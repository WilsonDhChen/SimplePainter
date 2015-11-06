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
#ifndef SCONST_H
#define SCONST_H

#include <QBrush>
#include <QRect>
#include <QSize>

const int WSX1 = 2;
const int WSX2 = 30;
const int WSSPACE = 10;

const int START_WIDTH_ON = 3;
const int START_STYLE_ON = 0;

const int FILL_BUTTONS = 6;
const int FILL_COLUMNS = 2;
const QSize FILL_BUTTON_SIZE(30, 32);
const QSize FILL_ICON_SIZE(22, 22);
const QRect FILL_DRAW_RECT(2,2,18,18);
const QSize FILL_FRAME_SIZE(61, 101);

const Qt::BrushStyle FILL_STYLES[] = {Qt::NoBrush, Qt::SolidPattern, Qt::CrossPattern,
                                      Qt::DiagCrossPattern, Qt::Dense1Pattern, Qt::Dense6Pattern};

#endif // SCONST_H
