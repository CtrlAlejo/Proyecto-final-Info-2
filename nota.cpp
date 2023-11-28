#include "nota.h"

Nota::Nota(int w, int h, QString file, QString texto, QObject *parent) : QObject(parent)
{
    setPixmap(QPixmap(file).scaled(w,h));
    pista_vindicador = texto;
//    setFlag(QGraphicsItem::ItemIsFocusable);
//    setFocus();
}

void Nota::keyPressEvent(QKeyEvent *evento)
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

void Nota::mostrar_mensaje()
{

    mensaje = new QGraphicsTextItem(pista_vindicador);
    mensaje -> setPos(posicion.x() - 10, posicion.y()- 10);
}

void Nota::cambiar_visibilidad(int modo)
{
    if (modo == 1){
        visible = false;
    }
    else {
        visible = true;
    }
    setVisible(visible);
    mensaje -> setVisible(visible);
}

void Nota::verif_interaccion()
{
    QList<QGraphicsItem *> collidingItems = this->collidingItems();
    for (QGraphicsItem *item : collidingItems) {

    }
}
