#include "morty.h"
#include "obstaculo.h"
#include "imagen.h"
#include "pizarra.h"
#include "bala.h"

Morty::Morty(Pizarra *_pizarra, int w, int h, QString file, QObject *parent) : QObject(parent)
{
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
    inicializar();
}

Morty::Morty(int w, int h, QString file, QObject *parent) : QObject(parent)
{
    Vy = 0.0;
    gravedad = 0.0010;
    salto = -0.5;
    alto = w;
    ancho = h;
    setPixmap(QPixmap(file).scaled(ancho,alto));
    vivo = true;
    control_sprites = new QTimer(this);
    verif_plataforma = new QTimer(this);
    detect_plataforma = false;
    verif_plataforma -> start(1);
    control_sprites -> start(100);
    connect(verif_plataforma, SIGNAL(timeout()), this, SLOT(deteccion_plataforma()));
    connect(control_sprites, SIGNAL(timeout()), this, SLOT(animacion_movimiento()));
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    sprite = 1;
    inicializar();
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

void Morty::inicializar()
{
    establecer_sonidos();
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
    //2da plataforma
    if (posicionMorty.x() >= 822 && (595 <= posicionMorty.y() && 675 >= posicionMorty.y())){
        setPos(822, posicionMorty.y());
    }
    //3ra plataforma
    else if (posicionMorty.x() <= 687 && (508 <= posicionMorty.y() && 585 >= posicionMorty.y())){
        setPos(687, posicionMorty.y());
    }
    //4ta plataforma
    else if (posicionMorty.x() <= 115 && (390 <= posicionMorty.y() && 455 >= posicionMorty.y())){
        setPos(115, posicionMorty.y());
    }
    //5ta plataforma
    else if (posicionMorty.x() >= 217 && (345 <= posicionMorty.y() && 410 >= posicionMorty.y())){
        setPos(217, posicionMorty.y());
    }
    //6ta plataforma (vertical)
    else if ((posicionMorty.x() <= 1296 && posicionMorty.x() > 1180) && (86 <= posicionMorty.y() && 292 >= posicionMorty.y())){
        if (posicionMorty.x() < 1220){
            setPos(1180, posicionMorty.y());
        }
        else if (posicionMorty.x() >= 1192) {
            setPos(1296, posicionMorty.y());
        }
    }
    //7ma plataforma
    else if ((posicionMorty.x() > 1270 && posicionMorty.x() <= 1414) && (224 <= posicionMorty.y() && 260 >= posicionMorty.y())){
        setPos(1414, posicionMorty.y());
    }
    //8va plataforma
    else if ((posicionMorty.x() > 1400 && posicionMorty.x() <= 1600) && (140 <= posicionMorty.y() && 210 >= posicionMorty.y())){
        setPos(1400, posicionMorty.y());
    }
    //1ra plataforma
    else if ((posicionMorty.x() <= 826 && posicionMorty.x() > 637) && (670 <= posicionMorty.y() && 730 >= posicionMorty.y())){
        if (posicionMorty.x() < 801){
            setPos(637, posicionMorty.y());
        }
        else if (posicionMorty.x() > 670) {
            setPos(826, posicionMorty.y());
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
            if (item -> pos().y() - 20 < posicionMorty.y()){
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
        else if (dynamic_cast<Bala*>(item)) continue;
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
}
