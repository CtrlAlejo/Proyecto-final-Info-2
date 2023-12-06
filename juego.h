#ifndef JUEGO_H
#define JUEGO_H

#include <QObject>

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
    int vidas;
    int nivelActual;
    int tiempo_restante();
};

#endif // JUEGO_H
