#include "nota.h"
#include "morty.h"

Nota::Nota(int w, int h, QString file, QString texto, QObject *parent) : QObject(parent)
{
    setPixmap(QPixmap(file).scaled(w,h));
    pista_vindicador = texto;
    timer = new QTimer(this);
    mensaje = new QGraphicsTextItem(pista_vindicador, this);
    connect(timer, SIGNAL(timeout()), this, SLOT(verif_interaccion()));
    timer -> start(50);
    mensaje -> setPos(posicion.x() - 10, posicion.y()- 10);
    visible = false;
//    scene() -> addItem(mensaje);
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

void Nota::cambiar_visibilidad(int modo)
{
}

void Nota::verif_interaccion()
{
    QList<QGraphicsItem *> collidingItems = this->collidingItems();
    for (QGraphicsItem *item : collidingItems) {
        if (dynamic_cast<Morty*>(item)){
            qDebug() << "MIerDAAAAA";
            mensaje -> setVisible(true);
        }
        else {
            qDebug() << "sebolla";
            mensaje -> setVisible(false);
        }
    }
}
