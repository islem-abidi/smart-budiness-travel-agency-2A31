QT       += core gui \
    quick
QT += sql
QT += core gui sql network multimedia multimediawidgets charts printsupport widgets axcontainer

config += consol
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets quickwidgets serialport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    arduino1.cpp \
    chat.cpp \
    connexion.cpp \
    contrat_client.cpp \
    employe.cpp \
    employees.cpp \
    excel.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    smtp1.cpp \
    statistique.cpp \
    transport.cpp \
    notif.cpp \
logement.cpp \
    smtp.cpp

HEADERS += \
    arduino.h \
    arduino1.h \
    chat.h \
    connexion.h \
    contrat_client.h \
    employe.h \
    employees.h \
    excel.h \
    login.h \
    mainwindow.h \
    smtp1.h \
    statistique.h \
logement.h \
    transport.h \
    notif.h \
    smtp.h

FORMS += \
    chat.ui \
    login.ui \
    mainwindow.ui \
    statistique.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
