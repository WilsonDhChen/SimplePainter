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
