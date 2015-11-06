#include "toolmodes.h"
#include "clipboard.h"
#include "spconst.h"

#include <QDebug>
#include <QRect>
#include <cstdlib>
#include <math.h>


ToolMode::ToolMode(ResourceHandler *rh, QObject *p) : QObject(p){
    image = &rh->image;
    overlay = &rh->overlay;
    coords = &rh->coords;
    clipboard = &rh->clipboard;
    undohandler = &rh->undohandler;

}
ToolMode::~ToolMode()
{
}


void ToolMode::setStyle(QColor color, QColor bcolor, int width, Qt::BrushStyle shapefill, Qt::PenStyle linestyle){
    this->color = color;
    this->bcolor = bcolor;
    this->brushwidth = width;
    this->shapefill = shapefill;
    this->linestyle = linestyle;

}
void ToolMode::start(){
    image->setDrawStyle(color, bcolor, brushwidth, shapefill, linestyle);
}
void ToolMode::clear(){

}
void ToolMode::draw(){

}
void ToolMode::clearSelection(){

}
QImage ToolMode::getSelection(){
    return QImage();
}
void ToolMode::setBindings(){
    
}
void ToolMode::clearBindings(){
    
}

//=============================================================================================
PencilMode::PencilMode(ResourceHandler *rh, QObject *p) : ToolMode(rh, p){

}

void PencilMode::start(){
    undohandler->append(*image->getImage());
    image->setDrawStyle(color, bcolor, brushwidth, shapefill, linestyle);
    image->drawPoint(coords->cptrans);
}

void PencilMode::move(){
    image->drawPoint(coords->cptrans);

}
void PencilMode::end(){
    image->drawPoint(coords->cptrans);
}
//=====================================================================================================
BrushMode::BrushMode(ResourceHandler *rh, QObject *p) : ToolMode(rh, p){

};
void BrushMode::start(){
    undohandler->append(*image->getImage());
    image->setDrawStyle(color, bcolor, brushwidth, shapefill, linestyle);
}

void BrushMode::move(){
    image->drawLine(coords->cptrans, coords->lptrans);
}
void BrushMode::end(){
    image->drawLine(coords->cptrans, coords->lptrans);
}

//=============================================================================================

DropperMode::DropperMode(ResourceHandler *rh, QObject *p):ToolMode(rh, p){

}
void DropperMode::start(){
    QColor c = image->getPixel(coords->cptrans);
    emit colorSet(c);

}
void DropperMode::move(){

}
void DropperMode::end(){

}


//=============================================================================================

SprayMode::SprayMode(ResourceHandler *rh, QObject *p) : ToolMode(rh, p){
}

void SprayMode::start(){
    undohandler->append(*image->getImage());
    image->setDrawStyle(color, bcolor, brushwidth, shapefill, linestyle);
    image->drawSpray(coords->cptrans);
}

void SprayMode::move(){
    image->drawSpray(coords->cptrans);

}
void SprayMode::end(){
    image->drawSpray(coords->cptrans);
}


//=============================================================================================
PenMode::PenMode(ResourceHandler *rh, QObject *p) : ToolMode(rh, p){
};
void PenMode::start(){

    undohandler->append(*image->getImage());
    image->setDrawStyle(color, bcolor, brushwidth, shapefill, linestyle);
}

void PenMode::move(){

    image->drawLine(coords->cptrans, coords->lptrans);
}
void PenMode::end(){
    image->drawLine(coords->cptrans, coords->lptrans);
}
//=============================================================================================
EraserMode::EraserMode(ResourceHandler *rh, QObject *p) : ToolMode(rh, p){

};
void EraserMode::start(){
    undohandler->append(*image->getImage());
    image->setDrawStyle(color, bcolor, brushwidth, shapefill, linestyle);
}

void EraserMode::move(){
    image->drawLine(coords->cptrans, coords->lptrans);

}
void EraserMode::end(){
    image->drawLine(coords->cptrans, coords->lptrans);
}

//=============================================================================================
FloodMode::FloodMode(ResourceHandler *rh, QObject *p) : ToolMode(rh, p){

};

void FloodMode::start(){
    undohandler->append(*image->getImage());
    image->fill(coords->cptrans, color);
}

void FloodMode::move(){

}
void FloodMode::end(){
}

//=============================================================================================
LineMode::LineMode(ResourceHandler *rh, QObject *p) : ToolMode(rh, p){

};
void LineMode::start(){

    overlay->setDrawStyle(color, bcolor, brushwidth, shapefill, linestyle);
    overlay->clear(Qt::transparent);
    overlay->drawLine(coords->sptrans, coords->cptrans);
}

void LineMode::move(){
    overlay->clear(Qt::transparent);
    overlay->drawLine(coords->sptrans, coords->lptrans);

}
void LineMode::end(){
    overlay->clear(Qt::transparent);
    undohandler->append(*image->getImage());
    image->setDrawStyle(color, bcolor, brushwidth, shapefill, linestyle);
    image->drawLine(coords->sptrans, coords->lptrans);
}


//=============================================================================================
CircleMode::CircleMode(ResourceHandler *rh, QObject *p) : ToolMode(rh, p){

}


void CircleMode::start(){
    overlay->setDrawStyle(color, bcolor, brushwidth, shapefill, linestyle);
    QRect rect = coords->getRect();
    overlay->drawCircle(rect);
}

void CircleMode::move(){
    overlay->clear(Qt::transparent);
    QRect rect = coords->getRect();
    overlay->drawCircle(rect);
}
void CircleMode::end(){
    overlay->clear(Qt::transparent);
    undohandler->append(*image->getImage());
    image->setDrawStyle(color, bcolor, brushwidth, shapefill, linestyle);
    QRect rect = coords->getRect();
    image->drawCircle(rect);
}


//=============================================================================================
SquareMode::SquareMode(ResourceHandler *rh, QObject *p) : ToolMode(rh, p){

};
void SquareMode::start(){
    overlay->setDrawStyle(color, bcolor, brushwidth, shapefill, linestyle);
}

void SquareMode::move(){
    overlay->clear(Qt::transparent);
    QRect rect = coords->getRect();
    overlay->drawSquare(rect);
}
void SquareMode::end(){
    overlay->clear(Qt::transparent);
    undohandler->append(*image->getImage());
    image->setDrawStyle(color, bcolor, brushwidth, shapefill, linestyle);
    QRect rect = coords->getRect();
    image->drawSquare(rect);
}


//=============================================================================================
TextMode::TextMode(ResourceHandler *rh, QObject *p) : ToolMode(rh, p){
};
TextMode::~TextMode(){
};
void TextMode::start(){
    if (!hasselection){
        tdialog->show();
        coords->pastepoint = coords->cptrans;
        coords->setPasteSize(HANDLE_HITBOX);
        coords->setPasteRect();
        hasselection = true;
        draw();

    }
    else if (coords->pasterect.contains(coords->cptrans)){
        coords->setPasteOffset();
        coords->setPastePoint();
        coords->setPasteRect();
        draw();
    }
    else{
        overlay->clear(Qt::transparent);
        undohandler->append(*image->getImage());
        image->setDrawStyle(color, bcolor, brushwidth, shapefill, linestyle);
        image->setFont(tdialog->getSelectedFont());
        image->drawText(coords->pastepoint, tdialog->getText());
        hasselection = false;
    }

}

void TextMode::move(){
    if (hasselection){
        coords->setPastePoint();
        coords->setPasteRect();
        draw();
    }
}
void TextMode::end(){
    if (hasselection){
        coords->setPastePoint();
        coords->setPasteRect();
        draw();
    }
}

void TextMode::draw(){
    overlay->clear(Qt::transparent);
    overlay->setHandleStyle();
    overlay->drawHandle(coords->pastepoint);
    overlay->setDrawStyle(color, bcolor, brushwidth, shapefill, linestyle);
    overlay->setFont(tdialog->getSelectedFont());
    //qDebug() << tdialog->getSelectedFont();
    overlay->drawText(coords->pastepoint, tdialog->getText());
}
void TextMode::clear(){
    tdialog->hide();
    overlay->clear(Qt::transparent);

}
//=============================================================================================
SelectMode::SelectMode(ResourceHandler *rh, QObject *p) : ToolMode(rh, p){

};
void SelectMode::start(){
    overlay->setBandStyle();
    overlay->drawBand(coords->getRect());
}
void SelectMode::move(){
    overlay->clear(Qt::transparent);
    overlay->drawBand(coords->getRect());

}
void SelectMode::end(){
    overlay->clear(Qt::transparent);
    if (coords->getRect().bottomRight().isNull()){
        hasselection = false;
    }
    else{
        overlay->drawBand(coords->getRect());
        hasselection = true;
    }
}

void SelectMode::clear(){
    overlay->clear(Qt::transparent);
    hasselection = false;
}
void SelectMode::clearSelection(){
    undohandler->append(*image->getImage());
    image->del(coords->getRect(), bcolor);

}
QImage SelectMode::getSelection(){
    return image->copy(coords->getRect());
}

//=============================================================================================
// This is a transient mode, no button exists in the toolbox.
// It's use cycle ends when the selection is anchored or cleared

PasteMode::PasteMode(ResourceHandler *rh, QObject*p) : ToolMode(rh, p){

};

void PasteMode::start(){
    coords->setPasteRect();
    if (coords->pasterect.contains(coords->cptrans)){
        hasselection = true;
        coords->setPasteOffset();
        overlay->setBandStyle();
        overlay->paste(clipboard->getClip(), coords->pastepoint);
        overlay->drawBand(coords->pasterect);
    }
    else if(!isfinished){

        overlay->clear(Qt::transparent);
        undohandler->append(*image->getImage());
        image->paste(clipboard->getClip(), coords->pastepoint);
        hasselection = false;
        isfinished = true;
        }
}

void PasteMode::move(){
    if (!isfinished){
        coords->setPastePoint();
        coords->setPasteRect();

        overlay->clear(Qt::transparent);
        overlay->setBandStyle();
        overlay->paste(clipboard->getClip(), coords->pastepoint);
        overlay->drawBand(coords->pasterect);
        hasselection = true;
   }


}
void PasteMode::end(){
    if (!isfinished){
        coords->setPastePoint();
        coords->setPasteRect();
        overlay->clear(Qt::transparent);
        overlay->setBandStyle();
        overlay->paste(clipboard->getClip(), coords->pastepoint);
        overlay->drawBand(coords->pasterect);
        hasselection = true;
   }
}
void PasteMode::clear(){
    overlay->clear(Qt::transparent);
    hasselection = false;
    isfinished = false;
}
void PasteMode::draw(){
    if (!isfinished){
        coords->setPasteSize(clipboard->getClip().size());
        coords->pastepoint = coords->sptrans;
        coords->setPasteRect();
        overlay->setBandStyle();
        overlay->paste(clipboard->getClip(), coords->pastepoint);
        overlay->drawBand(coords->pasterect);
        hasselection = true;
    };
}
void PasteMode::clearSelection(){
    hasselection = false;
    isfinished = true;
    overlay->clear(Qt::transparent);
}
QImage PasteMode::getSelection(){
    return clipboard->getClip();
}

//=============================================================================================
Modes::Modes(ResourceHandler *rh, QObject *p){
    pencil = new PencilMode(rh, p);
    brush = new BrushMode(rh, p);
    dropper = new DropperMode(rh, p);
    spray = new SprayMode(rh, p);
    flood = new FloodMode(rh, p);
    line = new LineMode(rh, p);
    circle = new CircleMode(rh, p);
    square = new SquareMode(rh, p);
    text = new TextMode(rh, p);
    select = new SelectMode(rh, p);
    paste = new PasteMode(rh, p);
}

Modes::~Modes(){

}
