#include "nivel3.h"

Nivel3::Nivel3(QWidget *parent) : QGraphicsView(parent)
{
    nivel3 = new QGraphicsScene;
    setFixedSize(1600,900);
    setScene(nivel3);
    fondo = new QGraphicsPixmapItem(QPixmap(":/Mortys_Vindicator_Challenge/Sprites/Fondo nivel1.jpg").scaled(1600,900));
    nivel3 -> addItem(fondo);
}

void Nivel3::start()
{
    base = new Plataforma(1600, 50, ":/Mortys_Vindicator_Challenge/Sprites/Plataforma_default.png");
    base -> setPos(0, 870);
    nivel3 -> addItem(base);
    morty2 = new Morty_Armado;
    morty2 -> setPos(0,500);
    nivel3 -> addItem(morty2);
    supernova = new Jefe(nivel3, 180, 180, ":/Mortys_Vindicator_Challenge/Sprites/supernova_boss_left.png");
    supernova -> setPos(1200, 600);
    nivel3 -> addItem(supernova);
    QObject::connect(morty2, &Morty_Armado::enviar_posicion, supernova, &Jefe::tomar_posicion_morty);
}
