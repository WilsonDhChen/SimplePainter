#ifndef IMAGEHANDLER_H
#define IMAGEHANDLER_H

#include <QPainter>
#include <QPen>
#include <QSize>
#include <QBrush>
#include <QImage>
#include <random>

class ImageHandler
{
public:
    ImageHandler();
    ~ImageHandler();

    void save(QString path);
    void open(QString path);
    void createNew(QSize s);
    void setImage(QImage i);
    QImage *getImage();

    QImage copy(QRect r);
    void del(QRect r, QColor bc);
    void paste(QImage i, QPoint p);
    QImage getCut(QPoint cp, QPoint lp);

    QSize getSize();
    QColor getPixel(QPoint p);
    void scale(double factor);
    void clear(QColor c=Qt::white);

    void drawBand(QRect r);
    void drawHandle(QPoint p);


    void setDrawStyle(QColor color, QColor bcolor, int width, Qt::BrushStyle shapefill, Qt::PenStyle linestyle);
    void setBandStyle();
    void setHandleStyle();
    void setFont(QFont f);

    void drawPoint(QPoint p);
    void drawLine(QPoint cp, QPoint lp);
    void drawCircle(QRect r);
    void drawSquare(QRect r);
    void drawText(QPoint p, QString s);
    void drawSpray(QPoint p);
    void fill(QPoint p, QColor color);

protected:
    QPen pen;
    QPen pentwo;
    QBrush brush;
    QPainter painter;
    QImage data;
    QFont font;
    std::default_random_engine re;
    std::uniform_real_distribution<double> unif;
};


#endif // IMAGEHANDLER_H
