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
#ifndef CPCONST_H
#define CPCONST_H

#include <QSize>
#include <QColor>




const QSize FBBUTTON_SIZE(25, 30);
const QSize CBUTTON_SIZE(20, 25);
const QSize SWAPBUTTON_SIZE(22, 22);

const double HIGHLIGHT_RADIUS = 5.0;
const int HIGHLIGHT_WIDTH = 4;

const int MAX_CBUTTONS = 16;
const int STD_CBUTTONS = 10;
const int MIN_CBUTTONS = 6;


const int MAX_VERTICAL_COLUMNS = 2;
const int MAX_HORIZONTAL_COLUMNS = 8;
const int VERTICAL_COLUMNS = 2;
const int HORIZONTAL_COLUMNS = 5;
const int MIN_HORIZONTAL_COLUMNS = 6;
const int MIN_VERTICAL_COLUMNS = 1;


const QSize MAX_VERTICAL_SIZE(56,301);
const QSize MAX_HORIZONTAL_SIZE(295, 61);
const QSize VERTICAL_SIZE(56, 220);
const QSize HORIZONTAL_SIZE(205, 61);
const QSize MIN_HORIZONTAL_SIZE(221, 41);
const QSize MIN_VERTICAL_SIZE(31, 221);


const QColor MAX_INIT_PALLETTE[] = {Qt::black, Qt::white, Qt::gray, Qt::darkGray,Qt::green,
                                    Qt::darkGreen, Qt::blue, Qt::darkBlue, Qt::cyan, Qt::darkCyan,
                                    Qt::magenta, Qt::darkMagenta, Qt::yellow, Qt::darkYellow,
                                    Qt::red, Qt::darkRed};
const QColor STD_INIT_PALLETTE[] = {Qt::black, Qt::white, Qt::darkGray, Qt::lightGray, Qt::green, Qt::blue, Qt::cyan,
                                    Qt::magenta, Qt::yellow, Qt::red};
const QColor MIN_INIT_PALLETTE[] = {Qt::black, Qt::white, Qt::green, Qt::yellow, Qt::blue, Qt::red};

#endif // CPCONST_H
