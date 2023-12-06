#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);
    fase1();
    connect(ui -> Boton_jugar, SIGNAL(clicked(bool)), this, SLOT(click_jugar()));
    connect(ui -> Boton_salir, SIGNAL(clicked(bool)), this, SLOT(click_salir()));
    connect(ui -> Boton_empezar, SIGNAL(clicked(bool)), this, SLOT(empezar_juego()));
}

Menu::~Menu()
{
    delete ui;
}

void Menu::fase1()
{
    ui -> Texto_introductorio -> setVisible(false);
    ui -> Reto1 -> setVisible(false);
    ui -> Reto2 -> setVisible(false);
    ui -> Reto3 -> setVisible(false);
    ui -> Controles -> setVisible(false);
    ui -> Boton_empezar -> setEnabled(false);
    ui -> Boton_empezar -> setVisible(false);
}

void Menu::click_jugar()
{
    ui -> Boton_jugar -> setEnabled(false);
    ui -> Boton_jugar -> setVisible(false);
    ui -> Boton_salir -> setEnabled(false);
    ui -> Boton_salir -> setVisible(false);
    ui -> Titulo_juego -> setVisible(false);
    fase2();
}

void Menu::click_salir()
{
    qApp -> exit();
}

void Menu::fase2()
{
    ui -> Texto_introductorio -> setVisible(true);
    ui -> Reto1 -> setVisible(true);
    ui -> Reto2 -> setVisible(true);
    ui -> Reto3 -> setVisible(true);
    ui -> Controles -> setVisible(true);
    ui -> Boton_empezar -> setVisible(true);
    ui -> Boton_empezar -> setEnabled(true);
    ui -> Boton_empezar -> setVisible(true);
}

void Menu::empezar_juego()
{
    juego = new Juego;
}
