#include "jefe.h"
#include "obstaculo.h"
#include "plasma.h"

Jefe::Jefe(QGraphicsScene * _escena, int w, int h, QString file, QObject *parent) : QObject(parent)
{
    vida = 30;
    escena = _escena;
    detect_plataforma = false;
    Vy = 0.0;
    gravedad = 0.0005;
    salto = -0.5;
    alto = h;
    ancho = w;
    setPixmap(QPixmap(file).scaled(ancho, alto));
    timer = new QTimer(this);
    timer2 = new QTimer(this);
    timer3 = new QTimer(this);
    bola = new Bola(40, 40, ":/Mortys_Vindicator_Challenge/Sprites/bola electrica.png", this);
    escena -> addItem(bola);
    connect(timer, SIGNAL(timeout()), this, SLOT(act_movimiento()));
    connect(timer2, SIGNAL(timeout()), this, SLOT(movimiento_jefe()));
    connect(timer3, SIGNAL(timeout()), this, SLOT(ataques_jefe()));
    timer -> start(1);
    timer2 -> start(100);
    timer3 -> start(1000);
}

void Jefe::postura_jefe()
{
    if (posicion_jefe.x() < posicion_morty.x()){
        setPixmap(QPixmap(":/Mortys_Vindicator_Challenge/Sprites/supernova_boss_right.png").scaled(ancho, alto));
        postura = 2;
    }
    else if (posicion_jefe.x() >= posicion_morty.x()){
        setPixmap(QPixmap(":/Mortys_Vindicator_Challenge/Sprites/supernova_boss_left.png").scaled(ancho, alto));
        postura = 1;
    }
}

void Jefe::bola_orbitante()
{
    qreal radio, velocidadAngular, xPos, yPos;
    radio = 100;
    velocidadAngular = 0.005;
    xPos = radio * qCos(bola -> rotation());
    yPos = radio * qSin(bola -> rotation());
    bola -> setPos(x() + xPos + ancho/2 , y() + yPos + alto/2);
    bola -> setRotation(bola -> rotation() + velocidadAngular);
    //qDebug() << bola2 -> pos();
}

void Jefe::disminuir_vida()
{
    vida--;
    if (vida <= 0){
        delete this;
    }
}

void Jefe::ataques_jefe()
{
    Plasma * plasma = new Plasma(postura, posicion_jefe.x(), 40, 40);
    plasma -> setPos(posicion_jefe.x() + 90, posicion_jefe.y() + 90);
    escena -> addItem(plasma);
}

void Jefe::tomar_posicion_morty(QPointF _posicion_morty)
{
    posicion_morty = _posicion_morty;
}

void Jefe::movimiento_jefe()
{
    mov = QRandomGenerator::global() -> bounded(1,4);
    if (mov == 1){
        Vx = -0.2;
    }
    else if (mov == 2){
        Vx = 0.2;
    }
    else if (mov == 3){
        if (detect_plataforma) Vy = salto;
    }
}

void Jefe::act_movimiento()
{
    posicion_jefe = this -> pos();
    QList<QGraphicsItem *> collidingItems = this->collidingItems();
    for (QGraphicsItem *item : collidingItems) {
        if (dynamic_cast<Plataforma*>(item)) {
            detect_plataforma = true;
            //            qDebug() << item -> pos();
            //            qDebug() << "Posicion morty: " << posicionMorty;
            if (Vy > 0.0){
                Vy = 0.0;
            }
            break;
        }
        else {
            detect_plataforma = false;
            Vy += gravedad;
        }
    }
    if (posicion_jefe.x() <= 0){
        setPos(1,posicion_jefe.y());
    }
    else if (posicion_jefe.x() >= 1420){
        setPos(1420,posicion_jefe.y());
    }
    postura_jefe();
    setPos(x() + Vx, y() + Vy);
    bola_orbitante();
}
