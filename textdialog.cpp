#include "textdialog.h"
#include "ui_textdialog.h"

#include <QDebug>

TextDialog::TextDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TextDialog)
{
    ui->setupUi(this);

    connect(ui->boldBox, SIGNAL(toggled(bool)), this, SLOT(onSettingsChange(bool)));
    connect(ui->italicsBox, SIGNAL(toggled(bool)), this, SLOT(onSettingsChange(bool)));
    connect(ui->underlineBox, SIGNAL(toggled(bool)), this, SLOT(onSettingsChange(bool)));
    connect(ui->overlineBox, SIGNAL(toggled(bool)), this, SLOT(onSettingsChange(bool)));
    connect(ui->strikeBox, SIGNAL(toggled(bool)), this, SLOT(onSettingsChange(bool)));
    connect(ui->fontComboBox, SIGNAL(currentFontChanged(QFont)), this, SLOT(onSettingsChange(QFont)));
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(onSettingsChange(int)));
    this->setWindowFlags(this->windowFlags()|Qt::WindowStaysOnTopHint);

}

TextDialog::~TextDialog()
{
    delete ui;
}
QFont TextDialog::getSelectedFont(){
    QFont f = ui->fontComboBox->currentFont();
    f.setPointSize(ui->spinBox->value());
    f.setBold(ui->boldBox->isChecked());
    f.setItalic(ui->italicsBox->isChecked());
    f.setUnderline(ui->underlineBox->isChecked());
    f.setStrikeOut(ui->strikeBox->isChecked());
    f.setOverline(ui->overlineBox->isChecked());
    return f;
}
QString TextDialog::getText(){
    return ui->lineEdit->text();
}
void TextDialog::onSettingsChange(QFont f){
    emit fontChanged(f);
}
void TextDialog::onSettingsChange(int arg){
    emit fontChanged(getSelectedFont());
}
void TextDialog::onSettingsChange(bool arg){
    emit fontChanged(getSelectedFont());
}

void TextDialog::on_lineEdit_textChanged(const QString &arg1){
    emit textChanged();
}
