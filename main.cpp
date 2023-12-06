#include "menu.h"
#include "juego.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Juego juego;
    return a.exec();
}
