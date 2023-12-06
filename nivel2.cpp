#include "nivel2.h"

NIvel2::NIvel2(int _vidas, QWidget *parent) : QGraphicsView (parent)
{
    nivel2 = new QGraphicsScene;
    setFixedSize(1600,900); //1600, 900
    setScene(nivel2);
    cant_vidas = new QGraphicsTextItem;
    cant_vidas -> setFont(QFont("Arial", 22));
    cant_vidas -> setDefaultTextColor(Qt::white);
    vidas = _vidas;
    id_nivel = 2;
    idNivel = new QGraphicsTextItem;
    idNivel -> setFont(QFont("Arial", 22));
    idNivel -> setDefaultTextColor(Qt::white);
    tiempo = new QGraphicsTextItem;
    tiempo -> setFont(QFont("Arial", 22));
    tiempo -> setDefaultTextColor(Qt::white);
    tiempo_restante = 5 * 60 * 1000;
    fondo = new QGraphicsPixmapItem(QPixmap(":/Mortys_Vindicator_Challenge/Sprites/Fondo nivel2.jpg").scaled(1600,900));
    nivel2 -> addItem(fondo);
    num_secuencia = 0;
    poner_bomba();
    poner_rombos();
    crear_botones();
    timer_rojo = new QTimer(this);
    timer_azul = new QTimer(this);
    timer_amarillo = new QTimer(this);
    timer_verde = new QTimer(this);
    light_time = new QTimer(this);
    connect(&timer, SIGNAL(timeout()), this, SLOT(actualizar_tiempo()));
    timer.start(1000);
    secuencias_vector = {{"ROJO"}, {"ROJO", "VERDE"}, {"ROJO", "VERDE", "AZUL"}, {"ROJO", "VERDE", "AZUL", "VERDE"}, {"ROJO", "VERDE", "AZUL", "VERDE", "AMARILLO"}};


    connect(boton_central, &QPushButton::clicked, this, [=]{
        secuencias();
        mensaje_secuencia->hide();
    });
    connect(boton_rojo, &QPushButton::clicked, this, [=]{
        verif_secuencia("ROJO");
    });
    connect(boton_azul, &QPushButton::clicked, this, [=]{
        verif_secuencia("AZUL");
    });
    connect(boton_amarillo, &QPushButton::clicked, this, [=]{
        verif_secuencia("AMARILLO");
    });
    connect(boton_verde, &QPushButton::clicked, this, [=]{
        verif_secuencia("VERDE");
    });

    mensaje_secuencia = new QLabel("Mensaje inicial", this);
    mensaje_secuencia->setGeometry(320, 40, 550, 50);
    mensaje_secuencia->hide(); // Oculta el QLabel inicialmente
    mensaje_secuencia->setFont(QFont("ALGERIAN", 35));

    bomba_desactivada = new QLabel("BOMBA DESACTIVADA", this);
    bomba_desactivada->setGeometry(320, 40, 550, 50);
    bomba_desactivada->hide(); // Oculta el QLabel inicialmente
    bomba_desactivada->setFont(QFont("ALGERIAN", 35));

}

void NIvel2::poner_rombos()
{
    tiempo -> setPos(20, 20);
    nivel2 -> addItem(tiempo);
    idNivel -> setPos(750, 20);
    idNivel -> setPlainText("Nivel: " + QString::number(id_nivel));
    nivel2 -> addItem(idNivel);
    cant_vidas -> setPos(1300, 20);
    cant_vidas -> setPlainText("Vidas: " + QString::number(vidas));
    nivel2 -> addItem(cant_vidas);
    rombo_rojo = new rombos(200,200,":/Mortys_Vindicator_Challenge/Sprites/rombo-rojo.png");
    rombo_rojo ->setPos(300,100);
    nivel2 -> addItem(rombo_rojo);

    rombo_azul = new rombos(200,200,":/Mortys_Vindicator_Challenge/Sprites/rombo-azul.png");
    rombo_azul ->setPos(600, 100);
    nivel2 ->addItem(rombo_azul);

    rombo_amarillo = new rombos(200,200,":/Mortys_Vindicator_Challenge/Sprites/rombo-amarillo.png");
    rombo_amarillo ->setPos(300, 400);
    nivel2 ->addItem(rombo_amarillo);

    rombo_verde = new rombos(200,200,":/Mortys_Vindicator_Challenge/Sprites/rombo-verde.png");
    rombo_verde ->setPos(600, 400);
    nivel2 ->addItem(rombo_verde);

    rombo_rojo_claro = new rombos(200,200,":/Mortys_Vindicator_Challenge/Sprites/rombo-rojo-claro.png");
    rombo_rojo_claro ->setPos(300,100);

    rombo_azul_claro = new rombos(200,200,":/Mortys_Vindicator_Challenge/Sprites/rombo-azul-claro.png");
    rombo_azul_claro ->setPos(600,100);

    rombo_amarillo_claro = new rombos(200,200,":/Mortys_Vindicator_Challenge/Sprites/rombo-amarillo-claro.png");
    rombo_amarillo_claro ->setPos(300,400);

    rombo_verde_claro = new rombos(200,200,":/Mortys_Vindicator_Challenge/Sprites/rombo-verde-claro.png");
    rombo_verde_claro ->setPos(600,400);

}

void NIvel2::poner_bomba()
{
    bomba = new rombos(400,400, ":/Mortys_Vindicator_Challenge/Sprites/bomba.png");
    bomba ->setPos(900, 100);
    nivel2 ->addItem(bomba);
    RyM = new rombos(600,400,":/Mortys_Vindicator_Challenge/Sprites/rick y morty feliz.png");
    RyM ->setPos(900,100);
}

void NIvel2::crear_botones()
{
    boton_rojo = new QPushButton("ROJO", nullptr);
    QGraphicsProxyWidget *widgetProxy_rojo = new QGraphicsProxyWidget();
    widgetProxy_rojo->setWidget(boton_rojo);
    QString red = "background-color: red;";
    boton_rojo->setStyleSheet(red);
    boton_rojo->setFont(QFont("ALGERIAN", 12));
    widgetProxy_rojo->setPos(900, 600);
    nivel2 -> addItem(widgetProxy_rojo);

    boton_azul = new QPushButton("AZUL", nullptr);
    QGraphicsProxyWidget *widgetProxy_azul = new QGraphicsProxyWidget();
    widgetProxy_azul->setWidget(boton_azul);
    QString blue = "background-color: blue;";
    boton_azul->setStyleSheet(blue);
    boton_azul->setFont(QFont("ALGERIAN", 12));
    widgetProxy_azul->setPos(1000, 600);
    nivel2 -> addItem(widgetProxy_azul);

    boton_amarillo = new QPushButton("AMARILLO", nullptr);
    QGraphicsProxyWidget *widgetProxy_amarillo = new QGraphicsProxyWidget();
    widgetProxy_amarillo->setWidget(boton_amarillo);
    QString yellow = "background-color: yellow;";
    boton_amarillo->setStyleSheet(yellow);
    boton_amarillo->setFont(QFont("ALGERIAN", 12));
    widgetProxy_amarillo->setPos(1100, 600);
    nivel2 -> addItem(widgetProxy_amarillo);

    boton_verde = new QPushButton("VERDE", nullptr);
    QGraphicsProxyWidget *widgetProxy_verde = new QGraphicsProxyWidget();
    widgetProxy_verde->setWidget(boton_verde);
    QString green = "background-color: green;";
    boton_verde->setStyleSheet(green);
    boton_verde->setFont(QFont("ALGERIAN", 12));
    widgetProxy_verde->setPos(1200, 600);
    nivel2 -> addItem(widgetProxy_verde);

    boton_central = new QPushButton(" MOSTRAR SECUENCIA", nullptr);
    QGraphicsProxyWidget *widgetProxy_central = new QGraphicsProxyWidget();
    widgetProxy_central->setWidget(boton_central);
    QString central = "background-color: purple;";
    boton_central->setStyleSheet(central);
    boton_central->setGeometry(0,0,200,50);
    boton_central->setFont(QFont("ALGERIAN", 15));
    widgetProxy_central->setPos(450, 330);
    nivel2 -> addItem(widgetProxy_central);
}

void NIvel2::secuencias()
{
    if(num_secuencia == 0){secuencia1();}
    else if(num_secuencia == 1){secuencia2();}
    else if(num_secuencia == 2){secuencia3();}
    else if(num_secuencia == 3){secuencia2();}
    else if(num_secuencia == 4){secuencia4();}
    else if(num_secuencia == 5){
        mensaje_secuencia->hide();
        bomba_desactivada->setStyleSheet("color: green;");
        bomba_desactivada->show();
        nivel2 ->removeItem(bomba);
        nivel2 ->addItem(RyM);
        timer.stop();
        emit secuencia_terminada();
        //delete this;
    }
}

void NIvel2::secuencia1()
{
    connect(timer_rojo, SIGNAL(timeout()), this, SLOT(rojo_claro()));
    connect(light_time, SIGNAL(timeout()), this, SLOT(rojo()));
    timer_rojo ->start(600);
}

void NIvel2::secuencia2()
{
    timer_rojo->stop();
    connect(timer_verde, SIGNAL(timeout()), this, SLOT(verde_claro()));
    connect(light_time, SIGNAL(timeout()), this, SLOT(verde()));
    timer_verde->start(600);
}

void NIvel2::secuencia3()
{
    timer_verde->stop();
    connect(timer_azul, SIGNAL(timeout()), this, SLOT(azul_claro()));
    connect(light_time, SIGNAL(timeout()), this, SLOT(azul()));
    timer_azul->start(600);
}

void NIvel2::secuencia4()
{
    timer_azul->stop();
    connect(timer_amarillo, SIGNAL(timeout()), this, SLOT(amarillo_claro()));
    connect(light_time, SIGNAL(timeout()), this, SLOT(amarillo()));
    timer_amarillo->start(600);
}

void NIvel2::verif_secuencia(const QString& color)
{
    if(num_secuencia < secuencias_vector.size()){
        esperada = secuencias_vector[num_secuencia];
        sec_usuario.push_back(color);

        if(sec_usuario.size() == esperada.size()){
            bool secuencia_correcta = true;

            for (size_t i = 0; i < esperada.size(); ++i) {
                if (esperada[i] != sec_usuario[i]) {
                    secuencia_correcta = false;
                    break;
                }
            }

            if(secuencia_correcta){
                qDebug() << "Secuencia correcta!";
                mensaje_secuencia->setText("SECUENCIA CORRECTA");
                mensaje_secuencia->setStyleSheet("color: green;");
                mensaje_secuencia->show();
                sec_usuario.clear();
                num_secuencia++;
            }
            else{
                qDebug() << "Secuencia incorrecta!";
                mensaje_secuencia->setText("SECUENCIA INCORRECTA");
                mensaje_secuencia->setStyleSheet("color: red;");
                mensaje_secuencia->show();
                sec_usuario.clear();
                num_secuencia = 0;
            }
        }
    }
}

void NIvel2::actualizar_tiempo()
{
    tiempo_restante -= 1000; // Reduce el tiempo en 1 segundo

    // Obtiene los minutos y segundos restantes
    int minutesRemaining = tiempo_restante / 60000;
    int secondsRemaining = (tiempo_restante % 60000) / 1000;

    // Actualiza el texto del QGraphicsTextItem
    tiempo -> setPlainText(QString::number(minutesRemaining) + ":" + QString::number(secondsRemaining));

    // Si el tiempo restante es 0, finaliza el timer
    if (tiempo_restante <= 0) {
        timer.stop();
        emit reiniciar_nivel();
        delete this;
    }
}

void NIvel2::rojo_claro()
{
    nivel2->removeItem(rombo_rojo);
    nivel2->addItem(rombo_rojo_claro);

    light_time ->start(500);
}

void NIvel2::rojo()
{
    nivel2 ->removeItem(rombo_rojo_claro);
    nivel2 ->addItem(rombo_rojo);

    light_time ->stop();
    timer_rojo ->stop();
}

void NIvel2::azul_claro()
{
    nivel2 ->removeItem(rombo_azul);
    nivel2 ->addItem(rombo_azul_claro);

    light_time ->start(500);
}

void NIvel2::azul()
{
    nivel2 ->removeItem(rombo_azul_claro);
    nivel2 ->addItem(rombo_azul);

    light_time ->stop();
    timer_azul ->stop();
}

void NIvel2::amarillo_claro()
{
    nivel2 ->removeItem(rombo_amarillo);
    nivel2 ->addItem(rombo_amarillo_claro);

    light_time ->start(500);
}

void NIvel2::amarillo()
{
    nivel2 ->removeItem(rombo_amarillo_claro);
    nivel2 ->addItem(rombo_amarillo);

    light_time ->stop();
    timer_amarillo ->stop();
}

void NIvel2::verde_claro()
{
    nivel2 ->removeItem(rombo_verde);
    nivel2 ->addItem(rombo_verde_claro);

    light_time ->start(500);
}

void NIvel2::verde()
{
    nivel2 ->removeItem(rombo_verde_claro);
    nivel2 ->addItem(rombo_verde);

    light_time ->stop();
    timer_verde ->stop();
}


