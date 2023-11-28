#ifndef PIZARRA_H
#define PIZARRA_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QKeyEvent>

class Pizarra : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Pizarra(int w, int h, QGraphicsRectItem *parent = NULL);
protected:
    void keyPressEvent(QKeyEvent *evento);
private:
    QPointF posicion;
};

#endif // PIZARRA_H
