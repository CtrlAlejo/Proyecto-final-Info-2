#ifndef NIVEL3_H
#define NIVEL3_H

#include <QObject>
#include <QGraphicsView>
#include "morty.h"
#include "obstaculo.h"

class Nivel3 : public QGraphicsView
{
    Q_OBJECT
public:
    Nivel3(QWidget *parent = NULL);
private:
    QGraphicsScene *nivel1;
    Morty *morty2;
    Plataforma *base;

};

#endif // NIVEL3_H
