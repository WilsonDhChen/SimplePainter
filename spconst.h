#ifndef SPCONST_H
#define SPCONST_H



#include <QSize>
#include <array>

const QSize DEFAULT_SIZE(840, 560);

const int UNDO_LEVELS = 5;

const std::array<double, 10 > SCALE_FACTORS = {0.25, 0.5, 0.75, 1.0, 1.25, 1.5, 2.0, 2.5, 3.0, 5.0};// must contain "1.0"

const QSize HANDLE_HITBOX(-10, 10);



#endif // SPCONST_H
