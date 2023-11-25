#ifndef NOTA_H
#define NOTA_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class Nota : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Nota(int x, int y, int w, int h, QString file, QString texto, QObject *parent = NULL);
    void keyPressEvent(QKeyEvent *evento);
private:
    int posX;
    int posY;
    QString pista_vindicador;
};

#endif // NOTA_H
