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
#ifndef IHCONST_H
#define IHCONST_H

#include <QPoint>
#include <QSize>
#include <QRect>
#include <QColor>

const QSize DEFAULT_SIZE(840, 560);

const QPoint WEST(-1, 0);
const QPoint EAST(1, 0);
const QPoint NORTH(0, -1);
const QPoint SOUTH(0, 1);

const QColor BAND_COLOR_1 = Qt::darkGray;
const QColor BAND_COLOR_2 = Qt::black;
const int BAND_WIDTH_1 = 2;
const int BAND_WIDTH_2 = 1;

const QRect HANDLE_RECT_1(-2 ,2, -5, 5);
const QRect HANDLE_RECT_2(0, 0, -10, 10);
const QColor HANDLE_COLOR_1 = Qt::lightGray;
const QColor HANDLE_COLOR_2 = Qt::black;
const int HANDLE_WIDTH_1 = 3;
const int HANDLE_WIDTH_2 = 2;

const int SPRAY_DENSITY = 8;
const int SPRAY_RADIUS = 10;

const QPoint TEXT_HANDLE_OFFSET(-10, 5);


#endif // IHCONST_H
