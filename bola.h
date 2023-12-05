#ifndef BOLA_H
#define BOLA_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Bola : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bola(int w, int h, QString file, QObject *parent = NULL);
private:
    int alto;
    int ancho;
};

#endif // BOLA_H
