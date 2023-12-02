#include "morty.h"
#include "obstaculo.h"
#include "imagen.h"
#include "pizarra.h"

Morty::Morty(Pizarra *_pizarra, int w, int h, QString file, QObject *parent) : QObject(parent)
{
    establecer_sonidos();
    vivo = true;
    detect_plataforma = false;
    nota_tomada = nullptr;
    pizarra = _pizarra;
    alto = w;
    ancho = h;
    Vy = 0.0;
    gravedad = 0.0010;
    salto = -0.5;
    num_notas = 0;
    control_sprites = new QTimer(this);
    verif_plataforma = new QTimer(this);
    setPixmap(QPixmap(file).scaled(ancho,alto));
    connect(verif_plataforma, SIGNAL(timeout()), this, SLOT(deteccion_plataforma()));
    connect(control_sprites, SIGNAL(timeout()), this, SLOT(animacion_movimiento()));
    verif_plataforma -> start(1);
    control_sprites -> start(100);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    sprite = 1;
}

void Morty::establecer_sonidos()
{
    sonido_salto = new QMediaPlayer(this);
    sonido_derrota = new QMediaPlayer(this);
    sonido_papel = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    audioOutput2 = new QAudioOutput(this);
    audioOutput3 = new QAudioOutput(this);
    audioOutput3 -> setVolume(50);
    audioOutput2 -> setVolume(50);
    audioOutput -> setVolume(50);
    sonido_papel -> setAudioOutput(audioOutput3);
    sonido_derrota -> setAudioOutput(audioOutput2);
    sonido_salto -> setAudioOutput(audioOutput);
    sonido_salto -> setSource(QUrl("qrc:/sonidos/Mortys_Vindicator_Challenge/Sonidos/salto.wav"));
    sonido_derrota -> setSource(QUrl("qrc:/sonidos/Mortys_Vindicator_Challenge/Sonidos/player-losing.wav"));
    sonido_papel -> setSource(QUrl("qrc:/sonidos/Mortys_Vindicator_Challenge/Sonidos/Sample_0006.wav"));
}

void Morty::cambiar_estado() //Cambia el estado de Morty, cuando este hace contacto con algun elemento mortal en el nivel
{
    vivo = false;
    control_sprites -> stop();
    gravedad = 0;
    Vy = 0;
    Vx = 0;
    setPixmap(QPixmap(":/Mortys_Vindicator_Challenge/Sprites/morty_default.png").scaled(ancho,alto));
    sonido_derrota -> play();
}

void Morty::deteccion_nota() //Detecta la nota cuando el jugador presiona la barra espaciadora
{
    QList<QGraphicsItem *> collidingItems = this -> collidingItems();
    if (num_notas < 1){
        for (QGraphicsItem *item : collidingItems) {
            if (Nota *nota = dynamic_cast<Nota*>(item)){
                nota_tomada = nota;
                sonido_papel -> play();
                nota_tomada -> setPos(780,0);
                nota_tomada -> act_mensaje = false;
                id_nota = nota_tomada -> get_id();
                num_notas++;
                //qDebug() << num_notas;
                break;
            }
        }
    }
    else{ //Cuando Morty halla tomado una nota, verificara que cuando se vuelva a pulsar la barra espaciadora, Morty este sobre la imagen correspondiente
        for (QGraphicsItem *item : collidingItems) {
            if (imagen *vindicador = dynamic_cast<imagen*>(item)){
                if (vindicador -> get_id() == id_nota){
                    pizarra -> check_generator(id_nota);
                    scene() -> removeItem(nota_tomada);
                    num_notas--;
                    break;
                }
            }
        }
    }
}

void Morty::verif_coordenadas() //Verifica multiples coordenadas para evitar traspasar las plataformas
{
    if (posicionMorty.x() >= 822 && (595 <= posicionMorty.y() && 680 >= posicionMorty.y())){
        setPos(822, posicionMorty.y());
    }
    else if (posicionMorty.x() <= 687 && (495 <= posicionMorty.y() && 590 >= posicionMorty.y())){
        setPos(687, posicionMorty.y());
    }
    else if (posicionMorty.x() <= 112 && (387 <= posicionMorty.y() && 450 >= posicionMorty.y())){
        setPos(112, posicionMorty.y());
    }
    else if (posicionMorty.x() >= 220 && (325 <= posicionMorty.y() && 420 >= posicionMorty.y())){
        setPos(220, posicionMorty.y());
    }
    else if ((posicionMorty.x() <= 1294 && posicionMorty.x() > 1185) && (86 <= posicionMorty.y() && 300 >= posicionMorty.y())){
        if (posicionMorty.x() < 1220){
            setPos(1185, posicionMorty.y());
        }
        else if (posicionMorty.x() >= 1192) {
            setPos(1294, posicionMorty.y());
        }
    }
    else if ((posicionMorty.x() > 1270 && posicionMorty.x() <= 1410) && (218 <= posicionMorty.y() && 250 >= posicionMorty.y())){
        setPos(1410, posicionMorty.y());
    }
    else if ((posicionMorty.x() > 1400 && posicionMorty.x() <= 1600) && (134 <= posicionMorty.y() && 206 >= posicionMorty.y())){
        setPos(1400, posicionMorty.y());
    }
    else if ((posicionMorty.x() <= 824 && posicionMorty.x() > 640) && (665 <= posicionMorty.y() && 740 >= posicionMorty.y())){
        if (posicionMorty.x() < 810){
            setPos(640, posicionMorty.y());
        }
        else if (posicionMorty.x() > 670) {
            setPos(824, posicionMorty.y());
        }
    }
}

void Morty::keyPressEvent(QKeyEvent *evento)
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
            deteccion_nota();
            break;
        default:
            break;
        }
    }
}

void Morty::keyReleaseEvent(QKeyEvent *evento)
{
    if (vivo){
        if (evento->isAutoRepeat()) return;
        switch (evento -> key()){
        case Qt::Key_A:
            Vx = 0;
            modo = 3;
            setPixmap(QPixmap(":/Mortys_Vindicator_Challenge/Sprites/morty_default_left.png").scaled(ancho,alto));
            break;
        case Qt::Key_D:
            Vx = 0;
            modo = 4;
            setPixmap(QPixmap(":/Mortys_Vindicator_Challenge/Sprites/morty_default_right.png").scaled(ancho,alto));
            break;
        default:
            break;
        }
    }
}

void Morty::deteccion_plataforma()
{ //Genera multiples detecciones de Morty con los elementos del mapa
    posicionMorty = this->pos();
    QList<QGraphicsItem *> collidingItems = this->collidingItems();
    for (QGraphicsItem *item : collidingItems) {
        if (dynamic_cast<Plataforma*>(item)) {
            detect_plataforma = true;
//            qDebug() << item -> pos();
//            qDebug() << "Posicion morty: " << posicionMorty;
            if (item -> pos().y() - 60 < posicionMorty.y()){
                Vy = 0.1;
                setPos(posicionMorty.x(), posicionMorty.y() + 1);
            }
            if (Vy > 0.0){
                Vy = 0.0;
            }
            break;
        }
        else if (dynamic_cast<Nota*>(item)) continue;
        else if (dynamic_cast<Pincho*>(item)){
            cambiar_estado();
            break;
        }
        else if (dynamic_cast<imagen*>(item)) continue;
        else if (dynamic_cast<Pizarra*>(item)) continue;
        else if (dynamic_cast<QGraphicsTextItem*>(item)) continue;
        else if (dynamic_cast<Lago*>(item)){
            cambiar_estado();
            break;
        }
        else if (dynamic_cast<Sierra*>(item)){
            cambiar_estado();
            break;
        }
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
    verif_coordenadas();
    setPos(x() + Vx, y() + Vy);
}

void Morty::animacion_movimiento()
{ //Anima el movimiento de Morty cambiando los sprites cada cierto tiempo y teniendo en cuenta la direccion a la que se mueve el personaje
    if (modo == 1){
        if (sprite == 1){
            setPixmap(QPixmap(":/Mortys_Vindicator_Challenge/Sprites/morty_left_fase1.png").scaled(ancho,alto));
            sprite = 2;
        }
        else if (sprite == 2){
            setPixmap(QPixmap(":/Mortys_Vindicator_Challenge/Sprites/morty_left_fase2.png").scaled(ancho,alto));
            sprite = 1;
        }
    }
    else if (modo == 2){
        if (sprite == 1){
            setPixmap(QPixmap(":/Mortys_Vindicator_Challenge/Sprites/morty_right_fase1.png").scaled(ancho,alto));
            sprite = 2;
        }
        else if (sprite == 2){
            setPixmap(QPixmap(":/Mortys_Vindicator_Challenge/Sprites/morty_right_fase2.png").scaled(ancho,alto));
            sprite = 1;
        }
    }
    else if (modo == 3){
        setPixmap(QPixmap(":/Mortys_Vindicator_Challenge/Sprites/morty_default_left.png").scaled(ancho,alto));
    }
    else if (modo == 4){
        setPixmap(QPixmap(":/Mortys_Vindicator_Challenge/Sprites/morty_default_right.png").scaled(ancho,alto));
    }
}
