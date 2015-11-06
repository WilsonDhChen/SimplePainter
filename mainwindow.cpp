#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "spconst.h"


#include <QMouseEvent>
#include <QDebug>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    modes = Modes(&rsh, this);
    tdialog = new TextDialog(this);
    modes.text->tdialog = tdialog;
    connect(ui->renderArea, SIGNAL(mmEvent(QMouseEvent*)),
            this, SLOT(moveMode(QMouseEvent*)));
    connect (ui->renderArea, SIGNAL(mpEvent(QMouseEvent*)),
            this, SLOT(startMode(QMouseEvent*)));
    connect (ui->renderArea, SIGNAL(mrEvent(QMouseEvent*)),
            this, SLOT(stopMode(QMouseEvent*)));
    connect (ui->colorPicker, SIGNAL(changed()),
             this, SLOT(updateView()));
    connect (&ui->tools->buttons, SIGNAL(buttonToggled(int, bool)),
            this, SLOT(setMode(int, bool)));
    connect (tdialog, SIGNAL(fontChanged(QFont)),
             this, SLOT(updateView(QFont))),
    connect (tdialog, SIGNAL(textChanged()),
             this, SLOT(updateView()));
    connect (&rsh.undohandler, SIGNAL(undoUpdated()),
            this, SLOT(on_undoUpdated()));
    connect (modes.dropper, SIGNAL(colorSet(QColor)),
             this, SLOT(on_SetColor(QColor)));
    ui->renderArea->setImages(rsh.image.getImage(), rsh.overlay.getImage());
    mode = modes.pencil;
    rsh.overlay.clear(Qt::transparent);
    ui->renderArea->setScaleFactor(rsh.coords.zoomFactor());
    on_actionFit_To_Screen_triggered();
    on_undoUpdated();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete tdialog;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Do not remove, just take the action off the toolbar
void MainWindow::on_actionDebug_info_triggered()
{

}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void MainWindow::initializeResources(){
    rsh.overlay.clear(Qt::transparent);
}


void MainWindow::on_SetColor(QColor c){
    ui->colorPicker->setActiveColor(c);
}

void MainWindow::updateView(QFont f){
    rsh.image.setFont(f);
    setPen();
    mode->draw();
    ui->renderArea->update();
}
void MainWindow::updateView(){
    setPen();
    mode->draw();
    ui->renderArea->update();
}
//-------------------------------------------------------------------------------------------------------
void MainWindow::on_actionOpen_Image_triggered()
{
    QString path = QFileDialog::getOpenFileName(this,
                                                tr("choose location"),
                                                tr(""),
                                                tr("png Files (*.png);;jpg Files (*.jpg);;All Files (*)"));
    if (!path.isEmpty()){
         currentpath = path;
         rsh.image.open(currentpath);
         rsh.overlay.createNew(rsh.image.getSize());
         rsh.overlay.clear(Qt::transparent);
         on_actionFit_To_Screen_triggered();
         rsh.undohandler.restart();
         ui->renderArea->update();
    }

}
void MainWindow::on_actionSave_as_triggered()
{
    QString path = QFileDialog::getSaveFileName(this,
                                                tr("choose location"),
                                                tr(""),
                                                tr("png Files (*.png);;jpg Files (*.jpg);;All Files (*)"));
    currentpath = path;
    rsh.image.save(currentpath);


}
void MainWindow::on_action_Save_triggered()
{
    if (currentpath.isEmpty()){
        on_actionSave_as_triggered();
    }
    else{
         rsh.image.save(currentpath);
    }
}




void MainWindow::on_actionNew_Image_triggered()
{
    currentpath.clear();
    rsh.image.createNew(DEFAULT_SIZE);
    rsh.overlay.createNew(rsh.image.getSize());
    rsh.overlay.clear(Qt::transparent);
    on_actionFit_To_Screen_triggered();
    rsh.undohandler.restart();
    ui->renderArea->update();



}
//----------------------------------------------------------------------------------------------
void MainWindow::on_actionZoom_In_triggered(){
    rsh.coords.increaseZoom();
    ui->renderArea->setScaleFactor(rsh.coords.zoomFactor());
    ui->renderArea->update();
}

void MainWindow::on_actionZoom_Out_triggered(){
    rsh.coords.decreaseZoom();
    ui->renderArea->setScaleFactor(rsh.coords.zoomFactor());
    ui->renderArea->update();

}

void MainWindow::on_actionFit_To_Screen_triggered(){   
    rsh.coords.resetZoom();
    ui->renderArea->setScaleFactor(rsh.coords.zoomFactor());
    ui->renderArea->update();

}


//---------------------------------------------------------------------------------------------
void MainWindow::on_actionDelete_triggered()
{
    if (mode->hasselection){
        mode->clearSelection();
        mode->clear();
        ui->renderArea->update();
    }
}

void MainWindow::on_actionPaste_triggered()
{
    rsh.coords.pastepoint = rsh.coords.cptrans;
    mode->clear();
    mode = modes.paste;
    mode->draw();
    ui->renderArea->update();

}

void MainWindow::on_actionCopy_triggered()
{
    if (mode->hasselection){
        QImage i = mode->getSelection();
        rsh.clipboard.setClip(i);
    }
}

void MainWindow::on_actionCut_triggered()
{
    if (mode->hasselection){
        QImage i = mode->getSelection();
        rsh.clipboard.setClip(i);
        mode->clearSelection();
        mode->clear();
        ui->renderArea->update();
    }
}
//----------------------------------------------------------------------------------------------
void MainWindow::createEditMenu(QPoint p){
    ui->actionCopy->setEnabled(mode->hasselection);
    ui->actionCut->setEnabled(mode->hasselection);
    ui->actionDelete->setEnabled(mode->hasselection);
    ui->actionPaste->setEnabled(rsh.clipboard.hasclip);
    QMenu menu(this);
    menu.addAction(ui->actionCut);
    menu.addAction(ui->actionCopy);
    menu.addAction(ui->actionPaste);
    menu.addAction(ui->actionDelete);
    menu.exec(p);
}

//---------------------------------------------------------------------------------------------
void MainWindow::on_actionUndo_triggered(){
    QImage i = rsh.undohandler.getUndo(*rsh.image.getImage());
    if (!i.isNull()){
        rsh.image.setImage(i);
        ui->renderArea->update();
    }
}

void MainWindow::on_actionRedo_triggered()
{
    QImage i = rsh.undohandler.getRedo(*rsh.image.getImage());
    rsh.image.setImage(i);
    ui->renderArea->update();
}
void MainWindow::on_undoUpdated(){
    ui->actionRedo->setEnabled(rsh.undohandler.redoPossible());
    ui->actionUndo->setEnabled(rsh.undohandler.undoPossible());
}

//----------------------------------------------------------------------------------------



void MainWindow::setMode(int id, bool checked){
    if (checked){
        mode->clear();
        ui->renderArea->update();
        switch (id) {
            case 0:
            {
                mode = modes.pencil;
                break;
            };
            case 1:
            {
                mode = modes.brush;
                break;
            };
            case 2:
            {
                mode = modes.dropper;
                break;
            };
            case 3:
            {
                mode = modes.spray;
                break;
            };
            case 4:
            {
                mode = modes.flood;
                break;
            };
            case 5:
            {
                mode = modes.line;
                break;
            };
            case 6:
            {
                mode = modes.circle;
                break;
            };
            case 7:
            {
                mode = modes.square;
                break;
            };
            case 8:
            {
                mode = modes.text;

                break;
            };
            case 9:
            {
                mode = modes.select;
                break;
            };
            default:
            {
                break;
            };
        }

    }
}
void MainWindow::setPen(){
    QColor cc = ui->colorPicker->getSelected();
    QColor bc = ui->colorPicker->getBackground();
    int bw = ui->widthselector->getWidth();
    Qt::BrushStyle f = ui->fillselector->getStyle();
    Qt::PenStyle ls = ui->styleselector->getStyle();
    mode->setStyle(cc, bc, bw, f, ls);
}
//---------------------------------------------------------------------------------------------
void MainWindow::startMode(QMouseEvent *ev){
    if (mode->isfinished){
        mode->clear();
        int md = ui->tools->getSelected();
        setMode(md, true);
    }

    if (ev->button() == Qt::LeftButton){
        rsh.coords.setStartPoint(ev->pos());
        setPen();
        mode->start();
        ui->renderArea->update();

    }
    else if(ev->button() == Qt::RightButton){
        createEditMenu(ev->globalPos());

    }
    else if(ev->button() == Qt::MiddleButton){
        setPen();
        rsh.coords.setCurrentPoint(ev->pos());
        mode->start();
        ui->renderArea->update();
    }
}
void MainWindow::moveMode(QMouseEvent *ev){
    rsh.coords.setCurrentPoint(ev->pos());
    mode->move();
    ui->renderArea->update();
}
void MainWindow::stopMode(QMouseEvent *ev){
    if (ev->button() == Qt::LeftButton){
        rsh.coords.setCurrentPoint(ev->pos());
        mode->end();
        ui->renderArea->update();
    }
    else if(ev->button() == Qt::MiddleButton){
        rsh.coords.setCurrentPoint(ev->pos());
        mode->end();
        ui->renderArea->update();
    }
}
