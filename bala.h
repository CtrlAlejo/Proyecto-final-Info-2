#ifndef BALA_H
#define BALA_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class Bala : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bala(int tipo_desplazamiento, int Xo, int w, int h, QObject *parent = NULL);
    virtual void verificar_colisiones();
public slots:
    virtual void desplazamiento_bala();
protected:
    int alto;
    int ancho;
    int dir_desplazamiento;
    qreal Vx;
    qreal X;
    QTimer * timer;
    QPointF posicion;
private:
    QString f_bala_izquierda;
    QString f_bala_derecha;
    QString f_bala_derecha_dañada;
    QString f_bala_izquierda_dañada;
};

#endif // BALA_H
