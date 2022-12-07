#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQueryModel>


class Employe
{
public:
    Employe();
    Employe(int,QString,QString,QString,QString ETAT);
    //getters
    int Get_id(){return ID;}
    QString Get_nom(){return NOM;}
     QString Get_prenom(){return PRENOM;}
     QString Get_mail(){return EMAIL;}
     QString Get_etat(){return ETAT;}

     //setters
     void Set_id(int ID){this->ID=ID;}
     void Set_nom(QString n){this->NOM=n;}
     void Set_prenom(QString pn){this->PRENOM=pn;}
     void Set_mail(QString m){this->EMAIL=m;}
     void Set_etat(QString e){this->ETAT=e;}

       //Fonctionnalités de base relatives à l'entuté EMPLOYE
     bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
   bool modifier(int);
    bool modifierEtat(int,QString);
   QSqlQueryModel* Rechercher(QString);

   QSqlQueryModel* tri();




private:
    int ID;
    QString NOM,PRENOM,EMAIL,ETAT;

};

#endif // EMPLOYE_H
