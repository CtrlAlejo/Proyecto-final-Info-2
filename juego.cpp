#include "juego.h"
#include "nivel1.h"
#include "nivel2.h"
#include "nivel3.h"
#include <QApplication>

Juego::Juego()
{
    vidas = 3;
    //menu.setVisible(true);
    //nivel2 = new NIvel2;
    //connect(&menu, SIGNAL(iniciar()), this, SLOT(iniciar_nivel()));
    nivelActual = 1;
    iniciar_nivel();
}

void Juego::iniciar_nivel()
{
    //menu.hide();
    if (nivelActual == 1){
        Nivel1 * nivel1 = new Nivel1(vidas);
        connect(nivel1, SIGNAL(pasar_nivel()), this, SLOT(pasarAlSiguienteNivel()));
        connect(nivel1, SIGNAL(reiniciar_nivel()), this, SLOT(reiniciarNivelActual()));
        nivel1 -> start();
        nivel1 -> setVisible(true);
    }
    else if (nivelActual == 2){
        NIvel2 * nivel2 = new NIvel2(vidas);
        connect(nivel2, SIGNAL(secuencia_terminada()), this, SLOT(pasarAlSiguienteNivel()));
        connect(nivel2, SIGNAL(reiniciar_nivel()), this, SLOT(reiniciarNivelActual()));
        nivel2 -> setVisible(true);
    }
    else if (nivelActual == 3){
        Nivel3 * nivel3 = new Nivel3;
        connect(nivel3, SIGNAL(nivel_completado()), this, SLOT(fin_del_juego()));
        nivel3 -> show();
    }
}

void Juego::pasarAlSiguienteNivel()
{
    nivelActual++;
    if (nivelActual > 3){
        qApp -> exit();
    }
    iniciar_nivel();
}

void Juego::reiniciarNivelActual()
{
    vidas--;
    if (vidas < 0){
        qApp -> exit();
    }
    iniciar_nivel();
}
