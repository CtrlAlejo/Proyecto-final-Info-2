#include "nivel1.h"
#include "nivel2.h"
#include <QApplication>

Nivel1 * nivel1;
NIvel2 * nivel2;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    nivel2 = new NIvel2;
    nivel2 -> show();
    return a.exec();
}
