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
    Morty(int x, int y, int w, int h, QString file, QObject *parent = NULL);
    QPoint control_movimiento();
    void establecerSobrePlataforma(bool sobrePlat);
protected:
    void keyPressEvent(QKeyEvent *evento);
    void keyReleaseEvent(QKeyEvent *evento);
    void act_movimiento();
private:
    int m_horizontalInput;
    int m_direction;
    int posX;
    int posY;
    int alto;
    int ancho;
    int movimiento;
    qreal Vy;
    qreal Vx;
    qreal gravedad;
    qreal salto;
    QTimer *control_salto;
    bool sobre_plataforma;
    QPoint posicion;
    QPoint direccion;
};

#endif // MORTY_H
