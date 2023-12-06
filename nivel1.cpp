#include "nivel1.h"

Nivel1::Nivel1(int _vidas, QWidget *parent) : QGraphicsView (parent)
{
    vidas = _vidas;
    id_nivel = 1;
    idNivel = new QGraphicsTextItem;
    idNivel -> setFont(QFont("Arial", 22));
    idNivel -> setDefaultTextColor(Qt::white);
    tiempo = new QGraphicsTextItem;
    tiempo -> setFont(QFont("Arial", 22));
    tiempo -> setDefaultTextColor(Qt::white);
    tiempo_restante = 3 * 60 * 1000;
    connect(&timer, SIGNAL(timeout()), this, SLOT(actualizar_tiempo()));
    nivel1 = new QGraphicsScene;
    setFixedSize(1600,900);
    vindicadores = new Pizarra(406,100);
    fondo = new QGraphicsPixmapItem(QPixmap(":/Mortys_Vindicator_Challenge/Sprites/Fondo nivel1.jpg").scaled(1600,900));
    connect(vindicadores, SIGNAL(nivel_completado()), this, SLOT(terminar_nivel()));
    nivel1 -> addItem(fondo);
    setScene(nivel1);
    timer.start(1000);
}

void Nivel1::start()
{ //Pone todos los elementos en la escena que corresponden al nivel 1
    tiempo -> setPos(20, 20);
    nivel1 -> addItem(tiempo);
    idNivel -> setPos(750, 20);
    idNivel -> setPlainText("Nivel: " + QString::number(id_nivel));
    nivel1 -> addItem(idNivel);
    primer_piso();
    segundo_piso();
    tercer_piso();
    cuarto_piso();
    mini_seccion();
    poner_base();
    spawn_morty();
    poner_imagenes();
    poner_sierras();
}

void Nivel1::primer_piso()
{
    plataforma = new Plataforma(700,40,":/Mortys_Vindicator_Challenge/Sprites/plataforma_tipo1.png");
    plataforma -> setPos(900,670);
    nivel1 -> addItem(plataforma);
    lago_toxico = new Lago(48,411,":/Mortys_Vindicator_Challenge/Sprites/Lago toxico.png");
    lago_toxico -> setPos(1044,658);
    lago_toxico -> setZValue(1);
    nivel1 -> addItem(lago_toxico);
    plataforma_flotante = new Plataforma(210,35,":/Mortys_Vindicator_Challenge/Sprites/plataforma_2.png");
    plataforma_flotante -> setPos(1144,660);
    nivel1 -> addItem(plataforma_flotante);
    million_ants = new Nota(1, 1500,610, 55,60,":/Mortys_Vindicator_Challenge/Sprites/hoja.png","Parece como si estuviera hecho de tierra");
    million_ants -> setPos(1500,610);
    nivel1 -> addItem(million_ants);
}

void Nivel1::segundo_piso()
{
    plataforma2 = new Plataforma(700, 40, ":/Mortys_Vindicator_Challenge/Sprites/Plataforma_default.png");
    plataforma2 -> setPos(0, 580);
    nivel1 -> addItem(plataforma2);
    pincho = new Pincho(41, 41, ":/Mortys_Vindicator_Challenge/Sprites/spikes.png");
    pincho -> setPos(392,540);
    nivel1 -> addItem(pincho);
    supernova = new Nota(2, 32, 520, 55, 60, ":/Mortys_Vindicator_Challenge/Sprites/hoja.png", "Es un elemento cosmico");
    supernova -> setPos(32, 520);
    nivel1 -> addItem(supernova);
}

void Nivel1::tercer_piso()
{
    plataforma3 = new Plataforma(1300,40, ":/Mortys_Vindicator_Challenge/Sprites/Plataforma_default.png");
    plataforma3 -> setPos(300,410);
    nivel1 -> addItem(plataforma3);
    crocubot = new Nota(3, 1500, 350, 55, 60, ":/Mortys_Vindicator_Challenge/Sprites/hoja.png", "Es un reptil, pero con partes roboticas");
    crocubot -> setPos(1500, 350);
    nivel1 -> addItem(crocubot);
}

void Nivel1::cuarto_piso()
{
    plataforma4 = new Plataforma(1302, 40, ":/Mortys_Vindicator_Challenge/Sprites/plataforma_tipo1.png");
    plataforma4 -> setPos(0,172);
    plataforma4 -> setZValue(2);
    nivel1 -> addItem(plataforma4);
    plataforma_flotante2 = new Plataforma(350, 30, ":/Mortys_Vindicator_Challenge/Sprites/plataforma_2.png");
    plataforma_flotante2 -> setZValue(0);
    plataforma_flotante2 -> setPos(472, 164);
    nivel1 -> addItem(plataforma_flotante2);
    lago_toxico2 = new Lago(48, 411, ":/Mortys_Vindicator_Challenge/Sprites/Lago toxico.png");
    lago_toxico2 -> setPos(224,160);
    plataforma4 -> setZValue(1);
    nivel1 -> addItem(lago_toxico2);
    lago_toxico3 = new Lago(48, 411, ":/Mortys_Vindicator_Challenge/Sprites/Lago toxico.png");
    lago_toxico3 -> setPos(632,160);
    plataforma4 -> setZValue(1);
    nivel1 -> addItem(lago_toxico3);
    pincho4 = new Pincho(41, 41, ":/Mortys_Vindicator_Challenge/Sprites/spikes.png");
    pincho4 -> setPos(604, 124);
    nivel1 -> addItem(pincho4);
    pincho5 = new Pincho(41, 41, ":/Mortys_Vindicator_Challenge/Sprites/spikes.png");
    pincho5 -> setPos(645, 124);
    nivel1 -> addItem(pincho5);
    alan_rails = new Nota(5, 28, 115, 55, 60, ":/Mortys_Vindicator_Challenge/Sprites/hoja.png", "Su poder se basa en usar trenes ._.");
    alan_rails -> setPos(28, 115);
    nivel1 ->  addItem(alan_rails);
}

void Nivel1::mini_seccion()
{
    plataforma3_5 = new Plataforma(40, 160, ":/Mortys_Vindicator_Challenge/Sprites/Plataforma_rotada_90.png");
    plataforma3_5 -> setPos(1264,172);
    nivel1 -> addItem(plataforma3_5);
    min_plat1 = new Plataforma(122, 30, ":/Mortys_Vindicator_Challenge/Sprites/plataforma_2.png");
    min_plat1 -> setPos(1300, 304);
    nivel1 -> addItem(min_plat1);
    min_plat2 = new Plataforma(122, 30, ":/Mortys_Vindicator_Challenge/Sprites/plataforma_2.png");
    min_plat2 -> setPos(1476, 220);
    nivel1 -> addItem(min_plat2);
}

void Nivel1::poner_base()
{
    base = new Plataforma(1600, 50, ":/Mortys_Vindicator_Challenge/Sprites/Plataforma_default.png");
    base ->  setPos(0,870);
    nivel1 -> addItem(base);
    min_plat_aux1 = new Plataforma(122,30, ":/Mortys_Vindicator_Challenge/Sprites/plataforma_2.png");
    min_plat_aux1 -> setPos(716, 752);
    nivel1 -> addItem(min_plat_aux1);
    min_plat_aux2 = new Plataforma(122,30, ":/Mortys_Vindicator_Challenge/Sprites/plataforma_2.png");
    min_plat_aux2 -> setPos(4, 472);
    nivel1 -> addItem(min_plat_aux2);
}

void Nivel1::spawn_morty()
{
    vindicadores -> setPos(900,770);
    nivel1 -> addItem(vindicadores);
    morty = new Morty(vindicadores, 90, 90, ":/Mortys_Vindicator_Challenge/Sprites/morty_default_right.png");
    morty -> setPos(1,600);
    morty -> setZValue(1);
    nivel1 -> addItem(morty);
}

void Nivel1::poner_imagenes()
{
    millionAnts = new imagen(1, 70, 70, ":/Mortys_Vindicator_Challenge/Sprites/million ants.png");
    millionAnts -> setPos(908, 796);
    nivel1 -> addItem(millionAnts);
    super_nova = new imagen(2, 70,70, ":/Mortys_Vindicator_Challenge/Sprites/supernova.png");
    super_nova -> setPos(988, 796);
    nivel1 -> addItem(super_nova);
    robodrilo = new imagen(3, 70,70, ":/Mortys_Vindicator_Challenge/Sprites/crocubot.png");
    robodrilo -> setPos(1068, 796);
    nivel1 -> addItem(robodrilo);
    vance = new imagen(4, 70, 70, ":/Mortys_Vindicator_Challenge/Sprites/vance maximus.png");
    vance -> setPos(1148, 796);
    nivel1 -> addItem(vance);
    alanrails = new imagen(5, 70, 70, ":/Mortys_Vindicator_Challenge/Sprites/alan rieles.png");
    alanrails -> setPos(1228, 796);
    nivel1 -> addItem(alanrails);
    vance_maximus = new Nota(4, 908, 610, 55,60,":/Mortys_Vindicator_Challenge/Sprites/hoja.png","El tipo literalmente se cree Starlord");
    vance_maximus -> setPos(908, 610);
    nivel1 -> addItem(vance_maximus);
}

void Nivel1::poner_sierras()
{
    sierra1_1 = new Sierra(1, 50,50, ":/Mortys_Vindicator_Challenge/Sprites/sierra.png");
    sierra1_1 -> setPos(512, 320);
    nivel1 -> addItem(sierra1_1);
    sierra1_2 = new Sierra(1, 50,50, ":/Mortys_Vindicator_Challenge/Sprites/sierra.png");
    sierra1_2 -> setPos(692, 320);
    nivel1 -> addItem(sierra1_2);
    sierra1_3 = new Sierra(1, 50,50, ":/Mortys_Vindicator_Challenge/Sprites/sierra.png");
    sierra1_3 -> setPos(862, 320);
    nivel1 -> addItem(sierra1_3);
    sierra2_1 = new Sierra(2, 50,50, ":/Mortys_Vindicator_Challenge/Sprites/sierra.png");
    sierra2_1 -> setPos(1424, 348);
    nivel1 -> addItem(sierra2_1);
}

void Nivel1::actualizar_tiempo()
{
    tiempo_restante -= 1000; // Reduce el tiempo en 1 segundo

    // Obtiene los minutos y segundos restantes
    int minutesRemaining = tiempo_restante / 60000;
    int secondsRemaining = (tiempo_restante % 60000) / 1000;

    // Actualiza el texto del QGraphicsTextItem
    tiempo -> setPlainText(QString::number(minutesRemaining) + ":" + QString::number(secondsRemaining));

    // Si el tiempo restante es 0, finaliza el timer
    if (tiempo_restante <= 0) {
        timer.stop();
    }
}

void Nivel1::terminar_nivel()
{
    emit pasar_nivel();
}
