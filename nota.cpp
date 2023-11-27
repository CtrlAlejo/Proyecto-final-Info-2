#include "nota.h"

Nota::Nota(int w, int h, QString file, QString texto, QObject *parent) : QObject(parent)
{
    setPixmap(QPixmap(file).scaled(w,h));
    pista_vindicador = texto;
}

void Nota::keyPressEvent(QKeyEvent *evento)
{
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
}
