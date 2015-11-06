#include "imagehandler.h"
#include "ihconst.h"

#include <QPainter>
#include <QPen>
#include <QColor>
#include <QDebug>
#include <queue>
#include <math.h>



//-------------------------------------------------------------------------------------------------------
ImageHandler::ImageHandler(){
    QImage img(DEFAULT_SIZE, QImage::Format_ARGB32_Premultiplied);
    data = img;
    data.fill(Qt::white);
    unif = std::uniform_real_distribution<double>(0, 1);
}
ImageHandler::~ImageHandler(){

}
//-------------------------------------------------------------------------------------------------------
void ImageHandler::save(QString path){
    data.save(path);

}
void ImageHandler::open(QString path){
    data.load(path);

}
void ImageHandler::createNew(QSize s){
    QImage img(s, QImage::Format_ARGB32_Premultiplied);
    data = img;
    data.fill(Qt::white);
}
void ImageHandler::setImage(QImage i){
    data = i;
}
QImage *ImageHandler::getImage(){
    return &data;
}
void ImageHandler::clear(QColor c){
    data.fill(c);
}
QSize ImageHandler::getSize(){
    return data.size();
}
QColor ImageHandler::getPixel(QPoint p){
    QColor c(data.pixel(p));
    return c;
}

//-----------------------------------------------------------------------------------
QImage ImageHandler::copy(QRect r){
    return data.copy(r);
}
void ImageHandler::del(QRect r, QColor bc){
    painter.begin(&data);
    painter.fillRect(r, bc);
    painter.end();
}
void ImageHandler::paste(QImage i, QPoint p){
    painter.begin(&data);
    painter.drawImage(p, i);
    painter.end();
}
QImage ImageHandler::getCut(QPoint cp, QPoint lp){
    QRect rct(lp, cp);
    return data.copy(rct);
}



//-------------------------------------------------------------------------------------------------
void ImageHandler::setDrawStyle(QColor color, QColor bcolor, int width, Qt::BrushStyle shapefill, Qt::PenStyle linestyle){
    pen.setColor(color);
    pen.setWidth(width);
    pen.setStyle(linestyle);
    brush.setColor(bcolor);
    brush.setStyle(shapefill);
    pen.setJoinStyle(Qt::RoundJoin);

}
void ImageHandler::setBandStyle(){
    pen.setColor(BAND_COLOR_1);
    pen.setWidth(BAND_WIDTH_1);
    pen.setStyle(Qt::SolidLine);
    pentwo.setColor(BAND_COLOR_2);
    pentwo.setWidth(BAND_WIDTH_2);
    pentwo.setStyle(Qt::DotLine);
    pen.setJoinStyle(Qt::RoundJoin);

}
void ImageHandler::setHandleStyle(){
    pen.setColor(HANDLE_COLOR_1);
    pen.setWidth(HANDLE_WIDTH_1);
    pen.setStyle(Qt::SolidLine);
    pentwo.setColor(HANDLE_COLOR_2);
    pentwo.setWidth(HANDLE_WIDTH_2);
    pentwo.setStyle(Qt::DotLine);
    pen.setJoinStyle(Qt::MiterJoin);
}
void ImageHandler::setFont(QFont f){
    font = f;
}
//-----------------------------------------------------------------------------------
void ImageHandler::drawBand(QRect r){
    painter.begin(&data);
    painter.setPen(pen);
    painter.drawRect(r);
    painter.setPen(pentwo);
    painter.drawRect(r);
    painter.end();
}
void ImageHandler::drawHandle(QPoint p){
    QRect r1 = HANDLE_RECT_1.translated(p);
    QRect r2 = HANDLE_RECT_2.translated(p);
    painter.begin(&data);
    painter.setPen(pen);
    painter.drawRect(r1);
    painter.setPen(pentwo);
    painter.drawRect(r2);
    painter.end();
}

//---------------------------------------------------------------------------------
void ImageHandler::drawPoint(QPoint p){
    painter.begin(&data);
    painter.setPen(pen);
    painter.drawPoint(p);
    painter.end();;
}
void ImageHandler::drawLine(QPoint cp, QPoint lp){
    painter.begin(&data);
    painter.setPen(pen);
    painter.drawLine(cp, lp);
    painter.end();

}
void ImageHandler::drawCircle(QRect r){
    painter.begin(&data);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawEllipse(r);
    painter.end();
}
void ImageHandler::drawSquare(QRect r){
    painter.begin(&data);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(r);
    painter.end();
}
void ImageHandler::drawText(QPoint p, QString s){
    painter.begin(&data);
    painter.setPen(pen);
    painter.setFont(font);
    painter.drawText(p, s);
    painter.end();
}

void ImageHandler::fill(QPoint p, QColor color){
    QRgb c(color.rgb());
    QRgb rc = data.pixel(p);
    if (rc == c){
        return;
    };
    std::queue<QPoint> totest;
    QPoint w;
    QPoint e;
    QPoint n;
    QPoint s;
    totest.push(p);
    while (!totest.empty()){
        w = totest.front();
        totest.pop();
        e = w + EAST;
        while (true){
            if (data.pixel(w) == rc){
                data.setPixel(w, c);
                n = w+NORTH;
                s = w+SOUTH;
                if (data.pixel(n) == rc){
                    totest.push(n);
                }
                if (data.pixel(s) == rc){
                    totest.push(s);
                }
                w += WEST;
            }
            else{
                break;
            }
        }
        while (true){
            if (data.pixel(e) == rc){
                data.setPixel(e, c);
                n = e+NORTH;
                s = e+SOUTH;
                if (data.pixel(n) == rc){
                    totest.push(n);
                }
                if (data.pixel(s) == rc){
                    totest.push(s);
                }
                e += EAST;
            }
            else{
                break;
            }
        }

    }
}


void ImageHandler::drawSpray(QPoint p){
    painter.begin(&data);
    painter.setPen(pen);
    for(int i=0; i<SPRAY_DENSITY; i++){
        double r1 = unif(re);
        double r2 = unif(re);
        double w = SPRAY_RADIUS * sqrt(r1);
        double t = 2 * M_PI * r2;
        int x = w * cos(t);
        int y = w * sin(t);

        painter.drawPoint(p+QPoint(x,y));

    }
    painter.end();
}



