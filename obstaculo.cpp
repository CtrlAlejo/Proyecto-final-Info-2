#include "obstaculo.h"
#include "qbrush.h"
#include "qpen.h"

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

Sierra::Sierra(int w, int h, QString file, QObject *parent) : Obstaculo(h,w,file,parent)
{

}

Pincho::Pincho(int w, int h, QString file, QObject *parent) : Obstaculo(h,w,file,parent)
{

}

void Pincho::keyPressEvent(QKeyEvent *evento)
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

Plataforma::Plataforma(int w, int h, QString file, QObject *parent) : Obstaculo(h,w,file,parent)
{

}

void Plataforma::keyPressEvent(QKeyEvent *evento)
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

QPointF Plataforma::get_posicion()
{
    return posicion;
}


Lago::Lago(int h, int w, QString file, QObject *parent) : Obstaculo(h,w,file,parent)
{

}

void Lago::keyPressEvent(QKeyEvent *evento)
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
