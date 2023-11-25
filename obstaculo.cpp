#include "obstaculo.h"

Obstaculo::Obstaculo(int x, int y, int w, int h, QString file, QObject *parent) : QObject(parent)
{
    posX = x;
    posY = y;
    alto = h;
    ancho = w;
    setPixmap(QPixmap(file).scaled(alto, ancho));
}

Sierra::Sierra(int x, int y, int w, int h, QString file, QObject *parent) : Obstaculo(x,y,h,w,file,parent)
{

}

Pincho::Pincho(int x, int y, int w, int h, QString file, QObject *parent) : Obstaculo(x,y,h,w,file,parent)
{

}

void Pincho::keyPressEvent(QKeyEvent *evento)
{
    if (evento -> key() == Qt::Key_W){
        setY(y() - 4);
        posY -= 4;
    }
    else if (evento -> key() == Qt::Key_A){
        setX(x() - 4);
        posX -= 4;
    }
    else if (evento -> key() == Qt::Key_S){
        setY(y() + 4);
        posY += 4;
    }
    else if(evento -> key() == Qt::Key_D){
        setX(x() + 4);
        posX += 4;
    }
    qDebug() << "X: " << posX;
    qDebug() << "Y: " << posY;
}

Plataforma::Plataforma(int x, int y, int w, int h, QString file, QObject *parent) : Obstaculo(x,y,h,w,file,parent)
{

}

void Plataforma::keyPressEvent(QKeyEvent *evento)
{
    if (evento -> key() == Qt::Key_W){
        setY(y() - 4);
        posY -= 4;
    }
    else if (evento -> key() == Qt::Key_A){
        setX(x() - 4);
        posX -= 4;
    }
    else if (evento -> key() == Qt::Key_S){
        setY(y() + 4);
        posY += 4;
    }
    else if(evento -> key() == Qt::Key_D){
        setX(x() + 4);
        posX += 4;
    }
    qDebug() << "X: " << posX;
    qDebug() << "Y: " << posY;
}


Lago::Lago(int x, int y, int h, int w, QString file, QObject *parent) : Obstaculo(x,y,h,w,file,parent)
{

}

void Lago::keyPressEvent(QKeyEvent *evento)
{
    if (evento -> key() == Qt::Key_W){
        setY(y() - 4);
        posY -= 4;
    }
    else if (evento -> key() == Qt::Key_A){
        setX(x() - 4);
        posX -= 4;
    }
    else if (evento -> key() == Qt::Key_S){
        setY(y() + 4);
        posY += 4;
    }
    else if(evento -> key() == Qt::Key_D){
        setX(x() + 4);
        posX += 4;
    }
    qDebug() << "X: " << posX;
    qDebug() << "Y: " << posY;
}
