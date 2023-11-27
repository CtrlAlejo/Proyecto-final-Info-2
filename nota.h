#ifndef NOTA_H
#define NOTA_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class Nota : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Nota(int w, int h, QString file, QString texto, QObject *parent = NULL);
    void keyPressEvent(QKeyEvent *evento);
private:
    QString pista_vindicador;
    QPointF posicion;
};

#endif // NOTA_H
