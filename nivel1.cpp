#include "nivel1.h"

Nivel1::Nivel1(QWidget *parent) : QGraphicsView (parent)
{
    nivel1 = new QGraphicsScene;
    setFixedSize(1600,900);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(nivel1);
    fondo = new QGraphicsPixmapItem(QPixmap(":/Mortys_Vindicator_Challenge/Sprites/Fondo nivel1.jpg").scaled(1600,900));
    nivel1 -> addItem(fondo);
    start();
}

void Nivel1::start()
{
    primer_piso();
    segundo_piso();
    tercer_piso();
    cuarto_piso();
    mini_seccion();
    poner_base();
}

void Nivel1::primer_piso()
{

    plataforma = new Plataforma(900,670,700,40,":/Mortys_Vindicator_Challenge/Sprites/plataforma_tipo1.png");
    plataforma -> setPos(900,670);
    nivel1 -> addItem(plataforma);
    lago_toxico = new Lago(1044,658,48,411,":/Mortys_Vindicator_Challenge/Sprites/Lago toxico.png");
    lago_toxico -> setPos(1044,658);
    lago_toxico -> setZValue(1);
    nivel1 -> addItem(lago_toxico);
    plataforma_flotante = new Plataforma(1144,660,210,35,":/Mortys_Vindicator_Challenge/Sprites/plataforma_2.png");
    plataforma_flotante -> setPos(1144,660);
    nivel1 -> addItem(plataforma_flotante);
    million_ants = new Nota(1500,610,55,60,":/Mortys_Vindicator_Challenge/Sprites/hoja.png","Parece como si estuviera hecho de tierra");
    million_ants -> setPos(1500,610);
    nivel1 -> addItem(million_ants);
}

void Nivel1::segundo_piso()
{
    plataforma2 = new Plataforma(0, 580, 700, 40, ":/Mortys_Vindicator_Challenge/Sprites/Plataforma_default.png");
    plataforma2 -> setPos(0, 580);
    nivel1 -> addItem(plataforma2);
    pincho = new Pincho(392, 540, 41, 41, ":/Mortys_Vindicator_Challenge/Sprites/spikes.png");
    pincho -> setPos(392,540);
    nivel1 -> addItem(pincho);
    pincho2 = new Pincho(352, 540, 41, 41, ":/Mortys_Vindicator_Challenge/Sprites/spikes.png");
    pincho2 -> setPos(352,540);
    nivel1 -> addItem(pincho2);
    pincho3 = new Pincho(312, 540, 41, 41, ":/Mortys_Vindicator_Challenge/Sprites/spikes.png");
    pincho3 -> setPos(312, 540);
    nivel1 -> addItem(pincho3);
    supernova = new Nota(32, 520, 55, 60, ":/Mortys_Vindicator_Challenge/Sprites/hoja.png", "Es un elemento cosmico");
    supernova -> setPos(32, 520);
    nivel1 -> addItem(supernova);
}

void Nivel1::tercer_piso()
{
    plataforma3 = new Plataforma(300,410,1300,40, ":/Mortys_Vindicator_Challenge/Sprites/Plataforma_default.png");
    plataforma3 -> setPos(300,410);
    nivel1 -> addItem(plataforma3);
    crocubot = new Nota(1500, 350, 55, 60, ":/Mortys_Vindicator_Challenge/Sprites/hoja.png", "Es un elemento cosmico");
    crocubot -> setPos(1500, 350);
    nivel1 -> addItem(crocubot);
}

void Nivel1::cuarto_piso()
{
    plataforma4 = new Plataforma(0, 172, 1302, 40, ":/Mortys_Vindicator_Challenge/Sprites/plataforma_tipo1.png");
    plataforma4 -> setPos(0,172);
    plataforma4 -> setZValue(2);
    nivel1 -> addItem(plataforma4);
    plataforma_flotante2 = new Plataforma(472, 164, 350, 30, ":/Mortys_Vindicator_Challenge/Sprites/plataforma_2.png");
    plataforma_flotante2 -> setZValue(0);
    plataforma_flotante2 -> setPos(472, 164);
    nivel1 -> addItem(plataforma_flotante2);
    lago_toxico2 = new Lago(224, 160, 48, 411, ":/Mortys_Vindicator_Challenge/Sprites/Lago toxico.png");
    lago_toxico2 -> setPos(224,160);
    plataforma4 -> setZValue(1);
    nivel1 -> addItem(lago_toxico2);
    lago_toxico3 = new Lago(632, 160, 48, 411, ":/Mortys_Vindicator_Challenge/Sprites/Lago toxico.png");
    lago_toxico3 -> setPos(632,160);
    plataforma4 -> setZValue(1);
    nivel1 -> addItem(lago_toxico3);
    pincho4 = new Pincho(604, 124, 41, 41, ":/Mortys_Vindicator_Challenge/Sprites/spikes.png");
    pincho4 -> setPos(604, 124);
    nivel1 -> addItem(pincho4);
    pincho5 = new Pincho(645, 124, 41, 41, ":/Mortys_Vindicator_Challenge/Sprites/spikes.png");
    pincho5 -> setPos(645, 124);
    nivel1 -> addItem(pincho5);
    alan_rails = new Nota(28, 116, 55, 60, ":/Mortys_Vindicator_Challenge/Sprites/hoja.png", "Su poder se basa en usar trenes ._.");
    alan_rails -> setPos(28, 115);
    nivel1 ->  addItem(alan_rails);
}

void Nivel1::mini_seccion()
{
    plataforma3_5 = new Plataforma(1264,172,40,160, ":/Mortys_Vindicator_Challenge/Sprites/Plataforma_rotada_90.png");
    plataforma3_5 -> setPos(1264,172);
    nivel1 -> addItem(plataforma3_5);
    min_plat1 = new Plataforma(1300, 304, 122, 30, ":/Mortys_Vindicator_Challenge/Sprites/plataforma_2.png");
    min_plat1 -> setPos(1300, 304);
    nivel1 -> addItem(min_plat1);
    min_plat2 = new Plataforma(1476, 220, 122, 30, ":/Mortys_Vindicator_Challenge/Sprites/plataforma_2.png");
    min_plat2 -> setPos(1476, 220);
    nivel1 -> addItem(min_plat2);
}

void Nivel1::detectar_plataformas()
{
    QList<QGraphicsItem *> collidingItems = morty -> collidingItems();
    for (QGraphicsItem *item : collidingItems) {
        if (dynamic_cast<Plataforma*>(item)) {
            check_plataforma = true;
            break;
        }
    }
    morty -> establecerSobrePlataforma(check_plataforma);
}

void Nivel1::poner_base()
{
    base = new Plataforma(0, 870, 1600, 50, ":/Mortys_Vindicator_Challenge/Sprites/Plataforma_default.png");
    base ->  setPos(0,870);
    nivel1 -> addItem(base);
}

void Nivel1::spawn_morty()
{
    morty = new Morty(0, 820, 40, 40, ":/Mortys_Vindicator_Challenge/Sprites/morty_default_left.png");
    morty -> setPos(0,820);
    nivel1 -> addItem(morty);
}
