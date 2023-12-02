#include "pizarra.h"
#include "qbrush.h"
#include "qpen.h"

Pizarra::Pizarra(int w, int h, QGraphicsRectItem *parent) : QGraphicsRectItem (0,0, w, h, parent)
{
    setBrush(QBrush(Qt::white));
    setPen(QPen(Qt::black, 1));
    generar_rectangulos();
    sonido_checker = new QMediaPlayer(this);
    audioOutput = new QAudioOutput(this);
    audioOutput->setVolume(50);
    sonido_checker -> setAudioOutput(audioOutput);
    sonido_checker -> setSource(QUrl("qrc:/sonidos/Mortys_Vindicator_Challenge/Sonidos/checker imagenes.wav"));
}

void Pizarra::generar_rectangulos()
{
    pass1 = new QGraphicsPixmapItem(QPixmap(":/Mortys_Vindicator_Challenge/Sprites/rectangulo verde.png").scaled(70,10), this);
    pass1 -> setPos(8,9);
    pass1 -> setVisible(false);
    pass2 = new QGraphicsPixmapItem(QPixmap(":/Mortys_Vindicator_Challenge/Sprites/rectangulo verde.png").scaled(70,10), this);
    pass2 -> setPos(88,9);
    pass2 -> setVisible(false);
    pass3 = new QGraphicsPixmapItem(QPixmap(":/Mortys_Vindicator_Challenge/Sprites/rectangulo verde.png").scaled(70,10), this);
    pass3 -> setPos(168,9);
    pass3 -> setVisible(false);
    pass4 = new QGraphicsPixmapItem(QPixmap(":/Mortys_Vindicator_Challenge/Sprites/rectangulo verde.png").scaled(70,10), this);
    pass4 -> setPos(248,9);
    pass4 -> setVisible(false);
    pass5 = new QGraphicsPixmapItem(QPixmap(":/Mortys_Vindicator_Challenge/Sprites/rectangulo verde.png").scaled(70,10), this);
    pass5 -> setPos(328,9);
    pass5 -> setVisible(false);
}

void Pizarra::check_generator(int id) //Pone los rectangulos verdes sobre la imagen del Vindicador correspondiente
{
    if (pass1 && id == 1){
        pass1 -> setVisible(true);
        sonido_checker -> play();
    }
    else if (pass2 && id == 2){
        pass2 -> setVisible(true);
        sonido_checker -> play();
    }
    else if (pass3 && id == 3){
        pass3 -> setVisible(true);
        sonido_checker -> play();
    }
    else if (pass4 && id == 4){
        pass4 -> setVisible(true);
        sonido_checker -> play();
    }
    else if (pass5 && id == 5){
        pass5 -> setVisible(true);
        sonido_checker -> play();
    }
    else{
        qDebug() << "Error";
    }
}
