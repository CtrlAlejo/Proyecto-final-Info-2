#include "imagen.h"

imagen::imagen(int _id, int w, int h, QString file, QObject *parent) : QObject(parent)
{
    id = _id;
    alto = h;
    ancho = w;
    setPixmap(QPixmap(file).scaled(alto, ancho));
//    setFlag(QGraphicsItem::ItemIsFocusable);
    //    setFocus();
}

int imagen::get_id()
{
    return id;
}
