#include "mcolortriangle.h"

#include <QDebug>

MColorTriangle::MColorTriangle(QObject * parent) : QObject(new QObject(parent)) {
    rmin = 0, rmax = 255;
    gmin = 0, gmax = 255;
    bmin = 0, bmax = 255;

    drawTriangle();
}

void MColorTriangle::drawTriangle() {
    QRect v1(0, 0, 0, 0);
    QRect v2(widgtImage, 0, 0, 0);
    QRect v3(v2.x() / 2., sqrt(v2.x() * v2.x() - (v2.x() / 2.) * (v2.x() / 2.)), 0,0);

    image = QImage(v2.x() + 1, v3.y() + 1, QImage::Format_ARGB32);

    int i, j;
    for(i = 0; i < image.width(); i++)
        for(j = 0; j < image.height(); j++)
            image.setPixel(i, j, 0x00000000);

    double l1, l2, l3, T = (v2.y() - v3.y()) * (v1.x() - v3.x()) + (v3.x() - v2.x()) * (v1.y() - v3.y());
    int colorR, colorG, colorB;
    for(i = 0; i < image.width(); i++)
        for(j = 0; j < image.height(); j++) {
            l1 = ((v2.y() - v3.y()) * (i - v3.x()) + (v3.x() - v2.x()) * (j - v3.y())) / T;
            l2 = ((v3.y() - v1.y()) * (i - v3.x()) + (v1.x() - v3.x()) * (j - v3.y())) / T;
            l3 = 1 - l1 - l2;

            colorR = l1 * 255 * 3;
            colorG = l3 * 255 * 3;
            colorB = l2 * 255 * 3;
            if(255 < colorR) colorR = 255;
            if(255 < colorG) colorG = 255;
            if(255 < colorB) colorB = 255;

            //if(colorR < 0) colorR = 0;
            //if(colorG < 0) colorG = 0;
            //if(colorB < 0) colorB = 0;

            if(l1 < -0.0001) break;
            if(l2 < -0.0001) break;
            if(l3 < -0.0001) break;

            QColor color(colorR, colorG, colorB);
            if(rmin <= color.red() && color.red() <= rmax &&
               gmin <= color.green() && color.green() <= gmax &&
               bmin <= color.blue() && color.blue() <= bmax) image.setPixel(i, j, color.rgba());
        }

    image.save("E:/test.png");

    emit pixmapChanged(QPixmap::fromImage(image));
}

void MColorTriangle::setRMin(int rIn) {
    rmin = rIn;
    drawTriangle();
}

void MColorTriangle::setGMin(int gIn) {
    gmin = gIn;
 drawTriangle();
}

void MColorTriangle::setBMin(int bIn) {
    bmin = bIn;
    drawTriangle();
}

void MColorTriangle::setRMax(int rIn) {
    rmax = rIn;
    drawTriangle();
}

void MColorTriangle::setGMax(int gIn) {
    gmax = gIn;
    drawTriangle();
}

void MColorTriangle::setBMax(int bIn) {
    bmax = bIn;
    drawTriangle();
}
