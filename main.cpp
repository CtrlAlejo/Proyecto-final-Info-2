#include "nivel1.h"
#include "nivel3.h"
#include <QApplication>

Nivel1 * nivel1;
Nivel3 * nivel3;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
/*
    nivel1 = new Nivel1;
    nivel1 -> show();
    */
    nivel3 = new Nivel3;
    nivel3 -> show();
    return a.exec();
}
