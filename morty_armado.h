#ifndef MORTY_ARMADO_H
#define MORTY_ARMADO_H

#include "morty.h"

class Morty_Armado : public Morty
{
    Q_OBJECT
public:
    Morty_Armado();
    void cambiar_estado() override;
protected:
    void establecer_sonidos() override;
    void disparar();
    void keyPressEvent(QKeyEvent *evento) override;
    void keyReleaseEvent(QKeyEvent *evento) override;
    QMediaPlayer * sonido_disparo;
signals:
    void muerto();
    void enviar_posicion(QPointF posicionMorty);
public slots:
    void animacion_movimiento() override;
    void deteccion_plataforma() override;
};

#endif // MORTY_ARMADO_H
