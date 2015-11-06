#ifndef TEXTDIALOG_H
#define TEXTDIALOG_H

#include <QDialog>

namespace Ui {
class TextDialog;
}

class TextDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TextDialog(QWidget *parent = 0);
    ~TextDialog();
    QFont getSelectedFont();
    QString getText();


private slots:
    void onSettingsChange(int arg);
    void onSettingsChange(bool arg);
    void onSettingsChange(QFont f);


    void on_lineEdit_textChanged(const QString &arg1);

signals:
    void textChanged();
    void fontChanged(QFont f);
private:
    Ui::TextDialog *ui;
};

#endif // TEXTDIALOG_H
