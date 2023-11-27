#include "morty.h"
#include "nivel1.h"
#include "obstaculo.h"
#include "nota.h"

extern Nivel1 * nivel1;

Morty::Morty(int w, int h, QString file, QObject *parent) : QObject(parent)
{
    detect_plataforma = false;
    alto = w;
    ancho = h;
    Vy = 0.0;
    gravedad = 0.0010;
    salto = -0.5;
    control_sprites = new QTimer(this);
    verif_plataforma = new QTimer(this);
    setPixmap(QPixmap(file).scaled(ancho,alto));
    connect(verif_plataforma, SIGNAL(timeout()), this, SLOT(deteccion_plataforma()));
    connect(control_sprites, SIGNAL(timeout()), this, SLOT(animacion_movimiento()));
    verif_plataforma -> start(1);
    control_sprites -> start(100);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    sprite = 1;
}

void Morty::verif_coordenadas()
{
    if (posicionMorty.x() >= 822 && (584 <= posicionMorty.y() && 680 >= posicionMorty.y())){
        setPos(822, posicionMorty.y());
    }
    else if (posicionMorty.x() <= 687 && (495 <= posicionMorty.y() && 590 >= posicionMorty.y())){
        setPos(687, posicionMorty.y());
    }
    else if (posicionMorty.x() <= 112 && (387 <= posicionMorty.y() && 450 >= posicionMorty.y())){
        setPos(112, posicionMorty.y());
    }
    else if (posicionMorty.x() >= 220 && (325 <= posicionMorty.y() && 420 >= posicionMorty.y())){
        setPos(220, posicionMorty.y());
    }
    else if ((posicionMorty.x() <= 1294 && posicionMorty.x() > 1185) && (86 <= posicionMorty.y() && 300 >= posicionMorty.y())){
        if (posicionMorty.x() < 1220){
            setPos(1185, posicionMorty.y());
        }
        else if (posicionMorty.x() >= 1192) {
            setPos(1294, posicionMorty.y());
        }
    }
    else if ((posicionMorty.x() > 1270 && posicionMorty.x() <= 1410) && (218 <= posicionMorty.y() && 250 >= posicionMorty.y())){
        setPos(1410, posicionMorty.y());
    }
    else if ((posicionMorty.x() > 1400 && posicionMorty.x() <= 1600) && (134 <= posicionMorty.y() && 206 >= posicionMorty.y())){
        setPos(1400, posicionMorty.y());
    }
    else if ((posicionMorty.x() <= 824 && posicionMorty.x() > 640) && (665 <= posicionMorty.y() && 740 >= posicionMorty.y())){
        if (posicionMorty.x() < 810){
            setPos(640, posicionMorty.y());
        }
        else if (posicionMorty.x() > 670) {
            setPos(824, posicionMorty.y());
        }
    }
}

void Morty::keyPressEvent(QKeyEvent *evento)
{
    if (evento->isAutoRepeat()) return;
    switch (evento -> key()){
    case Qt::Key_W:
        if (detect_plataforma) Vy = salto;
        break;
    case Qt::Key_A:
        Vx -= 0.4;
        modo = 1;
        break;
    case Qt::Key_D:
        Vx += 0.4;
        modo = 2;
        break;
    default:
        break;
    }
}

void Morty::keyReleaseEvent(QKeyEvent *evento)
{
    if (evento->isAutoRepeat()) return;
    switch (evento -> key()){
    case Qt::Key_A:
        Vx = 0;
        modo = 3;
        setPixmap(QPixmap(":/Mortys_Vindicator_Challenge/Sprites/morty_default_left.png").scaled(ancho,alto));
        break;
    case Qt::Key_D:
        Vx = 0;
        modo = 4;
        setPixmap(QPixmap(":/Mortys_Vindicator_Challenge/Sprites/morty_default_right.png").scaled(ancho,alto));
        break;
    default:
        break;
    }
}

void Morty::deteccion_plataforma()
{
    posicionMorty = this->pos();
    QList<QGraphicsItem *> collidingItems = this->collidingItems();
    for (QGraphicsItem *item : collidingItems) {
        if (dynamic_cast<Plataforma*>(item)) {
            detect_plataforma = true;
//            qDebug() << item -> pos();
//            qDebug() << "Posicion morty: " << posicionMorty;
            if (item -> pos().y() - 60 < posicionMorty.y()){
                Vy = 0.1;
                setPos(posicionMorty.x(), posicionMorty.y() + 1);
            }
            if (Vy > 0.0){
                Vy = 0.0;
            }

            break;
        }
        else if (dynamic_cast<Nota*>(item)){
            continue;
        }
        else if (dynamic_cast<Pincho*>(item)){
            continue;
        }
        else{
            detect_plataforma = false;
            Vy += gravedad;
            break;
        }
    }
    if (posicionMorty.x() <= 0){
        setPos(1,posicionMorty.y());
    }
    else if (posicionMorty.x() >= 1510){
        setPos(1510,posicionMorty.y());
    }
    verif_coordenadas();
    setPos(x() + Vx, y() + Vy);
    //qDebug() << posicionMorty;
}

void Morty::animacion_movimiento()
{
    if (modo == 1){
        if (sprite == 1){
            setPixmap(QPixmap(":/Mortys_Vindicator_Challenge/Sprites/morty_left_fase1.png").scaled(ancho,alto));
            sprite = 2;
        }
        else if (sprite == 2){
            setPixmap(QPixmap(":/Mortys_Vindicator_Challenge/Sprites/morty_left_fase2.png").scaled(ancho,alto));
            sprite = 1;
        }
    }
    else if (modo == 2){
        if (sprite == 1){
            setPixmap(QPixmap(":/Mortys_Vindicator_Challenge/Sprites/morty_right_fase1.png").scaled(ancho,alto));
            sprite = 2;
        }
        else if (sprite == 2){
            setPixmap(QPixmap(":/Mortys_Vindicator_Challenge/Sprites/morty_right_fase2.png").scaled(ancho,alto));
            sprite = 1;
        }
    }
    else if (modo == 3){
        setPixmap(QPixmap(":/Mortys_Vindicator_Challenge/Sprites/morty_default_left.png").scaled(ancho,alto));
    }
    else if (modo == 4){
        setPixmap(QPixmap(":/Mortys_Vindicator_Challenge/Sprites/morty_default_right.png").scaled(ancho,alto));
    }
}

