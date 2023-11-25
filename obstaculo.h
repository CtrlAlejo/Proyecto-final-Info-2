#ifndef OBSTACULO_H
#define OBSTACULO_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class Obstaculo : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Obstaculo(int x, int y, int w, int h, QString file, QObject *parent = NULL);
protected:
    int posX;
    int posY;
    int alto;
    int ancho;
};

class Sierra : public Obstaculo
{
    Q_OBJECT
public:
    Sierra(int x, int y, int w, int h, QString file, QObject *parent = NULL);
};

class Pincho : public Obstaculo
{
    Q_OBJECT
public:
    Pincho(int x, int y, int w, int h, QString file, QObject *parent = NULL);
    void keyPressEvent(QKeyEvent *evento);
};

class Plataforma : public Obstaculo
{
    Q_OBJECT
public:
    Plataforma(int x, int y, int w, int h, QString file, QObject *parent = NULL);
    void keyPressEvent(QKeyEvent *evento);
};

class Lago : public Obstaculo
{
    Q_OBJECT
public:
    Lago(int x, int y, int w, int h, QString file, QObject *parent = NULL);
    void keyPressEvent(QKeyEvent *evento);
};

#endif // OBSTACULO_H
