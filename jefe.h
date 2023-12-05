#ifndef JEFE_H
#define JEFE_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QRandomGenerator>
#include <QTimer>
#include <QGraphicsScene>
#include "bola.h"

class Jefe : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Jefe(QGraphicsScene * _escena, int w, int h, QString file, QObject *parent = NULL);
    void postura_jefe();
    void bola_orbitante();
    void disminuir_vida();
public slots:
    void tomar_posicion_morty(QPointF _posicion_morty);
private slots:
    void ataques_jefe();
    void movimiento_jefe();
    void act_movimiento();
private:
    int vida;
    QPointF posicion_jefe;
    QPointF posicion_morty;
    bool detect_plataforma;
    int mov;
    int alto;
    int ancho;
    qreal Vy;
    qreal Vx;
    qreal gravedad;
    qreal salto;
    QTimer * timer;
    QTimer * timer2;
    QTimer * timer3;
    Bola * bola;
    int postura;
    QGraphicsScene * escena;
};

#endif // JEFE_H
