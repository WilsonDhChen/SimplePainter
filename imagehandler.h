/*

this source code is part of Simple Painter, a classic Paint program Written in c++11/Qt5
Copyright (C) <2015>  <Justin D Neal>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
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
