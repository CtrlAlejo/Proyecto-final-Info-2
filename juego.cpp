#include "juego.h"

Juego::Juego()
{
    vidas = 3;
    menu = new Menu;
    menu -> setVisible(true);
    //nivel2 = new NIvel2;
    connect(menu, SIGNAL(iniciar()), this, SLOT(iniciar_nivel()));
    nivelActual = 1;
}

void Juego::iniciar_nivel()
{
    if (nivelActual == 1){
        nivel1 = new Nivel1(vidas);
        menu -> setVisible(false);
        connect(nivel1, SIGNAL(pasar_nivel()), this, SLOT(pasarAlSiguienteNivel()));
        nivel1 -> start();
        nivel1 -> setVisible(true);
    }
    else if (nivelActual == 2){
        //nivel2 -> show();
    }
    else if (nivelActual == 3){
        delete nivel1;
        nivel3 = new Nivel3;
        connect(nivel3, SIGNAL(nivel_completado()), this, SLOT(fin_del_juego()));
        nivel3 -> start();
        nivel3 -> setVisible(true);
    }
}

void Juego::pasarAlSiguienteNivel()
{
    nivelActual = 3;
    iniciar_nivel();
}

void Juego::reiniciarNivelActual()
{
    if (nivelActual == 1){
        delete nivel1;
    }
    else if (nivelActual == 2){
        delete nivel2;
    }
    else if (nivelActual == 3){
        delete nivel3;
    }
    iniciar_nivel();
    vidas--;
}
