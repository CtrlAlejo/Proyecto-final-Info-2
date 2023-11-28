#ifndef MORTY_H
#define MORTY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QKeyEvent>

class Morty : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Morty(int w, int h, QString file, QObject *parent = NULL);
protected:
    void verif_coordenadas();
    void keyPressEvent(QKeyEvent *evento);
    void keyReleaseEvent(QKeyEvent *evento);
private slots:
    void animacion_movimiento();
    void deteccion_plataforma();
private:
    QPointF posicionMorty;
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
};

#endif // MORTY_H
