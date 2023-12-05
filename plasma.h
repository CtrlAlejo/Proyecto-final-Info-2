#ifndef PLASMA_H
#define PLASMA_H

#include <QObject>
#include "bala.h"

class Plasma : public Bala
{
    Q_OBJECT
public:
    Plasma(int tipo_desplazamiento, int Xo, int w, int h);
    void verificar_colisiones() override;
public slots:
    void desplazamiento_bala() override;
    void desplazamiento_tipo1();
    void desplazamiento_tipo2();
private:
    QString plasma_fase1;
    QString plasma_fase2;
    QString plasma_fase3;
    QString plasma_fase4;
    QString plasma_fase5;
    QString plasma_fase6;
    QString plasma_fase7;
    QString plasma_fase8;
    int fase_mov;
};

#endif // PLASMA_H
