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
