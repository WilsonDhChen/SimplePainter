#include <QPainter>

#include "selectors.h"

LineSelector::LineSelector(QWidget *parent) :
    QComboBox(parent){

}
LineSelector::~LineSelector(){

}
//===================================================================================================
StyleSelector::StyleSelector(QWidget *parent) :
    LineSelector(parent){
    createIcons();
}
StyleSelector::~StyleSelector(){

}

void StyleSelector::createIcons(){
    int x = WSX1+WSX2;
    int y = WSSPACE*2;
    this->setIconSize(QSize(x, y));

    for(int i=1; i<5; i++){
        QPixmap px(x, y);
        px.fill(Qt::white);
        painter.begin(&px);
        pen.setWidth(2);
        pen.setStyle(static_cast<Qt::PenStyle>(i));
        pen.setColor(Qt::black);
        painter.setPen(pen);
        painter.drawLine(WSX1,WSSPACE,WSX2,WSSPACE);
        painter.end();
        this->addItem(px,"");
    };
    this->setCurrentIndex(START_STYLE_ON);
}

Qt::PenStyle StyleSelector::getStyle(){
    return static_cast<Qt::PenStyle>(this->currentIndex()+1);
}

//===========================================================================================
WidthSelector::WidthSelector(QWidget *parent) :
    LineSelector(parent){
    createIcons();
}
WidthSelector::~WidthSelector(){

}

void WidthSelector::createIcons(){
    int x = WSX1+WSX2;
    int y = WSSPACE*2;
    this->setIconSize(QSize(x, y));
    for(int i=1; i<10; i++){
        QPixmap px(x, y);
        px.fill(Qt::white);
        painter.begin(&px);
        pen.setWidth(i);
        pen.setColor(Qt::black);
        painter.setPen(pen);
        painter.drawLine(WSX1,WSSPACE,WSX2,WSSPACE);
        painter.end();
        this->addItem(px,"");
    };
    this->setCurrentIndex(START_WIDTH_ON);

}
int WidthSelector::getWidth(){
    return this->currentIndex()+1;
}

//====================================================================================================
FillSelector::FillSelector(QWidget *parent) :
    QFrame(parent){
    for (int i=0; i<FILL_BUTTONS; i++){
        QToolButton *tb = new QToolButton(this);
        tb->setMaximumSize(FILL_BUTTON_SIZE);
        tb->setObjectName(QString("fillButton").append(QString::number(i)));
        tb->setCheckable(true);
        buttongroup.addButton(tb);
        buttongroup.setId(tb, i);
        buttons.push_back(tb);
    }
    buttongroup.button(0)->setChecked(true);
    layout = new QGridLayout(this);
    layout->setSpacing(3);
    layout->setObjectName(QStringLiteral("fillLayout"));
    layout->setContentsMargins(1, 1, 1, 1);
    int r = 0;
    int c = 0;
    for (QToolButton *tb : buttons){
        layout->addWidget(tb, r, c, 1, 1);
        c++;
        if (c==FILL_COLUMNS){
            c = 0;
            r++;
        }
    }
    createIcons();
    //this->setFixedSize(FILL_FRAME_SIZE);

};

void FillSelector::createIcons(){
    QPainter painter;
    QPen pen(Qt::black);
    QBrush brush(Qt::red);
    for(int i=0; i<buttons.size(); i++){
        brush.setStyle(FILL_STYLES[i]);
        QPixmap px(FILL_ICON_SIZE);
        px.fill(Qt::white);
        painter.begin(&px);
        painter.setPen(pen);
        painter.setBrush(brush);
        painter.drawRect(FILL_DRAW_RECT);
        painter.end();
        buttons[i]->setIcon(px);
    };


}



FillSelector::~FillSelector()
{

}
Qt::BrushStyle FillSelector::getStyle(){
    int id = buttongroup.checkedId();
    return FILL_STYLES[id];

}
