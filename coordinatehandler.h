#ifndef COORDINATEHANDLER_H
#define COORDINATEHANDLER_H

#include <QPoint>
#include <QRect>

class CoordinateHandler
{
public:
    CoordinateHandler();
    QPoint currentpoint;
    QPoint lastpoint;
    QPoint startpoint;
    QPoint cptrans;
    QPoint lptrans;
    QPoint sptrans;
    QRect pasterect;
    QPoint pasteoffset;
    QPoint pastepoint;
    QSize pastesize;

    QRect getRect();
    void setCurrentPoint(QPoint p);
    void setStartPoint(QPoint p);
    void setPasteRect();
    void setPasteOffset();
    void setPastePoint();
    void setPasteSize(QSize s);
    void translate();
    void increaseZoom();
    void decreaseZoom();
    void resetZoom();
    double zoomFactor();
protected:
    int zoomIndex;
};

#endif // COORDINATEHANDLER_H
