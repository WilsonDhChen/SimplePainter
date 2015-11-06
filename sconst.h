#ifndef SCONST_H
#define SCONST_H

#include <QBrush>
#include <QRect>
#include <QSize>

const int WSX1 = 2;
const int WSX2 = 30;
const int WSSPACE = 10;

const int START_WIDTH_ON = 3;
const int START_STYLE_ON = 0;

const int FILL_BUTTONS = 6;
const int FILL_COLUMNS = 2;
const QSize FILL_BUTTON_SIZE(30, 32);
const QSize FILL_ICON_SIZE(22, 22);
const QRect FILL_DRAW_RECT(2,2,18,18);
const QSize FILL_FRAME_SIZE(61, 101);

const Qt::BrushStyle FILL_STYLES[] = {Qt::NoBrush, Qt::SolidPattern, Qt::CrossPattern,
                                      Qt::DiagCrossPattern, Qt::Dense1Pattern, Qt::Dense6Pattern};

#endif // SCONST_H
