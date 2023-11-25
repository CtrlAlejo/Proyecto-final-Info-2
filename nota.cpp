#include "nota.h"

Nota::Nota(int x, int y, int w, int h, QString file, QString texto, QObject *parent) : QObject(parent)
{
    posX = x;
    posY = y;
    setPixmap(QPixmap(file).scaled(w,h));
    pista_vindicador = texto;
}

void Nota::keyPressEvent(QKeyEvent *evento)
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
