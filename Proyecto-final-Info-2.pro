QT       += core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bala.cpp \
    bola.cpp \
    imagen.cpp \
    jefe.cpp \
    juego.cpp \
    main.cpp \
    menu.cpp \
    morty.cpp \
    morty_armado.cpp \
    nivel1.cpp \
    nivel2.cpp \
    nivel3.cpp \
    nota.cpp \
    obstaculo.cpp \
    pizarra.cpp \
    plasma.cpp \
    rombos.cpp

HEADERS += \
    bala.h \
    bola.h \
    imagen.h \
    jefe.h \
    juego.h \
    menu.h \
    morty.h \
    morty_armado.h \
    nivel1.h \
    nivel2.h \
    nivel3.h \
    nota.h \
    obstaculo.h \
    pizarra.h \
    plasma.h \
    rombos.h

FORMS += \
    menu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    sprites.qrc
