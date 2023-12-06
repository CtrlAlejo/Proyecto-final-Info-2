QT       += core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    imagen.cpp \
    juego.cpp \
    main.cpp \
    morty.cpp \
    nivel1.cpp \
    nivel2.cpp \
    nivel3.cpp \
    nota.cpp \
    obstaculo.cpp \
    pizarra.cpp \
    rombos.cpp

HEADERS += \
    imagen.h \
    juego.h \
    morty.h \
    nivel1.h \
    nivel2.h \
    nivel3.h \
    nota.h \
    obstaculo.h \
    pizarra.h \
    rombos.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    sprites.qrc
