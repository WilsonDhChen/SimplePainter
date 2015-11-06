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
#ifndef COORDINATEHANDLER_H
#define COORDINATEHANDLER_H

#include <QPoint>
#include <QRect>

class CoordinateHandler
{
public:
    CoordinateHandler();
    QPoint currentpoint;
    QPoint lastpoint;
    QPoint startpoint;
    QPoint cptrans;
    QPoint lptrans;
    QPoint sptrans;
    QRect pasterect;
    QPoint pasteoffset;
    QPoint pastepoint;
    QSize pastesize;

    QRect getRect();
    void setCurrentPoint(QPoint p);
    void setStartPoint(QPoint p);
    void setPasteRect();
    void setPasteOffset();
    void setPastePoint();
    void setPasteSize(QSize s);
    void translate();
    void increaseZoom();
    void decreaseZoom();
    void resetZoom();
    double zoomFactor();
protected:
    int zoomIndex;
};

#endif // COORDINATEHANDLER_H
