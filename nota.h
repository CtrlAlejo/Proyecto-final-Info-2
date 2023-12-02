#ifndef NOTA_H
#define NOTA_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsScene>

class Nota : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Nota(int _id, int _posX, int _posY, int w, int h, QString file, QString texto, QObject *parent = NULL);
    void poner_mensaje();
    int get_id();
    bool act_mensaje;
private slots:
    void verif_interaccion();
private:
    QString pista_vindicador;
    QTimer *timer;
    QGraphicsTextItem *mensaje;
    int posX;
    int posY;
    int id;
};

#endif // NOTA_H
