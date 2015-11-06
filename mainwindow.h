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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "toolmodes.h"

#include "resourcehandler.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionDebug_info_triggered();

    void on_actionOpen_Image_triggered();

    void on_action_Save_triggered();

    void on_actionSave_as_triggered();

    void on_actionNew_Image_triggered();

    void on_actionZoom_In_triggered();

    void on_actionZoom_Out_triggered();

    void on_actionFit_To_Screen_triggered();


    void setMode(int id, bool checked);

    void startMode(QMouseEvent *ev);

    void moveMode(QMouseEvent *ev);

    void stopMode(QMouseEvent *ev);


    void createEditMenu(QPoint p);

    void on_actionDelete_triggered();

    void on_actionPaste_triggered();

    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_undoUpdated();

    void updateView();

    void updateView(QFont f);

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_SetColor(QColor c);

private:
    Ui::MainWindow *ui;
    ResourceHandler rsh;
    ToolMode * mode;
    TextDialog *tdialog;
    Modes modes;
    QString currentpath;


    void initializeResources();
    void setPen();
};


#endif // MAINWINDOW_H
