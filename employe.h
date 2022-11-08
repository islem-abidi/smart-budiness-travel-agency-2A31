#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQueryModel>

class Employe
{
public:
    Employe();
    Employe(int,QString,QString,QString);
    //getters
    int Get_id(){return ID;}
    QString Get_nom(){return NOM;}
     QString Get_prenom(){return PRENOM;}
     QString Get_mail(){return EMAIL;}

     //setters
     void Set_id(int ID){this->ID=ID;}
     void Set_nom(QString n){this->NOM=n;}
     void Set_prenom(QString pn){this->PRENOM=pn;}
     void Set_mail(QString m){this->EMAIL=m;}

       //Fonctionnalités de base relatives à l'entuté EMPLOYE
     bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
   bool modifier(int);




private:
    int ID;
    QString NOM,PRENOM,EMAIL;

};

#endif // EMPLOYE_H
