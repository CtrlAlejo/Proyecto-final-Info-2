#ifndef IMAGEN_H
#define IMAGEN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class imagen : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    imagen(int w, int h, QString file, QObject *parent = NULL);
    int alto;
    int ancho;
protected:
    void keyPressEvent(QKeyEvent *evento);
private:
    QPointF posicion;
};

#endif // IMAGEN_H
