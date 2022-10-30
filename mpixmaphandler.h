#ifndef MPIXMAPHANDLER_H
#define MPIXMAPHANDLER_H

#include <QObject>

#include <QImage>
#include <QPixmap>

class MPixmapHandler : public QObject {
		Q_OBJECT

	private:
		QPixmap pixmapOriginal, pixmapProcessed;

		int rmin, rmax;
		int gmin, gmax;
		int bmin, bmax;

		void drawPixmap();

	public:
		MPixmapHandler(QObject * parent = nullptr);

	public slots:
		void setPixamp(QPixmap);

		void setRMin(int);
		void setGMin(int);
		void setBMin(int);
		void setRMax(int);
		void setGMax(int);
		void setBMax(int);

	signals:
		void pixmapChanged(QPixmap);
};

#endif // MPIXMAPHANDLER_H
