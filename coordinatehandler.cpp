#include "coordinatehandler.h"
#include "spconst.h"

#include <QPoint>
#include <algorithm>

CoordinateHandler::CoordinateHandler(): currentpoint(0,0),
    lastpoint(0,0),
    cptrans(0,0),
    lptrans(0,0),
    startpoint(0,0)
{
    resetZoom();
}



void CoordinateHandler::setCurrentPoint(QPoint p){
    lastpoint = currentpoint;
    currentpoint = p;
    translate();

}
void CoordinateHandler::setStartPoint(QPoint p){
    startpoint = p;
    setCurrentPoint(p);

}
QRect CoordinateHandler::getRect(){
    int x = sptrans.x();
    int y = sptrans.y();
    int xt = cptrans.x()-x;
    int yt = cptrans.y()-y;
    QRect r(x, y, xt, yt);
    return r;
}
void CoordinateHandler::setPasteOffset(){
    pasteoffset = cptrans - pasterect.topLeft();
}

void CoordinateHandler::setPasteRect(){

    pasterect = QRect(pastepoint, pastesize);

}
void CoordinateHandler::setPastePoint(){
    pastepoint = cptrans - pasteoffset;
}

void CoordinateHandler::setPasteSize(QSize s){
    pastesize = s;

}
void CoordinateHandler::translate(){
    cptrans = currentpoint/SCALE_FACTORS[zoomIndex];
    lptrans = lastpoint/SCALE_FACTORS[zoomIndex];
    sptrans = startpoint/SCALE_FACTORS[zoomIndex];
}

void CoordinateHandler::increaseZoom()
{
    if (zoomIndex <SCALE_FACTORS.size()-1){
        zoomIndex++ ;
        translate();
    }
}
void CoordinateHandler::decreaseZoom()
{
    if (zoomIndex > 0){
        zoomIndex-- ;
        translate();
    }
}
double CoordinateHandler::zoomFactor()
{
    return SCALE_FACTORS[zoomIndex];
}
void CoordinateHandler::resetZoom()
{
    zoomIndex = std::find(SCALE_FACTORS.begin(), SCALE_FACTORS.end(), 1.0) - SCALE_FACTORS.begin();
    translate();
}
