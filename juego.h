#ifndef JUEGO_H
#define JUEGO_H

#include <QObject>
#include "menu.h"
#include "nivel1.h"
#include "nivel2.h"
#include "nivel3.h"

class Juego : public QObject
{
    Q_OBJECT
public:
    Juego();
public slots:
    void iniciar_nivel();
    void pasarAlSiguienteNivel();
    void reiniciarNivelActual();
private:
    Nivel1 * nivel1;
    NIvel2 * nivel2;
    Nivel3 * nivel3;
    int vidas;
    int nivelActual;
    int tiempo_restante();
    Menu * menu;
};

#endif // JUEGO_H
