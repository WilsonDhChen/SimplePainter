#ifndef UNDOHANDLER_H
#define UNDOHANDLER_H

#include <deque>
#include <QImage>

class UndoHandler:public QObject
{
    Q_OBJECT
public:
    UndoHandler(QObject *parent = 0);
    void append(QImage i);
    QImage getUndo(QImage ci);
    QImage getRedo(QImage ci);
    void restart();
    bool redoPossible();
    bool undoPossible();
signals:
    void undoUpdated();
protected:
    std::deque<QImage> undoImages;
    std::deque<QImage> redoImages;
};

#endif // UNDOHANDLER_H
