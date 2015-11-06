#ifndef TOOLBUCKET_H
#define TOOLBUCKET_H

#include <QFrame>
#include <QButtonGroup>

namespace Ui {
class ToolBucket;
}

class ToolBucket : public QFrame
{
    Q_OBJECT

public:
    explicit ToolBucket(QWidget *parent = 0);
    ~ToolBucket();
    int getSelected();
    QButtonGroup buttons;

private:
    Ui::ToolBucket *ui;


};

#endif // TOOLBUCKET_H
