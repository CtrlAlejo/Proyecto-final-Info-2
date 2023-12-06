#ifndef NIVEL2_H
#define NIVEL2_H

#include <QObject>
#include <QGraphicsView>
#include <QPushButton>
#include <QGraphicsProxyWidget>
#include <QLabel>
#include <QTimer>
#include <vector>
#include <unistd.h>
#include "rombos.h"

using namespace std;

class NIvel2 : public QGraphicsView
{
    Q_OBJECT
public:
    NIvel2(QWidget *parent = NULL);
    void poner_rombos();
    void poner_bomba();
    void crear_botones();
    void secuencias();
    void secuencia1();
    void secuencia2();
    void secuencia3();
    void secuencia4();
    void verif_secuencia(const QString& color);
signals:
    void secuencia_terminada();
public slots:
    void rojo_claro();
    void rojo();
    void azul_claro();
    void azul();
    void amarillo_claro();
    void amarillo();
    void verde_claro();
    void verde();
private:
    QTimer *timer_rojo;
    QTimer *timer_azul;
    QTimer *timer_amarillo;
    QTimer *timer_verde;
    QTimer *light_time;
    QGraphicsScene *nivel2;
    QGraphicsPixmapItem *fondo;
    QPushButton *boton_rojo;
    QPushButton *boton_azul;
    QPushButton *boton_amarillo;
    QPushButton *boton_verde;
    QPushButton *boton_central;
    QLabel *mensaje_secuencia;
    QLabel *bomba_desactivada;
    rombos *rombo_rojo;
    rombos *rombo_rojo_claro;
    rombos *rombo_azul;
    rombos *rombo_azul_claro;
    rombos *rombo_amarillo;
    rombos *rombo_amarillo_claro;
    rombos *rombo_verde;
    rombos *rombo_verde_claro;
    rombos *bomba;
    rombos *RyM;
    int num_secuencia;
    vector<vector<QString>> secuencias_vector;
    vector<QString> esperada;
    vector<QString> sec_usuario;

};

#endif // NIVEL2_H
