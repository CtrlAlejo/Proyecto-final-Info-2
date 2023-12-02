#ifndef OBSTACULO_H
#define OBSTACULO_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QTimer>

class Obstaculo : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Obstaculo();
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
    Sierra(int tipo_mov, int w, int h, QString file, QObject *parent = NULL);
private slots:
    void movimiento_sierra();
private:
    bool alternador_mov;
    QTimer *control_mov;
    int tipo_movimiento;
};

class Pincho : public Obstaculo
{
    Q_OBJECT
public:
    Pincho(int w, int h, QString file, QObject *parent = NULL);
};

class Plataforma : public Obstaculo
{
    Q_OBJECT
public:
    Plataforma(int w, int h, QString file, QObject *parent = NULL);
    QPointF get_posicion();
};

class Lago : public Obstaculo
{
    Q_OBJECT
public:
    Lago(int w, int h, QString file, QObject *parent = NULL);
};
#endif // OBSTACULO_H
