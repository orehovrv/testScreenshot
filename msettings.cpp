#include "msettings.h"

#include <QDebug>

MSettings::MSettings(QWidget * parent): QMainWindow(parent) {
	centralWidget = new QWidget(this);
	mainVerticalLayout = new QGridLayout(centralWidget);

	rminLabel = new QLabel(centralWidget);
	rminLabel->setText("rmin");
	gminLabel = new QLabel(centralWidget);
	gminLabel->setText("gmin");
	bminLabel = new QLabel(centralWidget);
	bminLabel->setText("bmin");
	rmaxLabel = new QLabel(centralWidget);
	rmaxLabel->setText("rmax");
	gmaxLabel = new QLabel(centralWidget);
	gmaxLabel->setText("gmax");
	bmaxLabel = new QLabel(centralWidget);
	bmaxLabel->setText("bmax");

	rminSlider = new QSlider(centralWidget);
	rminSlider->setOrientation(Qt::Horizontal);
	rminSlider->setRange(0, 255);
	rminSlider->setValue(0);
	gminSlider = new QSlider(centralWidget);
	gminSlider->setOrientation(Qt::Horizontal);
	gminSlider->setRange(0, 255);
	gminSlider->setValue(0);
	bminSlider = new QSlider(centralWidget);
	bminSlider->setOrientation(Qt::Horizontal);
	bminSlider->setRange(0, 255);
	bminSlider->setValue(0);
	rmaxSlider = new QSlider(centralWidget);
	rmaxSlider->setOrientation(Qt::Horizontal);
	rmaxSlider->setRange(0, 255);
	rmaxSlider->setValue(255);
	gmaxSlider = new QSlider(centralWidget);
	gmaxSlider->setOrientation(Qt::Horizontal);
	gmaxSlider->setRange(0, 255);
	gmaxSlider->setValue(255);
	bmaxSlider = new QSlider(centralWidget);
	bmaxSlider->setOrientation(Qt::Horizontal);
	bmaxSlider->setRange(0, 255);
	bmaxSlider->setValue(255);

	rminSpinBox = new QSpinBox(centralWidget);
	rminSpinBox->setRange(0, 255);
	rminSpinBox->setValue(0);
	gminSpinBox = new QSpinBox(centralWidget);
	gminSpinBox->setRange(0, 255);
	gminSpinBox->setValue(0);
	bminSpinBox = new QSpinBox(centralWidget);
	bminSpinBox->setRange(0, 255);
	bminSpinBox->setValue(0);
	rmaxSpinBox = new QSpinBox(centralWidget);
	rmaxSpinBox->setRange(0, 255);
	rmaxSpinBox->setValue(255);
	gmaxSpinBox = new QSpinBox(centralWidget);
	gmaxSpinBox->setRange(0, 255);
	gmaxSpinBox->setValue(255);
	bmaxSpinBox = new QSpinBox(centralWidget);
	bmaxSpinBox->setRange(0, 255);
	bmaxSpinBox->setValue(255);

	xLabel = new QLabel(centralWidget);
	xLabel->setText("x");
	yLabel = new QLabel(centralWidget);
	yLabel->setText("y");
	wLabel = new QLabel(centralWidget);
	wLabel->setText("w");
	hLabel = new QLabel(centralWidget);
	hLabel->setText("h");

	xSpinBox = new QSpinBox(centralWidget);
	xSpinBox->setMaximum(3840);
	xSpinBox->setMinimum(-1920);
	ySpinBox = new QSpinBox(centralWidget);
	ySpinBox->setMaximum(1080);
	wSpinBox = new QSpinBox(centralWidget);
	wSpinBox->setMaximum(5760);
	hSpinBox = new QSpinBox(centralWidget);
	hSpinBox->setMaximum(1080);

	//triangleLabel = new QLabel(centralWidget);
	//triangleLabel->setMinimumSize(312, 270);
	//triangleLabel->setMaximumSize(312, 270);
	//triangleLabel->setScaledContents(true);

	mainVerticalLayout->addWidget(rminLabel, 0, 0);
	mainVerticalLayout->addWidget(gminLabel, 1, 0);
	mainVerticalLayout->addWidget(bminLabel, 2, 0);
	mainVerticalLayout->addWidget(rmaxLabel, 3, 0);
	mainVerticalLayout->addWidget(gmaxLabel, 4, 0);
	mainVerticalLayout->addWidget(bmaxLabel, 5, 0);

	mainVerticalLayout->addWidget(rminSlider, 0, 1);
	mainVerticalLayout->addWidget(gminSlider, 1, 1);
	mainVerticalLayout->addWidget(bminSlider, 2, 1);
	mainVerticalLayout->addWidget(rmaxSlider, 3, 1);
	mainVerticalLayout->addWidget(gmaxSlider, 4, 1);
	mainVerticalLayout->addWidget(bmaxSlider, 5, 1);

	mainVerticalLayout->addWidget(rminSpinBox, 0, 2);
	mainVerticalLayout->addWidget(gminSpinBox, 1, 2);
	mainVerticalLayout->addWidget(bminSpinBox, 2, 2);
	mainVerticalLayout->addWidget(rmaxSpinBox, 3, 2);
	mainVerticalLayout->addWidget(gmaxSpinBox, 4, 2);
	mainVerticalLayout->addWidget(bmaxSpinBox, 5, 2);

	mainVerticalLayout->addWidget(xLabel, 6, 0);
	mainVerticalLayout->addWidget(yLabel, 7, 0);
	mainVerticalLayout->addWidget(wLabel, 8, 0);
	mainVerticalLayout->addWidget(hLabel, 9, 0);

	mainVerticalLayout->addWidget(xSpinBox, 6, 1, 1, 2);
	mainVerticalLayout->addWidget(ySpinBox, 7, 1, 1, 2);
	mainVerticalLayout->addWidget(wSpinBox, 8, 1, 1, 2);
	mainVerticalLayout->addWidget(hSpinBox, 9, 1, 1, 2);
	//mainVerticalLayout->addWidget(triangleLabel, 0, 3, 10, 1);

	mainVerticalLayout->setColumnStretch(0, 1);
	mainVerticalLayout->setColumnStretch(1, 10);
	mainVerticalLayout->setColumnStretch(2, 2);
	//mainVerticalLayout->setColumnStretch(3, 20);

	this->setCentralWidget(centralWidget);
	//this->setMinimumWidth(800);
	//this->setMaximumHeight(220);

	connect(rminSlider, SIGNAL(sliderMoved(int)), this, SLOT(rminSlider_sliderMoved()));
	connect(gminSlider, SIGNAL(sliderMoved(int)), this, SLOT(gminSlider_sliderMoved()));
	connect(bminSlider, SIGNAL(sliderMoved(int)), this, SLOT(bminSlider_sliderMoved()));
	connect(rmaxSlider, SIGNAL(sliderMoved(int)), this, SLOT(rmaxSlider_sliderMoved()));
	connect(gmaxSlider, SIGNAL(sliderMoved(int)), this, SLOT(gmaxSlider_sliderMoved()));
	connect(bmaxSlider, SIGNAL(sliderMoved(int)), this, SLOT(bmaxSlider_sliderMoved()));

	connect(rminSpinBox, SIGNAL(valueChanged(int)), this, SLOT(rminSpinBox_valueChanged()));
	connect(gminSpinBox, SIGNAL(valueChanged(int)), this, SLOT(gminSpinBox_valueChanged()));
	connect(bminSpinBox, SIGNAL(valueChanged(int)), this, SLOT(bminSpinBox_valueChanged()));
	connect(rmaxSpinBox, SIGNAL(valueChanged(int)), this, SLOT(rmaxSpinBox_valueChanged()));
	connect(gmaxSpinBox, SIGNAL(valueChanged(int)), this, SLOT(gmaxSpinBox_valueChanged()));
	connect(bmaxSpinBox, SIGNAL(valueChanged(int)), this, SLOT(bmaxSpinBox_valueChanged()));

	connect(xSpinBox, SIGNAL(valueChanged(int)), this, SLOT(xSpinBox_valueChanged()));
	connect(ySpinBox, SIGNAL(valueChanged(int)), this, SLOT(ySpinBox_valueChanged()));
	connect(wSpinBox, SIGNAL(valueChanged(int)), this, SLOT(wSpinBox_valueChanged()));
	connect(hSpinBox, SIGNAL(valueChanged(int)), this, SLOT(hSpinBox_valueChanged()));
}

//void MainWindow::setTrianglePixmap(QPixmap pixmapIn) {
//    pixmap = pixmapIn;
//    triangleLabel->setPixmap(pixmap);
//}

void MSettings::setMin(int r, int g, int b) {
	rminSlider->setValue(r);
	gminSlider->setValue(g);
	bminSlider->setValue(b);

	rminSlider_sliderMoved();
	gminSlider_sliderMoved();
	bminSlider_sliderMoved();

	emit rminChanged(r);
	emit gminChanged(g);
	emit bminChanged(b);
}

void MSettings::setMax(int r, int g, int b) {
	rmaxSlider->setValue(r);
	gmaxSlider->setValue(g);
	bmaxSlider->setValue(b);

	rmaxSlider_sliderMoved();
	gmaxSlider_sliderMoved();
	bmaxSlider_sliderMoved();

	emit rmaxChanged(r);
	emit gmaxChanged(g);
	emit bmaxChanged(b);
}

void MSettings::setDefaultRect(int xIn, int yIn, int wIn, int hIn) {
	xSpinBox->setValue(xIn);
	ySpinBox->setValue(yIn);
	wSpinBox->setValue(wIn);
	hSpinBox->setValue(hIn);

	emit xChanged(xIn);
	emit yChanged(yIn);
	emit wChanged(wIn);
	emit hChanged(hIn);
}

//========================================================================================================

void MSettings::rminSpinBox_valueChanged() {
	int temp = rminSpinBox->value();
	rminSlider->setValue(temp);
	if(rmaxSlider->value() < temp) {
		rmaxSlider->setValue(temp);
		rmaxSpinBox->setValue(temp);
	}
	emit rminChanged(temp);
}

void MSettings::rminSlider_sliderMoved() {
	int temp = rminSlider->value();
	rminSpinBox->setValue(temp);
	if(rmaxSlider->value() < temp) {
		rmaxSlider->setValue(temp);
		rmaxSpinBox->setValue(temp);
	}
	emit rminChanged(temp);
}

void MSettings::gminSpinBox_valueChanged() {
	int temp = gminSpinBox->value();
	gminSlider->setValue(temp);
	if(gmaxSlider->value() < temp) {
		gmaxSlider->setValue(temp);
		gmaxSpinBox->setValue(temp);
	}
	emit gminChanged(temp);
}

void MSettings::gminSlider_sliderMoved() {
	int temp = gminSlider->value();
	gminSpinBox->setValue(temp);
	if(gmaxSlider->value() < temp) {
		gmaxSlider->setValue(temp);
		gmaxSpinBox->setValue(temp);
	}
	emit gminChanged(temp);
}

void MSettings::bminSpinBox_valueChanged() {
	int temp = bminSpinBox->value();
	bminSlider->setValue(temp);
	if(bmaxSlider->value() < temp) {
		bmaxSlider->setValue(temp);
		bmaxSpinBox->setValue(temp);
	}
	emit bminChanged(temp);
}

void MSettings::bminSlider_sliderMoved() {
	int temp = bminSlider->value();
	bminSpinBox->setValue(temp);
	if(bmaxSlider->value() < temp) {
		bmaxSlider->setValue(temp);
		bmaxSpinBox->setValue(temp);
	}
	emit bminChanged(temp);
}

void MSettings::rmaxSpinBox_valueChanged() {
	int temp = rmaxSpinBox->value();
	rmaxSlider->setValue(temp);
	if(temp < rminSlider->value()) {
		rminSlider->setValue(temp);
		rminSpinBox->setValue(temp);
	}
	emit rmaxChanged(temp);
}

void MSettings::rmaxSlider_sliderMoved() {
	int temp = rmaxSlider->value();
	rmaxSpinBox->setValue(temp);
	if(temp < rminSlider->value()) {
		rminSlider->setValue(temp);
		rminSpinBox->setValue(temp);
	}
	emit rmaxChanged(temp);
}

void MSettings::gmaxSpinBox_valueChanged() {
	int temp = gmaxSpinBox->value();
	gmaxSlider->setValue(temp);
	if(temp < gminSlider->value()) {
		gminSlider->setValue(temp);
		gminSpinBox->setValue(temp);
	}
	emit gmaxChanged(temp);
}

void MSettings::gmaxSlider_sliderMoved() {
	int temp = gmaxSlider->value();
	gmaxSpinBox->setValue(temp);
	if(temp < gminSlider->value()) {
		gminSlider->setValue(temp);
		gminSpinBox->setValue(temp);
	}
	emit gmaxChanged(temp);
}

void MSettings::bmaxSpinBox_valueChanged() {
	int temp = bmaxSpinBox->value();
	bmaxSlider->setValue(temp);
	if(temp < bminSlider->value()) {
		bminSlider->setValue(temp);
		bminSpinBox->setValue(temp);
	}
	emit bmaxChanged(temp);
}

void MSettings::bmaxSlider_sliderMoved() {
	int temp = bmaxSlider->value();
	bmaxSpinBox->setValue(temp);
	if(temp < bminSlider->value()) {
		bminSlider->setValue(temp);
		bminSpinBox->setValue(temp);
	}
	emit bmaxChanged(temp);
}

//========================================================================================================

void MSettings::xSpinBox_valueChanged() {
	emit xChanged(xSpinBox->value());
}

void MSettings::ySpinBox_valueChanged() {
	emit yChanged(ySpinBox->value());
}

void MSettings::wSpinBox_valueChanged() {
	emit wChanged(wSpinBox->value());
}

void MSettings::hSpinBox_valueChanged() {
	emit hChanged(hSpinBox->value());
}

//========================================================================================================

int MSettings::valueRMin() {
	return rminSlider->value();
}

int MSettings::valueGMin() {
	return gminSlider->value();
}

int MSettings::valueBMin() {
	return bminSlider->value();
}

int MSettings::valueRMax() {
	return rmaxSlider->value();
}

int MSettings::valueGMax() {
	return gmaxSlider->value();
}

int MSettings::valueBMax() {
	return bmaxSlider->value();
}

int MSettings::valueX() {
	return xSpinBox->value();
}

int MSettings::valueY() {
	return ySpinBox->value();
}

int MSettings::valueW() {
	return wSpinBox->value();
}

int MSettings::valueH() {
	return hSpinBox->value();
}
