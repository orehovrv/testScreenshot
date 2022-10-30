#ifndef MSCREENSHOTTAKER_H
#define MSCREENSHOTTAKER_H

#include <QApplication>

#include <QObject>

#include <QScreen>
#include <QPixmap>

class MScreenshotTaker : public QObject {
		Q_OBJECT;

		QScreen * screen;

		QPixmap screenshot;
		int x, y, w, h, wLast, hLast;

	public:
		MScreenshotTaker();

		void setRect(QRect);
		QRect getRect();

	public slots:
		void newScreenshot();

		void setX(int);
		void setY(int);
		void setW(int);
		void setH(int);

	signals:
		void screenshotChanged(QPixmap);
		void pixmapSizeChanged(int, int);
};

#endif // MSCREENSHOTTAKER_H
