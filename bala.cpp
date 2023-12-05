#include "bala.h"
#include "jefe.h"

Bala::Bala(int tipo_desplazamiento, int Xo, int w, int h, QObject *parent) : QObject(parent)
{
    alto = h;
    ancho = w;
    Vx = 9;
    f_bala_izquierda = ":/Mortys_Vindicator_Challenge/Sprites/bala_left.png";
    f_bala_derecha = ":/Mortys_Vindicator_Challenge/Sprites/bala_right.png";
    f_bala_derecha_dañada = ":/Mortys_Vindicator_Challenge/Sprites/bala dañada_left.png";
    //f_bala_izquierda_dañada = ":/Mortys_Vindicator_Challenge/Sprites/bala dañada_right.png";
    if (tipo_desplazamiento == 1 || tipo_desplazamiento == 3){
        X = Xo - 5;
    }
    else if (tipo_desplazamiento == 2 || tipo_desplazamiento == 4){
        X = Xo + 80;
    }
    dir_desplazamiento = tipo_desplazamiento;
    timer = new QTimer (this);
    connect(timer, SIGNAL(timeout()), this, SLOT(desplazamiento_bala()));
    timer -> start(1000/60);
}

void Bala::verificar_colisiones()
{
    QList<QGraphicsItem *> collidingItems = this->collidingItems();
    for (QGraphicsItem *item : collidingItems) {
        if (Jefe *jefe = dynamic_cast<Jefe*>(item)) {
            jefe -> disminuir_vida();
            timer -> stop();
            scene() -> removeItem(this);
            break;
        }
        /*
        else if(QGraphicsPixmapItem *bola = dynamic_cast<QGraphicsPixmapItem*>(item)){
            timer -> stop();
            scene() -> removeItem(this);
            break;
        }
*/
    }
}

void Bala::desplazamiento_bala()
{
    verificar_colisiones();
    posicion = this -> pos();
    if (dir_desplazamiento == 2 || dir_desplazamiento == 4){
        X = X + Vx;
        setPixmap(QPixmap(f_bala_derecha).scaled(ancho, alto));
    }
    else if (dir_desplazamiento == 1 || dir_desplazamiento == 3) {
        X = X - Vx;
        setPixmap(QPixmap(f_bala_izquierda).scaled(ancho, alto));
    }
    setX(X);
    if (posicion.x() <= 0 || posicion.x() >= 1570){
        timer -> stop();
        delete timer;
        delete this;
        return;
    }
}
