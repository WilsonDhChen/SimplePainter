#ifndef CANVAS_H
#define CANVAS_H

#include <QLabel>

#include <QScrollArea>
#include <QPoint>
#include <QPainter>
#include <QColor>
#include <QImage>


class Canvas;

class Label : public QLabel{
     Q_OBJECT
public:
    Label(Canvas *p);
    ~Label();
    void setImages(QImage *i, QImage *o);
    void setScaleFactor(double f);
protected:
    void paintEvent(QPaintEvent *ev);
    QImage * image;
    QImage * overlay;
    QPainter painter;
    double scalefactor;
    Canvas * parent;
protected slots:
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);


};

//=========================================================================================
class Canvas : public QScrollArea
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = 0);
    void setImages(QImage *i, QImage *o);
    void setScaleFactor(double f);
    void update();
protected:
    Label * surface;
signals:
    void mpEvent(QMouseEvent * ev);
    void mmEvent(QMouseEvent * ev);
    void mrEvent(QMouseEvent * ev);
};

#endif // CANVAS_H
