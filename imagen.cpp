#include "imagen.h"

imagen::imagen(int w, int h, QString file, QObject *parent) : QObject(parent)
{
    alto = h;
    ancho = w;
    setPixmap(QPixmap(file).scaled(alto, ancho));
//    setFlag(QGraphicsItem::ItemIsFocusable);
//    setFocus();
}

void imagen::keyPressEvent(QKeyEvent *evento)
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
