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
#ifndef SELECTORS_H
#define SELECTORS_H

#include <QComboBox>
#include <QPainter>
#include <QToolButton>
#include <QButtonGroup>
#include <vector>
#include <QGridLayout>

#include "sconst.h"

//========================================================================================================
class LineSelector : public QComboBox{
    Q_OBJECT
public:
    explicit LineSelector(QWidget *parent = 0);
    ~LineSelector();

protected:
    QPainter painter;
    QPen pen;
    virtual void createIcons()=0;
};

//========================================================================================================
class StyleSelector : public LineSelector{
    Q_OBJECT
public:
    explicit StyleSelector(QWidget *parent = 0);
    ~StyleSelector();
    Qt::PenStyle getStyle();
protected:
    void createIcons();

};

//=========================================================================================================
class WidthSelector : public LineSelector{
    Q_OBJECT
public:
    explicit WidthSelector(QWidget *parent = 0);
    ~WidthSelector();
    int getWidth();

private:
    void createIcons();
};
//===========================================================================================================
class FillSelector : public QFrame{
    Q_OBJECT
public:
    explicit FillSelector(QWidget *parent = 0);
    ~FillSelector();
    Qt::BrushStyle getStyle();
private:
    void createIcons();
    QGridLayout *layout;
    std::vector<QToolButton*> buttons;
    QButtonGroup buttongroup;

};

#endif // SELECTORS_H
