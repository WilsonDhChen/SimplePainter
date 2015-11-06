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
