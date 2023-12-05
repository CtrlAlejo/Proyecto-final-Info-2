#ifndef MORTY_H
#define MORTY_H

#include "nota.h"
#include "pizarra.h"
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QKeyEvent>
#include <QMediaPlayer>
#include <QAudioOutput>

class Morty : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Morty(Pizarra *_pizarra, int w, int h, QString file, QObject *parent = NULL);
    Morty(int w, int h, QString file, QObject *parent = NULL);
    virtual void cambiar_estado();
protected:
    virtual void establecer_sonidos();
    void inicializar();
    void deteccion_nota();
    void verif_coordenadas();
    virtual void keyPressEvent(QKeyEvent *evento);
    virtual void keyReleaseEvent(QKeyEvent *evento);
public slots:
    virtual void animacion_movimiento();
    virtual void deteccion_plataforma();
protected:
    QPointF posicionMorty;
    int num_notas;
    int modo;
    int sprite;
    int alto;
    int ancho;
    int movimiento;
    qreal Vy;
    qreal Vx;
    qreal gravedad;
    qreal salto;
    QTimer *control_sprites;
    QTimer *verif_plataforma;
    bool detect_plataforma;
    bool vivo;
    int id_nota;
    Pizarra * pizarra;
    Nota * nota_tomada;
    QMediaPlayer * sonido_salto;
    QMediaPlayer * sonido_derrota;
    QMediaPlayer * sonido_papel;
    QAudioOutput * audioOutput;
    QAudioOutput * audioOutput2;
    QAudioOutput * audioOutput3;
};

#endif // MORTY_H
