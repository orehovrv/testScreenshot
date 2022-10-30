#include "mpixmapview.h"

MPixmapView::MPixmapView(QWidget * parent) : QMainWindow(parent) {
	centralWidget = new QWidget(this);
	mainLayout = new QVBoxLayout(centralWidget);
	mainLayout->setContentsMargins(0, 0, 0, 0);

	pixmapLabel = new QLabel(centralWidget);
	pixmapLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	pixmapLabel->setAlignment(Qt::AlignCenter);
	pixmapLabel->setMinimumSize(200, 100);

	mainLayout->addWidget(pixmapLabel);

	this->setCentralWidget(centralWidget);
}

void MPixmapView::setPixmap(QPixmap pixmapIn) {
	pixmap = pixmapIn;
	updateLabel();
}

void MPixmapView::updateLabel() {
	if(pixmap.isNull()) return;
	pixmapLabel->setPixmap(pixmap.scaled(pixmapLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
}

void MPixmapView::resizeEvent(QResizeEvent * event) {
	QSize scaledSize = pixmap.size();
	scaledSize.scale(pixmapLabel->size(), Qt::KeepAspectRatio);
	if (scaledSize != pixmapLabel->pixmap(Qt::ReturnByValue).size())
		updateLabel();
}

void MPixmapView::resizeWindow(int w, int h) {
	this->resize(w, h);
	updateLabel();
}
