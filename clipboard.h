#ifndef CLIPBOARD_H
#define CLIPBOARD_H

#include <QImage>
#include <QClipboard>

class ClipBoard
{
public:
    ClipBoard();
    ~ClipBoard();
    bool hasclip;
    bool sysHasClip();

    QImage getClip();
    void setClip(QImage i);
    QImage getSysClip();
    void setSysClip(QImage i);
private:
    QImage clip;
    QClipboard *sysclipboard;
};

#endif // CLIPBOARD_H
