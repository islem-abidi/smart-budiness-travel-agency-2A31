QT       += core gui \
    quick
QT += sql


config += consol
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets quickwidgets serialport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    connexion.cpp \
    contrat_client.cpp \
    employees.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    transport.cpp

HEADERS += \
    arduino.h \
    connexion.h \
    contrat_client.h \
    employees.h \
    login.h \
    mainwindow.h \
    transport.h

FORMS += \
    login.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
