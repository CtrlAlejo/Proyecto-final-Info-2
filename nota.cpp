#include "nota.h"
#include "morty.h"

Nota::Nota(int _id, int _posX, int _posY, int w, int h, QString file, QString texto, QObject *parent) : QObject(parent)
{
    id = _id;
    posX = _posX;
    posY = _posY;
    setPixmap(QPixmap(file).scaled(w,h));
    pista_vindicador = texto;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(verif_interaccion()));
    timer -> start(100);
    mensaje = new QGraphicsTextItem(pista_vindicador, this);
    mensaje -> setDefaultTextColor(Qt::white);
    mensaje -> setFont(QFont("Arial", 12));
    mensaje -> setVisible(false);
    poner_mensaje();
    act_mensaje = true;
//    setFlag(QGraphicsItem::ItemIsFocusable);
//    setFocus();
}

void Nota::poner_mensaje()
{
    if (posX < 800){
        mensaje -> setPos(x() + 70, y() + 20);
    }
    else if (posX >= 800){
        mensaje -> setPos(x() - 300, y() + 20);
    }
}

int Nota::get_id()
{
    return id;
}

void Nota::verif_interaccion() //Cuando Morty este sobre una nota, la nota mostrara el mensaje correspondiente al Vindicador
{
    bool colisionConMorty;
    if (act_mensaje){
        QList<QGraphicsItem *> collidingItems = this->collidingItems();
        colisionConMorty = false;
        for (QGraphicsItem *item : collidingItems) {
            if (dynamic_cast<Morty*>(item)){
                colisionConMorty = true;
                break;
            }
        }
        mensaje->setVisible(colisionConMorty);
    }
    else {
        colisionConMorty = false;
        mensaje->setVisible(colisionConMorty);
    }
}
