#ifndef OBSTACULO_H
#define OBSTACULO_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class Obstaculo : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Obstaculo(int w, int h, QString file, QObject *parent = NULL);
protected:
    int alto;
    int ancho;
    QPointF posicion;
};

class Sierra : public Obstaculo
{
    Q_OBJECT
public:
    Sierra(int w, int h, QString file, QObject *parent = NULL);
};

class Pincho : public Obstaculo
{
    Q_OBJECT
public:
    Pincho(int w, int h, QString file, QObject *parent = NULL);
    void keyPressEvent(QKeyEvent *evento);
};

class Plataforma : public Obstaculo
{
    Q_OBJECT
public:
    Plataforma(int w, int h, QString file, QObject *parent = NULL);
    void keyPressEvent(QKeyEvent *evento);
    QPointF get_posicion();
};

class Lago : public Obstaculo
{
    Q_OBJECT
public:
    Lago(int w, int h, QString file, QObject *parent = NULL);
    void keyPressEvent(QKeyEvent *evento);
};

#endif // OBSTACULO_H
