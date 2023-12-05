#include "bola.h"

Bola::Bola(int w, int h, QString file, QObject *parent) : QObject (parent)
{
    alto = h;
    ancho = w;
    setPixmap(QPixmap(file).scaled(ancho, alto));
}
