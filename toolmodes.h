#ifndef TOOLMODE_H
#define TOOLMODE_H

#include <QColor>
#include <QPoint>
#include <QRect>
#include <QRubberBand>

#include "imagehandler.h"
#include "coordinatehandler.h"
#include "clipboard.h"
#include "textdialog.h"
#include "resourcehandler.h"
#include "undohandler.h"

//-----------------------------------------------------------------------------------------
class ToolMode : public QObject{
    Q_OBJECT
public:
    ToolMode(ResourceHandler *rh, QObject *p=0);
    ToolMode(){}
    ~ToolMode();
    void setStyle(QColor color, QColor bcolor=Qt::white, int width=1, Qt::BrushStyle shapefill=Qt::NoBrush, Qt::PenStyle linestyle=Qt::SolidLine );
    virtual void start();
    virtual void move() =0;
    virtual void end() =0;
    virtual void clear();
    virtual void draw();
    virtual void clearSelection();
    virtual QImage getSelection();
    virtual void setBindings();
    
    virtual void clearBindings();

    bool hasselection = false;
    bool isfinished = false;
protected:
    ImageHandler * image;
    ImageHandler * overlay;
    CoordinateHandler * coords;
    ClipBoard * clipboard;
    UndoHandler * undohandler;
    int brushwidth;
    Qt::BrushStyle shapefill;
    Qt::PenStyle linestyle;
    QColor color;
    QColor bcolor;





};
//-----------------------------------------------------------------------------------------

class PencilMode : public ToolMode{
    Q_OBJECT
public:
    PencilMode(ResourceHandler *rh, QObject *p=0);
    PencilMode(){}
    void start();
    void move();
    void end();

};
//-----------------------------------------------------------------------------------------
class PenMode : public ToolMode{
    Q_OBJECT
public:
    PenMode(ResourceHandler *rh, QObject *p=0);
    PenMode(){}
    void start();
    void move();
    void end();

};
//-----------------------------------------------------------------------------------------
class BrushMode : public ToolMode{
    Q_OBJECT
public:
    BrushMode(ResourceHandler *rh, QObject *p=0);
    BrushMode(){}
    void start();
    void move();
    void end();
};
//-----------------------------------------------------------------------------------------
class EraserMode : public ToolMode{
    Q_OBJECT
public:
    EraserMode(ResourceHandler *rh, QObject *p=0);
    EraserMode(){}
    void start();
    void move();
    void end();
};
//-----------------------------------------------------------------------------------------
class FloodMode : public ToolMode{
    Q_OBJECT
public:
    FloodMode(ResourceHandler *rh, QObject *p=0);
    FloodMode(){}
    void start();
    void move();
    void end();

};
//-----------------------------------------------------------------------------------------
class LineMode : public ToolMode{
    Q_OBJECT
public:
    LineMode(ResourceHandler *rh, QObject *p=0);
    LineMode(){}
    void start();
    void move();
    void end();

};
//-----------------------------------------------------------------------------------------
class CircleMode : public ToolMode{
    Q_OBJECT
public:
    CircleMode(ResourceHandler *rh, QObject *p=0);
    CircleMode(){}
    void start();
    void move();
    void end();

};
//-----------------------------------------------------------------------------------------
class SquareMode : public ToolMode{
    Q_OBJECT
public:
    SquareMode(ResourceHandler *rh, QObject *p=0);
    SquareMode(){}
    void start();
    void move();
    void end();
};
//-----------------------------------------------------------------------------------------
class TextMode : public ToolMode{
    Q_OBJECT
public:
    TextMode(ResourceHandler *rh, QObject *p=0);
    TextMode(){}
    ~TextMode();
    void start();
    void move();
    void end();
    void draw();
    void clear();
    TextDialog *tdialog;


};
//-----------------------------------------------------------------------------------------
class SelectMode : public ToolMode{
    Q_OBJECT
public:
    SelectMode(ResourceHandler *rh, QObject *p=0);
    SelectMode(){}
    void start();
    void move();
    void end();
    void clear();
    void clearSelection();
    QImage getSelection();
};
//-----------------------------------------------------------------------------------------
class PasteMode : public ToolMode{
    Q_OBJECT
public:
    PasteMode(ResourceHandler *rh, QObject *p= 0);
    PasteMode(){}
    void start();
    void move();
    void end();
    void clear();
    void draw();
    void clearSelection();
    QImage getSelection();

};
//-----------------------------------------------------------------------------------------
class SprayMode : public ToolMode{
    Q_OBJECT
public:
    SprayMode(ResourceHandler *rh, QObject *p=0);
    SprayMode(){}
    void start();
    void move();
    void end();

};
//-----------------------------------------------------------------------------------------
class DropperMode : public ToolMode {
    Q_OBJECT
public:
    DropperMode(ResourceHandler *rh, QObject *p = 0);
    DropperMode(){}
    void start();
    void move();
    void end();
signals:
    void colorSet(QColor c);


};

//-----------------------------------------------------------------------------------------
class Modes{
public:
    Modes(ResourceHandler *rh, QObject *p=0);
    Modes(){}
    ~Modes();
    PencilMode *pencil;
    BrushMode *brush;
    DropperMode *dropper;
    SprayMode *spray;
    FloodMode *flood;
    LineMode *line;
    CircleMode *circle;
    SquareMode *square;
    TextMode *text;
    SelectMode *select;
    PasteMode *paste;
};

#endif // TOOLMODE_H
