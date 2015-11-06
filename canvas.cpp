#include "canvas.h"

#include <QDebug>
#include <QPainter>
#include <QColor>
#include <QMouseEvent>

Label::Label(Canvas *p):
    QLabel(p){
    parent = p;

}
Label::~Label(){

}
void Label::paintEvent(QPaintEvent *ev){
    QRect crct(ev->rect().topLeft()/scalefactor, ev->rect().bottomRight()/scalefactor);
    QImage cropped = image->copy(crct);
    QImage ocropped = overlay->copy(crct);
    QSize sz = cropped.size()*scalefactor;
    QImage i = cropped.scaled(sz);
    QImage o = ocropped.scaled(sz);
    painter.begin(this);
    painter.drawImage(ev->rect().topLeft(), i);
    painter.drawImage(ev->rect().topLeft(), o);
    painter.end();

}

void Label::setImages(QImage *i, QImage *o){
    image = i;
    overlay = o;
}
void Label::setScaleFactor(double f){
    QSize s = image->size()*f;
    resize(s);
    scalefactor = f;
}
void Label::mousePressEvent(QMouseEvent *ev){
    emit parent->mpEvent(ev);
}

void Label::mouseReleaseEvent(QMouseEvent *ev){
    emit parent->mrEvent(ev);
}
void Label::mouseMoveEvent(QMouseEvent *ev){
    emit parent->mmEvent(ev);

}
//==============================================================================================
Canvas::Canvas(QWidget *parent) :
    QScrollArea(parent){
    surface = new Label(this);
    this->setWidget(surface);
}

void Canvas::setImages(QImage *i, QImage *o){
    surface->setImages(i, o);
}
void Canvas::setScaleFactor(double f){
    surface->setScaleFactor(f);
}
void Canvas::update(){
    surface->update();
    QScrollArea::update();
}


