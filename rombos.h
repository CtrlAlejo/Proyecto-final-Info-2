#ifndef ROMBOS_H
#define ROMBOS_H

#include <QObject>
#include <QGraphicsPixmapItem>

class rombos : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    rombos();
    rombos(int w, int h, QString file, QObject *parent = NULL);
protected:
    int alto;
    int ancho;
    QPointF posicion;
public slots:
    //void click_rombo();
};

#endif // ROMBOS_H
