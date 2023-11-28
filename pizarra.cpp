#include "pizarra.h"
#include "qbrush.h"
#include "qpen.h"

Pizarra::Pizarra(int w, int h, QGraphicsRectItem *parent) : QGraphicsRectItem (0,0, w, h, parent)
{
    setBrush(QBrush(Qt::white));
    setPen(QPen(Qt::black, 1));
//    setFlag(QGraphicsItem::ItemIsFocusable);
//    setFocus();
}

void Pizarra::keyPressEvent(QKeyEvent *evento)
{
    posicion = this->pos();
    if (evento -> key() == Qt::Key_W){
        setY(y() - 4);
    }
    else if (evento -> key() == Qt::Key_A){
        setX(x() - 4);
    }
    else if (evento -> key() == Qt::Key_S){
        setY(y() + 4);
    }
    else if(evento -> key() == Qt::Key_D){
        setX(x() + 4);
    }
    qDebug() << posicion;
}

