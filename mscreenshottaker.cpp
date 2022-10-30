#include "mscreenshottaker.h"

MScreenshotTaker::MScreenshotTaker() {
	x = y = 0;
	w = h = 200;
	wLast = hLast = -1;
	screen = QGuiApplication::primaryScreen();
}

void MScreenshotTaker::setRect(QRect rectIn) {
	x = rectIn.x();
	y = rectIn.y();
	wLast = w = rectIn.width();
	hLast = h = rectIn.height();
}

QRect MScreenshotTaker::getRect() {
	return QRect(x, y, w, h);
}

void MScreenshotTaker::newScreenshot() {
	screenshot = screen->grabWindow(0, x, y, w, h);
	emit screenshotChanged(screenshot);

	bool flag = false;

	if(w != wLast) { flag = true; wLast = w; }
	if(h != hLast) { flag = true; hLast = h; }
	if(flag) emit pixmapSizeChanged(w, h);
}

void MScreenshotTaker::setX(int xIn) {
	x = xIn;
}

void MScreenshotTaker::setY(int yIn) {
	y = yIn;
}

void MScreenshotTaker::setW(int wIn) {
	w = wIn;
}

void MScreenshotTaker::setH(int hIn) {
	h = hIn;
}
