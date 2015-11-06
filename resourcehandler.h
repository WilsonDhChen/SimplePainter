#ifndef RESOURCEHANDLER_H
#define RESOURCEHANDLER_H

#include "imagehandler.h"
#include "coordinatehandler.h"
#include "clipboard.h"
#include "undohandler.h"


struct ResourceHandler{
    ClipBoard  clipboard;
    ImageHandler image;
    ImageHandler overlay;
    CoordinateHandler coords;
    UndoHandler undohandler;

};

#endif // RESOURCEHANDLER_H
