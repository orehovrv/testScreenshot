#ifndef MSETTINGS_H
#define MSETTINGS_H

#include <QMainWindow>

#include <QVBoxLayout>
#include <QGridLayout>

#include <QLabel>
#include <QSlider>
#include <QSpinBox>

#include <QPixmap>

class MSettings : public QMainWindow {
		Q_OBJECT

	private:
		QWidget * centralWidget;
		QGridLayout * mainVerticalLayout;

		QLabel * rminLabel;
		QLabel * gminLabel;
		QLabel * bminLabel;
		QLabel * rmaxLabel;
		QLabel * gmaxLabel;
		QLabel * bmaxLabel;

		QSlider * rminSlider;
		QSlider * gminSlider;
		QSlider * bminSlider;
		QSlider * rmaxSlider;
		QSlider * gmaxSlider;
		QSlider * bmaxSlider;

		QSpinBox * rminSpinBox;
		QSpinBox * gminSpinBox;
		QSpinBox * bminSpinBox;
		QSpinBox * rmaxSpinBox;
		QSpinBox * gmaxSpinBox;
		QSpinBox * bmaxSpinBox;

		QLabel * xLabel;
		QLabel * yLabel;
		QLabel * wLabel;
		QLabel * hLabel;

		QSpinBox * xSpinBox;
		QSpinBox * ySpinBox;
		QSpinBox * wSpinBox;
		QSpinBox * hSpinBox;

		//QLabel * triangleLabel;
		//QPixmap pixmap;

	public:
		MSettings(QWidget * parent = nullptr);

		void setMin(int, int, int);
		void setMax(int, int, int);
		void setDefaultRect(int, int, int, int);

		int valueRMin();
		int valueGMin();
		int valueBMin();
		int valueRMax();
		int valueGMax();
		int valueBMax();

		int valueX();
		int valueY();
		int valueW();
		int valueH();

	private slots:
		void rminSlider_sliderMoved();
		void gminSlider_sliderMoved();
		void bminSlider_sliderMoved();
		void rmaxSlider_sliderMoved();
		void gmaxSlider_sliderMoved();
		void bmaxSlider_sliderMoved();

		void rminSpinBox_valueChanged();
		void gminSpinBox_valueChanged();
		void bminSpinBox_valueChanged();
		void rmaxSpinBox_valueChanged();
		void gmaxSpinBox_valueChanged();
		void bmaxSpinBox_valueChanged();

		void xSpinBox_valueChanged();
		void ySpinBox_valueChanged();
		void wSpinBox_valueChanged();
		void hSpinBox_valueChanged();

		//void setTrianglePixmap(QPixmap);

	signals:
		void rminChanged(int);
		void gminChanged(int);
		void bminChanged(int);
		void rmaxChanged(int);
		void gmaxChanged(int);
		void bmaxChanged(int);

		void xChanged(int);
		void yChanged(int);
		void wChanged(int);
		void hChanged(int);
};

#endif // MSETTINGS_H
