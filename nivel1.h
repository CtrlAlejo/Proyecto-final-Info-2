#ifndef NIVEL1_H
#define NIVEL1_H

#include "morty.h"
#include "nota.h"
#include "obstaculo.h"
#include <QObject>
#include <QGraphicsView>
#include "imagen.h"
#include "pizarra.h"

class Nivel1 : public QGraphicsView
{
    Q_OBJECT
public:
    Nivel1(QWidget *parent = NULL);
    void start();
    void primer_piso();
    void segundo_piso();
    void tercer_piso();
    void cuarto_piso();
    void mini_seccion();
    void detectar_plataformas();
    void poner_base();
    void spawn_morty();
    void poner_imagenes();
    void poner_sierras();
private:
    QGraphicsScene *nivel1;
    bool check_plataforma;
    QGraphicsPixmapItem *fondo;
    Morty *morty;
    Plataforma *base;
    Plataforma *plataforma;
    Plataforma *plataforma2;
    Plataforma *plataforma3;
    Plataforma *plataforma3_5;
    Plataforma *plataforma4;
    Pincho *pincho;
    Pincho *pincho4;
    Pincho *pincho5;
    Lago *lago_toxico;
    Lago *lago_toxico2;
    Lago *lago_toxico3;
    Plataforma *plataforma_flotante;
    Plataforma *plataforma_flotante2;
    Plataforma *min_plat1;
    Plataforma *min_plat2;
    Plataforma *min_plat_aux1;
    Plataforma *min_plat_aux2;
    Sierra *sierra;
    Nota *million_ants;
    Nota *alan_rails;
    Nota *crocubot;
    Nota *supernova;
    Nota *vance_maximus;
    Pizarra *vindicadores;
    imagen *millionAnts;
    imagen *super_nova;
    imagen *robodrilo;
    imagen *alanrails;
    imagen *vance;
    Sierra *sierra1_1;
    Sierra *sierra1_2;
    Sierra *sierra1_3;
    Sierra *sierra2_1;
};
#endif // NIVEL1_H
