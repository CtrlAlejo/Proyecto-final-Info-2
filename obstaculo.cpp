#include "obstaculo.h"

Obstaculo::Obstaculo()
{

}

Obstaculo::Obstaculo(int w, int h, QString file, QObject *parent) : QObject(parent)
{
    alto = h;
    ancho = w;
    setPixmap(QPixmap(file).scaled(alto, ancho));
    posicion = this -> pos();
}

Sierra::Sierra(int tipo_mov, int w, int h, QString file, QObject *parent) : Obstaculo(h,w,file,parent)
{
    alternador_mov = true;
    tipo_movimiento = tipo_mov;
    control_mov = new QTimer(this);
    connect(control_mov, SIGNAL(timeout()), this, SLOT(movimiento_sierra()));
    control_mov -> start(16);
}

void Sierra::movimiento_sierra() //Mueve la sierra de dos formas por algunas partes del nivel
{
    if (tipo_movimiento == 1){
        posicion = this->pos();
        if (posicion.y() == 320){
            setX(x() + 2);
            posicion = this->pos();
        }
        if (posicion.x() == 1150){
            setY(y() - 2);
            posicion = this->pos();
        }
        if (posicion.y() == 228){
            setX(x() - 2);
            posicion = this->pos();
        }
        if (posicion.x() == 512){
            setY(y() + 2);
            posicion = this->pos();
        }
    }
    else{
        posicion = this->pos();
        if (posicion.y() == 150){
            alternador_mov = false;
        }
        else if (posicion.y() == 348){
            alternador_mov = true;
        }
        if (alternador_mov){
            setY(y() - 2);
        }
        else{
            setY(y() + 2);
        }
    }
}

Pincho::Pincho(int w, int h, QString file, QObject *parent) : Obstaculo(h,w,file,parent)
{

}

Plataforma::Plataforma(int w, int h, QString file, QObject *parent) : Obstaculo(h,w,file,parent)
{

}

QPointF Plataforma::get_posicion()
{
    return posicion;
}


Lago::Lago(int h, int w, QString file, QObject *parent) : Obstaculo(h,w,file,parent)
{

}
