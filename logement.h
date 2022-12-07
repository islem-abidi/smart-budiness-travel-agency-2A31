#ifndef LOGEMENT_H
#define LOGEMENT_H
#include <QDate>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSystemTrayIcon>

class Logement
{
    int id ,id_hotel,id_client;
    QString adresse;
    QDate date_log;
public:
    Logement();
    Logement(int,int,QString,QDate);
    bool ajouter();
    bool ajouter_historique(QString);
       QSqlQueryModel * tri_idh();
       QSqlQueryModel * tri_idc();
       QSqlQueryModel * tri_adr();
       QSqlQueryModel * afficher();
       QSqlQueryModel * afficher_historique();
       void notification(QString,QString);

        QSqlQueryModel * recherche(QString);

       bool supprimer(int);
       bool supprimer_historique(int);
       bool modifier();
       bool test_pourc(int);
       void setId(int);
};

#endif // LOGEMENT_H
