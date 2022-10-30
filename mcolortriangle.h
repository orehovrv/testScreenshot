#ifndef MCOLORTRIANGLE_H
#define MCOLORTRIANGLE_H

#include <QObject>
#include <QtMath>

#include <QImage>
#include <QPixmap>

class MColorTriangle : public QObject {
        Q_OBJECT

    private:
        QImage image;
        const int widgtImage = 800;

        int rmin, rmax;
        int gmin, gmax;
        int bmin, bmax;

        void drawTriangle();

    public:
        MColorTriangle(QObject * parent = nullptr);

    public slots:
        void setRMin(int);
        void setGMin(int);
        void setBMin(int);
        void setRMax(int);
        void setGMax(int);
        void setBMax(int);

    signals:
        void pixmapChanged(QPixmap);
};

#endif // MCOLORTRIANGLE_H
