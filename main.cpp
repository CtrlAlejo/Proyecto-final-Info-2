#include "nivel1.h"
#include <QApplication>

Nivel1 * nivel1;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    nivel1 = new Nivel1;
    nivel1 -> show();
    return a.exec();
}
