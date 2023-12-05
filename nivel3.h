#ifndef NIVEL3_H
#define NIVEL3_H

#include <QObject>
#include <QGraphicsView>
#include "morty_armado.h"
#include "obstaculo.h"
#include "jefe.h"

class Nivel3 : public QGraphicsView
{
    Q_OBJECT
public:
    Nivel3(QWidget *parent = NULL);
private:
    void start();
    QGraphicsScene * nivel3;
    QGraphicsPixmapItem * fondo;
    Morty_Armado * morty2;
    Plataforma * base;
    Jefe * supernova;
};

#endif // NIVEL3_H
