#ifndef TRANSPORT_H
#define TRANSPORT_H
#include <QString>
#include "connexion.h"
#include <QSqlQueryModel>
#include <QSqlQuery>


class transport
{
    QString prenom , nom , depart , destination ,datedepart,dateretour,datenaissance;
    int NUM_PASS;
    int len;
public:
    transport(){}
    transport (int,QString,QString,QString,QString,QString,QString,QString);
    QString getNom(){return nom;}
     QString getPrenom(){return prenom;}
     QString getdepart(){return depart;}
      QString getdestination(){return destination;}
      QString getdatedepart(){return datedepart;}
       QString getdateretour(){return dateretour;}
       QString getdatenaissance(){return datenaissance;}
       void checkvoucher(QString,QString);
      int voucher();
      QString randString(int);


      int getId(){return NUM_PASS;}
      void setNom(QString n){nom=n;}
      void setPrenom(QString p){nom =p ;}
      void setID(int NUM_PASS){this->NUM_PASS=NUM_PASS;}
      bool ajouter();
      QSqlQueryModel * afficher();
      bool supprimer(int);
      bool modifier(int);
      QSqlQueryModel *chercher(int);
      QSqlQueryModel *sortid();
       void on_PDF_clicked();



};

#endif // TRANSPORT_H
