#include "morty.h"
#include "nivel1.h"

extern Nivel1 * nivel1;

Morty::Morty(int x, int y, int w, int h, QString file, QObject *parent) : QObject(parent)
{
    sobre_plataforma = false;
    posX = x;
    posY = y;
    alto = w;
    ancho = h;
    movimiento = 5;
    m_direction = 0;
    Vy = 0.0;
    gravedad = 0.5;
    salto = -12.0;
    setPixmap(QPixmap(file).scaled(ancho,alto));
    connect(control_salto, SIGNAL(timeout()), this, SLOT(act_movimiento()));
    control_salto -> start(16);
}

QPoint Morty::control_movimiento()
{
    QPoint velocidad, sig_posicion;
    velocidad = direccion * movimiento;
    sig_posicion = posicion + velocidad;
    velocidad.setY(velocidad.y() - 9.81);
    return sig_posicion;
}

void Morty::keyPressEvent(QKeyEvent *evento)
{
    if (evento->isAutoRepeat()) return;
    switch (evento -> key()){
    case Qt::Key_W:
        if (sobre_plataforma){
            Vy = salto;
        }
        break;
    case Qt::Key_A:
        Vx -= 1.0;
        break;
    case Qt::Key_D:
        Vx += 1.0;
        break;
    default:
        break;
    }

}

void Morty::keyReleaseEvent(QKeyEvent *evento)
{
    if (evento->isAutoRepeat()) return;
    switch (evento -> key()){
    case Qt::Key_A:
        Vx = 0;
        break;
    case Qt::Key_D:
        Vx = 0;
        break;
    default:
        break;
    }
}

void Morty::act_movimiento()
{
    Vy += gravedad;
    moveBy(Vx, Vy);
}

void Morty::establecerSobrePlataforma(bool sobrePlat)
{
    sobre_plataforma = sobrePlat;
    if (sobre_plataforma) {
        Vy = 0;
    }
}

