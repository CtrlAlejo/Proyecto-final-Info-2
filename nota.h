#ifndef NOTA_H
#define NOTA_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QTimer>

class Nota : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Nota(int w, int h, QString file, QString texto, QObject *parent = NULL);
    void keyPressEvent(QKeyEvent *evento);
    void mostrar_mensaje();
    void cambiar_visibilidad(int modo);
private slots:
    void verif_interaccion();
private:
    QString pista_vindicador;
    QPointF posicion;
    QTimer *timer;
    QGraphicsTextItem *mensaje;
    bool visible;
};

#endif // NOTA_H
