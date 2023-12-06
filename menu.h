#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include "juego.h"

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();
signals:
    void iniciar();
public slots:
    void fase1();
    void click_jugar();
    void click_salir();
    void fase2();
    void empezar_juego();
private:
    Ui::Menu *ui;
    Juego * juego;
};

#endif // MENU_H
