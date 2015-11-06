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
#ifndef COLORPICKER_H
#define COLORPICKER_H

#include "colorpickerinternal.h"

namespace CP {

    class ColorPickerMinV:public ColorPicker{
        Q_OBJECT
    public:
        ColorPickerMinV(QWidget *parent):ColorPicker(parent, minvertical){};
    };

    class ColorPickerV:public ColorPicker{
        Q_OBJECT
    public:
        ColorPickerV(QWidget *parent):ColorPicker(parent, vertical){};

    };
    class ColorPickerMaxV:public ColorPicker{
        Q_OBJECT
    public:
        ColorPickerMaxV(QWidget *parent):ColorPicker(parent, maxvertical){};
    };

    class ColorPickerMinH:public ColorPicker{
        Q_OBJECT
    public:
        ColorPickerMinH(QWidget *parent):ColorPicker(parent, minhorizontal){};
    };

    class ColorPickerH:public ColorPicker{
        Q_OBJECT
    public:
        ColorPickerH(QWidget *parent):ColorPicker(parent, horizontal){};

    };
    class ColorPickerMaxH:public ColorPicker{
        Q_OBJECT
    public:
        ColorPickerMaxH(QWidget *parent):ColorPicker(parent, maxhorizontal){};
    };

}
#endif // COLORPICKER_H
