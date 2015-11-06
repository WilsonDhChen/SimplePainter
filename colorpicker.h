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
