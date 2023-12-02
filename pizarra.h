#ifndef PIZARRA_H
#define PIZARRA_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QMediaPlayer>
#include <QAudioOutput>

class Pizarra : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Pizarra(int w, int h, QGraphicsRectItem *parent = NULL);
    void generar_rectangulos();
    void check_generator(int id);
private:
    QPointF posicion;
    QGraphicsPixmapItem *pass1;
    QGraphicsPixmapItem *pass2;
    QGraphicsPixmapItem *pass3;
    QGraphicsPixmapItem *pass4;
    QGraphicsPixmapItem *pass5;
    QMediaPlayer * sonido_checker;
    QAudioOutput * audioOutput;
};

#endif // PIZARRA_H
