#ifndef IMAGEN_H
#define IMAGEN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class imagen : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    imagen(int _id, int w, int h, QString file, QObject *parent = NULL);
    int alto;
    int ancho;
    int get_id();
private:
    int id;
    QPointF posicion;
};

#endif // IMAGEN_H
