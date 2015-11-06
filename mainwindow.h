#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "toolmodes.h"

#include "resourcehandler.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionDebug_info_triggered();

    void on_actionOpen_Image_triggered();

    void on_action_Save_triggered();

    void on_actionSave_as_triggered();

    void on_actionNew_Image_triggered();

    void on_actionZoom_In_triggered();

    void on_actionZoom_Out_triggered();

    void on_actionFit_To_Screen_triggered();


    void setMode(int id, bool checked);

    void startMode(QMouseEvent *ev);

    void moveMode(QMouseEvent *ev);

    void stopMode(QMouseEvent *ev);


    void createEditMenu(QPoint p);

    void on_actionDelete_triggered();

    void on_actionPaste_triggered();

    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_undoUpdated();

    void updateView();

    void updateView(QFont f);

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_SetColor(QColor c);

private:
    Ui::MainWindow *ui;
    ResourceHandler rsh;
    ToolMode * mode;
    TextDialog *tdialog;
    Modes modes;
    QString currentpath;


    void initializeResources();
    void setPen();
};


#endif // MAINWINDOW_H
