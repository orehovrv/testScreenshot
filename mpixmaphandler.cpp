#include "mpixmaphandler.h"

#include <QDebug>

MPixmapHandler::MPixmapHandler(QObject * parent) : QObject(new QObject(parent)) {
	rmin = 0, rmax = 255;
	gmin = 0, gmax = 255;
	bmin = 0, bmax = 255;

	drawPixmap();
}

void MPixmapHandler::setPixamp(QPixmap pixmapIN) {
	pixmapOriginal = pixmapIN;
	drawPixmap();
}

void MPixmapHandler::drawPixmap() {
	if(pixmapOriginal.isNull()) return;

	QImage temp = pixmapOriginal.toImage();

	int i, j;
	for(i = 0; i < pixmapOriginal.width(); i++)
		for(j = 0; j < pixmapOriginal.height(); j++) {
			QColor color(temp.pixel(i, j));
			if(rmin <= color.red() && color.red() <= rmax &&
			   gmin <= color.green() && color.green() <= gmax &&
			   bmin <= color.blue() && color.blue() <= bmax) temp.setPixel(i, j, 0);
			else temp.setPixel(i, j, 0xFFFFFF);
	}
	pixmapProcessed = QPixmap::fromImage(temp, Qt::AutoColor);

	emit pixmapChanged(pixmapProcessed);
}

void MPixmapHandler::setRMin(int rIn) {
	rmin = rIn;
	drawPixmap();
}

void MPixmapHandler::setGMin(int gIn) {
	gmin = gIn;
	drawPixmap();
}

void MPixmapHandler::setBMin(int bIn) {
	bmin = bIn;
	drawPixmap();
}

void MPixmapHandler::setRMax(int rIn) {
	rmax = rIn;
	drawPixmap();
}

void MPixmapHandler::setGMax(int gIn) {
	gmax = gIn;
	drawPixmap();
}

void MPixmapHandler::setBMax(int bIn) {
	bmax = bIn;
	drawPixmap();
}
