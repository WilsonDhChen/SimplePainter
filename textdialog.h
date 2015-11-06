/*

this source code is part of Simple Painter, a classic Paint program Written in c++11/Qt5
Copyright (C) <2015>  <Justin D Neal>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
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
