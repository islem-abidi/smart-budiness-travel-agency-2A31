#include "mainwindow.h"
#include <contrat_client.h>
#include <QApplication>
#include <connexion.h>
#include <QMessageBox>
#include<login.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(false);
    Connexion c;
    login l;
    bool test=c.createconnect();
    //MainWindow w;

    if(test)
    {

        //w.show();
       l.show();
   QMessageBox::information(nullptr, QObject::tr("database is open"),
                QObject::tr("connection successful.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


    }
else
    QMessageBox::information(nullptr, QObject::tr("database is not open"),
                QObject::tr("connection failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

    return a.exec();
}

