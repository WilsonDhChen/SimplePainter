#ifndef IHCONST_H
#define IHCONST_H

#include <QPoint>
#include <QSize>
#include <QRect>
#include <QColor>

const QSize DEFAULT_SIZE(840, 560);

const QPoint WEST(-1, 0);
const QPoint EAST(1, 0);
const QPoint NORTH(0, -1);
const QPoint SOUTH(0, 1);

const QColor BAND_COLOR_1 = Qt::darkGray;
const QColor BAND_COLOR_2 = Qt::black;
const int BAND_WIDTH_1 = 2;
const int BAND_WIDTH_2 = 1;

const QRect HANDLE_RECT_1(-2 ,2, -5, 5);
const QRect HANDLE_RECT_2(0, 0, -10, 10);
const QColor HANDLE_COLOR_1 = Qt::lightGray;
const QColor HANDLE_COLOR_2 = Qt::black;
const int HANDLE_WIDTH_1 = 3;
const int HANDLE_WIDTH_2 = 2;

const int SPRAY_DENSITY = 8;
const int SPRAY_RADIUS = 10;

const QPoint TEXT_HANDLE_OFFSET(-10, 5);


#endif // IHCONST_H
