#include "rombos.h"

rombos::rombos()
{

}

rombos::rombos(int w, int h, QString file, QObject *parent) : QObject(parent)
{
    alto = h;
    ancho = w;
    setPixmap(QPixmap(file).scaled(alto, ancho));

    posicion = this -> pos();
}
