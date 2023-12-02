#ifndef JUEGO_H
#define JUEGO_H

#include <QObject>

class Juego : public QObject
{
    Q_OBJECT
public:
    Juego();
public slots:
    //void pasarAlSiguienteNivel();
    //void reiniciarNivelActual();
private:
    int nivelActual;
};

#endif // JUEGO_H
