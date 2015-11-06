#include "clipboard.h"
#include <QMimeData>
#include <QApplication>

ClipBoard::ClipBoard()
{
    hasclip = false;
    QClipboard *sysclipboard = QApplication::clipboard();
}
ClipBoard::~ClipBoard(){

}
QImage ClipBoard::getClip(){
    return clip;
}
bool ClipBoard::sysHasClip(){
    return sysclipboard->mimeData()->hasImage();

}

void ClipBoard::setClip(QImage i){
    clip = i;
    hasclip = true;
}

QImage ClipBoard::getSysClip(){
    const QMimeData *mimeData = sysclipboard->mimeData();
    if (mimeData->hasImage()) {
        QImage i = qvariant_cast<QImage>(mimeData->imageData());
        return i;
    }
    else{
        return QImage();
    }
}

void ClipBoard::setSysClip(QImage i){
    sysclipboard->setImage(i);
}
