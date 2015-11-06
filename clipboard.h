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
#ifndef CLIPBOARD_H
#define CLIPBOARD_H

#include <QImage>
#include <QClipboard>

class ClipBoard
{
public:
    ClipBoard();
    ~ClipBoard();
    bool hasclip;
    bool sysHasClip();

    QImage getClip();
    void setClip(QImage i);
    QImage getSysClip();
    void setSysClip(QImage i);
private:
    QImage clip;
    QClipboard *sysclipboard;
};

#endif // CLIPBOARD_H
