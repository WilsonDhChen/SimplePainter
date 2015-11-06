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
#ifndef COLORPICKERINTERNAL_H
#define COLORPICKERINTERNAL_H

#include <QToolButton>
#include <QPainter>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QMouseEvent>

#include <vector>

enum CPStyles{
    maxvertical,
    maxhorizontal,
    vertical,
    horizontal,
    minvertical,
    minhorizontal

};

//=============================================================================================
class ColorButton : public QToolButton
{
    Q_OBJECT
public:
    explicit ColorButton(QWidget *parent = 0);
    QColor CurrentColor;
    void setColor(QColor color);
signals:
    void changed();
protected:
    void paintEvent(QPaintEvent *e);
    QPainter painter;
    QPen pen;
protected slots:
    virtual void mouseReleaseEvent ( QMouseEvent * event );


};
//==================================================================================================
class FBFrame: public QFrame{
    Q_OBJECT
public:
    explicit FBFrame(QWidget *parent = 0, CPStyles style=vertical);
    QGridLayout *gridLayout;
    QToolButton *swapButton;
    ColorButton *foregroundButton;
    ColorButton *backgroundButton;
    QButtonGroup *buttons;
private slots:
    void swapButtonReleased();
};


//===================================================================================================
class CFrame: public QFrame{
    Q_OBJECT
public:
    explicit CFrame(QWidget *parent = 0, CPStyles style=vertical);
    QButtonGroup *buttons;
    QGridLayout *gridLayout;
    std::vector <ColorButton *> colButtons;
    void setInitPal(const QColor pal[]);
};

//===========================================================================================
class ColorPicker : public QFrame{
    Q_OBJECT
public:
    ColorPicker(QWidget *parent = 0, CPStyles style=maxhorizontal);
    ~ColorPicker();

    QColor getSelected();
    QColor getBackground();
    void setActiveColor(QColor c);
signals:
    void changed();
private slots:
    void onChanged();
    void onColorSelected(QAbstractButton *b);
protected:
    QGridLayout *layout;
    FBFrame *fbframe;
    CFrame *cframe;
private:
};



#endif // COLORPICKERINTERNAL_H
