#include "plasma.h"
#include "morty_armado.h"

Plasma::Plasma(int tipo_desplazamiento, int Xo, int w, int h) : Bala(tipo_desplazamiento, Xo, w, h)
{
    plasma_fase1 = ":/Mortys_Vindicator_Challenge/Sprites/proyectil jefe_fase1.png";
    plasma_fase2 = ":/Mortys_Vindicator_Challenge/Sprites/proyectil jefe_fase2.png";
    plasma_fase3 = ":/Mortys_Vindicator_Challenge/Sprites/proyectil jefe_fase3.png";
    plasma_fase4 = ":/Mortys_Vindicator_Challenge/Sprites/proyectil jefe_fase4.png";
    plasma_fase5 = ":/Mortys_Vindicator_Challenge/Sprites/proyectil jefe_fase5.png";
    plasma_fase6 = ":/Mortys_Vindicator_Challenge/Sprites/proyectil jefe_fase6.png";
    plasma_fase7 = ":/Mortys_Vindicator_Challenge/Sprites/proyectil jefe_fase7.png";
    plasma_fase8 = ":/Mortys_Vindicator_Challenge/Sprites/proyectil jefe_fase8.png";
    fase_mov = 1;
    Vx = 7;
}

void Plasma::verificar_colisiones()
{
    QList<QGraphicsItem *> collidingItems = this -> collidingItems();
    for (QGraphicsItem *item : collidingItems) {
        if (Morty_Armado *morty = dynamic_cast<Morty_Armado*>(item)) {
            morty -> cambiar_estado();
            break;
        }
    }
}

void Plasma::desplazamiento_bala()
{
    verificar_colisiones();
    posicion = this -> pos();
    if (dir_desplazamiento == 2 || dir_desplazamiento == 4){
        desplazamiento_tipo1();
        X = X + Vx;
    }
    else if (dir_desplazamiento == 1 || dir_desplazamiento == 3){
        desplazamiento_tipo2();
        X = X - Vx;
    }
    setX(X);

    if (posicion.x() <= 0 || posicion.x() >= 1570){
        timer -> stop();
        delete this;
    }
}

void Plasma::desplazamiento_tipo1()
{
    if (fase_mov == 1){
        setPixmap(QPixmap(plasma_fase1).scaled(ancho, alto));
        fase_mov = 2;
    }
    else if (fase_mov == 2){
        setPixmap(QPixmap(plasma_fase2).scaled(ancho, alto));
        fase_mov = 3;
    }
    else if (fase_mov == 3){
        setPixmap(QPixmap(plasma_fase3).scaled(ancho, alto));
        fase_mov = 4;
    }
    else if (fase_mov == 4){
        setPixmap(QPixmap(plasma_fase4).scaled(ancho, alto));
        fase_mov = 5;
    }
    else if (fase_mov == 5){
        setPixmap(QPixmap(plasma_fase5).scaled(ancho, alto));
        fase_mov = 6;
    }
    else if (fase_mov == 6){
        setPixmap(QPixmap(plasma_fase6).scaled(ancho, alto));
        fase_mov = 7;
    }
    else if (fase_mov == 7){
        setPixmap(QPixmap(plasma_fase7).scaled(ancho, alto));
        fase_mov = 8;
    }
    else if (fase_mov == 8){
        setPixmap(QPixmap(plasma_fase8).scaled(ancho, alto));
        fase_mov = 1;
    }
}

void Plasma::desplazamiento_tipo2()
{
    if (fase_mov == 1){
        setPixmap(QPixmap(plasma_fase8).scaled(ancho, alto));
        fase_mov = 2;
    }
    else if (fase_mov == 2){
        setPixmap(QPixmap(plasma_fase7).scaled(ancho, alto));
        fase_mov = 3;
    }
    else if (fase_mov == 3){
        setPixmap(QPixmap(plasma_fase6).scaled(ancho, alto));
        fase_mov = 4;
    }
    else if (fase_mov == 4){
        setPixmap(QPixmap(plasma_fase5).scaled(ancho, alto));
        fase_mov = 5;
    }
    else if (fase_mov == 5){
        setPixmap(QPixmap(plasma_fase4).scaled(ancho, alto));
        fase_mov = 6;
    }
    else if (fase_mov == 6){
        setPixmap(QPixmap(plasma_fase3).scaled(ancho, alto));
        fase_mov = 7;
    }
    else if (fase_mov == 7){
        setPixmap(QPixmap(plasma_fase2).scaled(ancho, alto));
        fase_mov = 8;
    }
    else if (fase_mov == 8){
        setPixmap(QPixmap(plasma_fase1).scaled(ancho, alto));
        fase_mov = 1;
    }
}


