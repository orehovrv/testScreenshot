#include "msettings.h"
#include "mscreenshottaker.h"
#include "mpixmaphandler.h"
#include "mpixmapview.h"

#include <QApplication>

#include <QTimer>

#define FPS 10

int main(int argc, char * argv[]) {
	QApplication a(argc, argv);

	QTimer timerUpdate;

	MScreenshotTaker screenshot;
	MPixmapHandler pixmapHandler;

	MSettings settings;
	MPixmapView originalPixmap;
	MPixmapView processedPixmap;
	//MColorTriangle colorTriangle;

	QObject::connect(&timerUpdate, SIGNAL(timeout()), &screenshot, SLOT(newScreenshot()));
	QObject::connect(&screenshot, SIGNAL(screenshotChanged(QPixmap)), &originalPixmap, SLOT(setPixmap(QPixmap)));
	QObject::connect(&screenshot, SIGNAL(screenshotChanged(QPixmap)), &pixmapHandler, SLOT(setPixamp(QPixmap)));
	QObject::connect(&screenshot, SIGNAL(pixmapSizeChanged(int, int)), &originalPixmap, SLOT(resizeWindow(int, int)));
	QObject::connect(&screenshot, SIGNAL(pixmapSizeChanged(int, int)), &processedPixmap, SLOT(resizeWindow(int, int)));
	QObject::connect(&pixmapHandler, SIGNAL(pixmapChanged(QPixmap)), &processedPixmap, SLOT(setPixmap(QPixmap)));

	QObject::connect(&settings, SIGNAL(xChanged(int)), &screenshot, SLOT(setX(int)));
	QObject::connect(&settings, SIGNAL(yChanged(int)), &screenshot, SLOT(setY(int)));
	QObject::connect(&settings, SIGNAL(wChanged(int)), &screenshot, SLOT(setW(int)));
	QObject::connect(&settings, SIGNAL(hChanged(int)), &screenshot, SLOT(setH(int)));

	QObject::connect(&settings, SIGNAL(rminChanged(int)), &pixmapHandler, SLOT(setRMin(int)));
	QObject::connect(&settings, SIGNAL(gminChanged(int)), &pixmapHandler, SLOT(setGMin(int)));
	QObject::connect(&settings, SIGNAL(bminChanged(int)), &pixmapHandler, SLOT(setBMin(int)));
	QObject::connect(&settings, SIGNAL(rmaxChanged(int)), &pixmapHandler, SLOT(setRMax(int)));
	QObject::connect(&settings, SIGNAL(gmaxChanged(int)), &pixmapHandler, SLOT(setGMax(int)));
	QObject::connect(&settings, SIGNAL(bmaxChanged(int)), &pixmapHandler, SLOT(setBMax(int)));

	//QObject::connect(&settings, SIGNAL(rminChanged(int)), &colorTriangle, SLOT(setRMin(int)));
	//QObject::connect(&settings, SIGNAL(gminChanged(int)), &colorTriangle, SLOT(setGMin(int)));
	//QObject::connect(&settings, SIGNAL(bminChanged(int)), &colorTriangle, SLOT(setBMin(int)));
	//QObject::connect(&settings, SIGNAL(rmaxChanged(int)), &colorTriangle, SLOT(setRMax(int)));
	//QObject::connect(&settings, SIGNAL(gmaxChanged(int)), &colorTriangle, SLOT(setGMax(int)));
	//QObject::connect(&settings, SIGNAL(bmaxChanged(int)), &colorTriangle, SLOT(setBMax(int)));

	//QObject::connect(&colorTriangle, SIGNAL(pixmapChanged(QPixmap)), &settings, SLOT(setTrianglePixmap(QPixmap)));

	QList qq = qApp->screens();
	int offset = 1920;
	if(1 == qq.count()) offset = 0;

	timerUpdate.start(1000. / FPS);

	QIcon iconSettings("D:/Pictures/Авы/W8-jrdou350.jpg");
	QIcon iconOriginalPixmap("D:/Pictures/Авы/wgjjR9Wxot.jpg");
	QIcon iconProcessedPixmap("D:/Pictures/Авы/gRFqFj6zUX0.jpg");

	settings.move(offset + 120, 480);
	settings.resize(300, 290);
	settings.setWindowTitle("Settings");
	settings.setWindowIcon(iconSettings);
	settings.setMin(0, 213, 0);
	settings.setMax(255, 255, 255);
	settings.setDefaultRect(offset + 810, 695, 790, 120);
	settings.show();

	originalPixmap.move(offset + 1060, 900);
	originalPixmap.setWindowTitle("Original");
	originalPixmap.setWindowIcon(iconOriginalPixmap);
	originalPixmap.show();

	processedPixmap.move(offset + 230, 900);
	processedPixmap.setWindowTitle("Processed");
	processedPixmap.setWindowIcon(iconProcessedPixmap);
	processedPixmap.show();

	return a.exec();
}
