#include "toolbucket.h"
#include "ui_toolbucket.h"

#include <QButtonGroup>

ToolBucket::ToolBucket(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ToolBucket)
{
    ui->setupUi(this);
    Q_INIT_RESOURCE(icons);

    buttons.addButton(ui->toolButton, 0);
    buttons.addButton(ui->toolButton_1, 1);
    buttons.addButton(ui->toolButton_2, 2);
    buttons.addButton(ui->toolButton_3, 3);
    buttons.addButton(ui->toolButton_4, 4);
    buttons.addButton(ui->toolButton_5, 5);
    buttons.addButton(ui->toolButton_6, 6);
    buttons.addButton(ui->toolButton_7, 7);
    buttons.addButton(ui->toolButton_8, 8);
    buttons.addButton(ui->toolButton_9, 9);

}

ToolBucket::~ToolBucket()
{
    delete ui;
}

int ToolBucket::getSelected(){
    return buttons.checkedId();
}
