#include "colorpickerinternal.h"
#include "cpconst.h"

#include <QColor>
#include <QPixmap>
#include <QPainter>
#include <QRect>
#include <QFrame>
#include <QToolButton>
#include <QButtonGroup>
#include <QMouseEvent>
#include <QColorDialog>

#include <QDebug>



//========================================================================================================
ColorButton::ColorButton(QWidget *parent) :
    QToolButton(parent)
{
    pen.setColor(Qt::darkGray);
    pen.setWidth(HIGHLIGHT_WIDTH);
    pen.setJoinStyle(Qt::RoundJoin);

}
void ColorButton::setColor(QColor color){
    CurrentColor = color;
    QPixmap px(this->size()-QSize(4, 4));
    px.fill(color);
    setIcon(px);
    emit changed();

}
void ColorButton::paintEvent(QPaintEvent *e){
    QToolButton::paintEvent(e);
    if (this->isChecked()){
        QRect rct = this->rect();
        painter.begin(this);
        painter.setPen(pen);
        painter.drawRoundedRect(rct, HIGHLIGHT_RADIUS, HIGHLIGHT_RADIUS);
        painter.end();
    }

}
void ColorButton::mouseReleaseEvent ( QMouseEvent * event )
{
    if(event->button() == Qt::RightButton)
    {
        QColor color = QColorDialog::getColor(CurrentColor, this, "Select Color");
        if (color.isValid()) {
            setColor(color);

        }
     }
    else if (event->button() == Qt::LeftButton)
    {
        QToolButton::mouseReleaseEvent(event);
    }
}
//===================================================================================================
FBFrame::FBFrame(QWidget *parent, CPStyles style):
    QFrame(parent){


    //..............................................
    this->setObjectName(QStringLiteral("FBFrame"));
    //............................................
    swapButton = new QToolButton(this);
    swapButton->setObjectName(QStringLiteral("swapButton"));
    swapButton->setMaximumSize(SWAPBUTTON_SIZE);
    QIcon icon;
    icon.addFile(QStringLiteral(":/icons/icons/arrow-swap.png"), QSize(), QIcon::Normal, QIcon::Off);
    swapButton->setIcon(icon);

    //..............................................
    backgroundButton = new ColorButton(this);
    backgroundButton->setObjectName(QStringLiteral("backgroundButton"));
    backgroundButton->setMaximumSize(FBBUTTON_SIZE);
    backgroundButton->setCheckable(true);
    backgroundButton->setColor(Qt::white);

    //..............................................
    foregroundButton = new ColorButton(this);
    foregroundButton->setObjectName(QStringLiteral("foregroundButton"));
    foregroundButton->setMaximumSize(FBBUTTON_SIZE);
    foregroundButton->setCheckable(true);
    foregroundButton->setChecked(true);
    foregroundButton->setColor(Qt::black);



    //................................................
    buttons = new QButtonGroup(this);
    buttons->addButton(backgroundButton);
    buttons->addButton(foregroundButton);

    //............................................
    gridLayout = new QGridLayout(this);
    gridLayout->setSpacing(1);
    gridLayout->setObjectName(QStringLiteral("gridLayout"));
    gridLayout->setContentsMargins(7, 0, 0, 0);

    if ((style == minvertical)||(style == minhorizontal)){
        gridLayout->addWidget(foregroundButton, 0, 0, 1, 1);
        swapButton->hide();
        backgroundButton->hide();
    }
    else{
        gridLayout->addWidget(foregroundButton, 1, 1, 3, 2, Qt::AlignTop);
        gridLayout->addWidget(backgroundButton, 0, 0, 3, 2, Qt::AlignTop);
        gridLayout->addWidget(swapButton, 3, 0, 2, 1, Qt::AlignRight|Qt::AlignBottom);

        connect(swapButton, SIGNAL(released()),
                this, SLOT(swapButtonReleased()));

    }
}
void FBFrame::swapButtonReleased()
{
    QColor f = foregroundButton->CurrentColor;
    QColor b = backgroundButton->CurrentColor;

    foregroundButton->setColor(b);
    backgroundButton->setColor(f);

}
//==========================================================================================================
CFrame::CFrame(QWidget *parent, CPStyles style):
    QFrame(parent){

        //................................................
        this->setObjectName(QStringLiteral("CFrame"));
        this->setFrameShape(QFrame::StyledPanel);
        this->setLineWidth(1);

        //................................................
        int cbcount;
        if ((style == maxvertical)||(style == maxhorizontal)){
            cbcount = MAX_CBUTTONS;
        }
        else if ((style == vertical)||(style == horizontal)){
            cbcount = STD_CBUTTONS;
        }
        else{
            cbcount = MIN_CBUTTONS;
        }
        for (int i=0; i<cbcount; i++){
            ColorButton *cb = new ColorButton(this);
            cb->setMaximumSize(CBUTTON_SIZE);
            cb->setObjectName(QString("colButton").append(QString::number(i)));
            colButtons.push_back(cb);
        }

        //...................................................


        buttons = new QButtonGroup(this);
        gridLayout = new QGridLayout(this);
        gridLayout->setSpacing(2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);

        int columns;
        switch(style){
            case maxvertical:{
                columns = MAX_VERTICAL_COLUMNS;
                break;
            }
            case vertical:{
                columns = VERTICAL_COLUMNS;
                break;
            }
            case maxhorizontal:{
                columns = MAX_HORIZONTAL_COLUMNS;
                break;
            }
            case horizontal:{
                columns = HORIZONTAL_COLUMNS;
                break;
            }
            case minvertical:{
                columns = MIN_VERTICAL_COLUMNS;
                break;
            }
            case minhorizontal:{
                columns = MIN_HORIZONTAL_COLUMNS;
                break;
            }
        };
        int r = 0;
        int c = 0;
        for (ColorButton *cb : colButtons){
            gridLayout->addWidget(cb, r, c, 1, 1);
            buttons->addButton(cb);
            c++;
            if (c==columns){
                c = 0;
                r++;
            }
        }
}
void CFrame::setInitPal(const QColor pal[]){
    for(int i=0; i<colButtons.size(); i++){
        colButtons[i]->setColor(pal[i]);
    }

}
//==========================================================================================================
ColorPicker::ColorPicker(QWidget *parent, CPStyles style):
    QFrame(parent){

    fbframe = new FBFrame(this, style);
    cframe = new CFrame(this, style);
    int r = 1;
    int c = 0;
    if ((style == maxvertical)||(style == vertical)||(style == minvertical)){
            r = 0;
            c = 1;
    }

    layout = new QGridLayout(this);
    layout->setSpacing(0);
    layout->setObjectName(QStringLiteral("verticalLayout"));
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(cframe, 0, 0, 1, 1);
    layout->addWidget(fbframe, c, r, 1, 1);
    connect(cframe->buttons, SIGNAL(buttonReleased(QAbstractButton*)),
            this, SLOT(onColorSelected(QAbstractButton*)));
    connect(fbframe->foregroundButton, SIGNAL(changed()),
            this, SLOT(onChanged()));
    switch(style){
        case maxvertical:{
            cframe->setInitPal(MAX_INIT_PALLETTE);
            this->setFixedSize(MAX_VERTICAL_SIZE);
            break;
        }
        case vertical:{
            cframe->setInitPal(STD_INIT_PALLETTE);
            this->setFixedSize(VERTICAL_SIZE);
            break;
        }
        case maxhorizontal:{
            cframe->setInitPal(MAX_INIT_PALLETTE);
            this->setFixedSize(MAX_HORIZONTAL_SIZE);
            break;
        }
        case horizontal:{
            cframe->setInitPal(STD_INIT_PALLETTE);
            this->setFixedSize(HORIZONTAL_SIZE);
            break;
        }
        case minvertical:{
            cframe->setInitPal(MIN_INIT_PALLETTE);
            this->setFixedSize(MIN_VERTICAL_SIZE);
            break;
        }
        case minhorizontal:{
            cframe->setInitPal(MIN_INIT_PALLETTE);
            this->setFixedSize(MIN_HORIZONTAL_SIZE);
            break;
        }
    };


}

ColorPicker::~ColorPicker()
{
}

QColor ColorPicker::getSelected(){
    return fbframe->foregroundButton->CurrentColor;
}

QColor ColorPicker::getBackground(){
    return fbframe->backgroundButton->CurrentColor;

}
void ColorPicker::setActiveColor(QColor c){
    fbframe->foregroundButton->setColor(c);
}

void ColorPicker::onColorSelected(QAbstractButton *b)
{
    ColorButton * cbt = static_cast<ColorButton*>(b);
    ColorButton * fbbt = static_cast<ColorButton*>(fbframe->buttons->checkedButton());
    fbbt->setColor(cbt->CurrentColor);
}
void ColorPicker::onChanged(){
    emit changed();
}
