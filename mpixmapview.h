#ifndef MPIXMAPVIEW_H
#define MPIXMAPVIEW_H

#include <QMainWindow>
#include <QWidget>
#include <QObject>

#include <QVBoxLayout>

#include <QPixmap>
#include <QLabel>

class MPixmapView : public QMainWindow {
		Q_OBJECT

	private:
		QWidget * centralWidget;
		QVBoxLayout * mainLayout;
		QLabel * pixmapLabel;

		QPixmap pixmap;

		void updateLabel();

	protected:
		void resizeEvent(QResizeEvent * event) override;

	public:
		MPixmapView(QWidget * parent = nullptr);

	public slots:
		void setPixmap(QPixmap);
		void resizeWindow(int, int);

	signals:
		void pixmapChanged(QPixmap);
};

#endif // MPIXMAPVIEW_H
