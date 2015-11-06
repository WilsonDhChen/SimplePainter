#include "undohandler.h"
#include "spconst.h"

UndoHandler::UndoHandler(QObject *parent) : QObject(parent){

}
void UndoHandler::append(QImage i){

    undoImages.push_front(i);
    redoImages.clear();
    if (undoImages.size() > UNDO_LEVELS){
        undoImages.pop_back();
    }
    emit undoUpdated();
}

QImage UndoHandler::getUndo(QImage ci){
    QImage i = undoImages.front();
    undoImages.pop_front();
    redoImages.push_front(ci);
    emit undoUpdated();
    return i;

}
QImage UndoHandler::getRedo(QImage ci){
    QImage i = redoImages.front();
    redoImages.pop_front();
    undoImages.push_front(ci);
    emit undoUpdated();
    return i;
}
bool UndoHandler::undoPossible(){
    return !undoImages.empty();
}
bool UndoHandler::redoPossible(){
    return !redoImages.empty();
}
void UndoHandler::restart(){
    undoImages.clear();
    redoImages.clear();
    emit undoUpdated();
}
