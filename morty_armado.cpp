#include "morty_armado.h"
#include "bala.h"
#include "obstaculo.h"

Morty_Armado::Morty_Armado() : Morty(70, 90, ":/Mortys_Vindicator_Challenge/Sprites/morty_default_left_gun.png")
{

}

void Morty_Armado::cambiar_estado()
{
    vivo = false;
    control_sprites -> stop();
    gravedad = 0;
    Vy = 0;
    Vx = 0;
    setPixmap(QPixmap(":/Mortys_Vindicator_Challenge/Sprites/morty_default.png").scaled(90,95));
    sonido_derrota -> play();
}

void Morty_Armado::establecer_sonidos()
{
    sonido_salto = new QMediaPlayer(this);
    sonido_derrota = new QMediaPlayer(this);
    sonido_disparo = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    audioOutput2 = new QAudioOutput(this);
    audioOutput3 = new QAudioOutput(this);
    audioOutput3 -> setVolume(50);
    audioOutput2 -> setVolume(50);
    audioOutput -> setVolume(50);
    sonido_disparo -> setAudioOutput(audioOutput3);
    sonido_derrota -> setAudioOutput(audioOutput2);
    sonido_salto -> setAudioOutput(audioOutput);
    sonido_salto -> setSource(QUrl("qrc:/sonidos/Mortys_Vindicator_Challenge/Sonidos/salto.wav"));
    sonido_derrota -> setSource(QUrl("qrc:/sonidos/Mortys_Vindicator_Challenge/Sonidos/player-losing.wav"));
    sonido_disparo -> setSource(QUrl("qrc:/sonidos/Mortys_Vindicator_Challenge/Sonidos/Sample_0006.wav"));
}

void Morty_Armado::disparar()
{
    Bala * bala = new Bala(modo, posicionMorty.x(), 20, 10);
    bala -> setPos(posicionMorty.x(), posicionMorty.y() + 40);
    scene() -> addItem(bala);
}

void Morty_Armado::keyPressEvent(QKeyEvent *evento)
{
    if (vivo){
        if (evento->isAutoRepeat()) return;
        switch (evento -> key()){
        case Qt::Key_W: //Morty solo salta cuando esta sobre una plataforma
            if (detect_plataforma){
                Vy = salto;
                //if (sonido_salto -> state() == QMediaPlayer::PlayingState)
                sonido_salto -> play();
            }
            break;
        case Qt::Key_A:
            Vx -= 0.4;
            modo = 1;
            break;
        case Qt::Key_D:
            Vx += 0.4;
            modo = 2;
            break;
        case Qt::Key_Space:
            disparar();
            break;
        default:
            break;
        }
    }
}

void Morty_Armado::keyReleaseEvent(QKeyEvent *evento)
{
    if (vivo){
        if (evento->isAutoRepeat()) return;
        switch (evento -> key()){
        case Qt::Key_A:
            Vx = 0;
            modo = 3;
            setPixmap(QPixmap(":/Mortys_Vindicator_Challenge/Sprites/morty_default_left_gun.png").scaled(ancho,alto));
            break;
        case Qt::Key_D:
            Vx = 0;
            modo = 4;
            setPixmap(QPixmap(":/Mortys_Vindicator_Challenge/Sprites/morty_default_right_gun.png").scaled(ancho,alto));
            break;
        default:
            break;
        }
    }
}

void Morty_Armado::animacion_movimiento()
{
    if (modo == 1){
        if (sprite == 1){
            setPixmap(QPixmap(":/Mortys_Vindicator_Challenge/Sprites/morty_left_fase1_gun.png").scaled(ancho,alto));
            sprite = 2;
        }
        else if (sprite == 2){
            setPixmap(QPixmap(":/Mortys_Vindicator_Challenge/Sprites/morty_left_fase2_gun.png").scaled(ancho,alto));
            sprite = 1;
        }
    }
    else if (modo == 2){
        if (sprite == 1){
            setPixmap(QPixmap(":/Mortys_Vindicator_Challenge/Sprites/morty_right_fase1_gun.png").scaled(ancho,alto));
            sprite = 2;
        }
        else if (sprite == 2){
            setPixmap(QPixmap(":/Mortys_Vindicator_Challenge/Sprites/morty_right_fase2_gun.png").scaled(ancho,alto));
            sprite = 1;
        }
    }
}

void Morty_Armado::deteccion_plataforma()
{
    posicionMorty = this->pos();
    QList<QGraphicsItem *> collidingItems = this->collidingItems();
    for (QGraphicsItem *item : collidingItems) {
        if (dynamic_cast<Plataforma*>(item)) {
            detect_plataforma = true;
            //            qDebug() << item -> pos();
            //            qDebug() << "Posicion morty: " << posicionMorty;
            if (item -> pos().y() - 20 < posicionMorty.y()){
                Vy = 0.1;
                setPos(posicionMorty.x(), posicionMorty.y() + 1);
            }
            if (Vy > 0.0){
                Vy = 0.0;
            }
            break;
        }
        else if (dynamic_cast<Bala*>(item)) continue;
        else if (dynamic_cast<QGraphicsTextItem*>(item)) continue;
        else{
            detect_plataforma = false;
            Vy += gravedad;
            break;
        }
    }
    if (posicionMorty.x() <= 0){
        setPos(1,posicionMorty.y());
    }
    else if (posicionMorty.x() >= 1510){
        setPos(1510,posicionMorty.y());
    }
    setPos(x() + Vx, y() + Vy);
    emit enviar_posicion(posicionMorty);
}
