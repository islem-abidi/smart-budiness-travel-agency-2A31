#ifndef CONTRAT_CLIENT_H
#define CONTRAT_CLIENT_H
#include<QString>
#include<QSqlQueryModel>
#include<QTableView>
#include<QMessageBox>


class CONTRAT_CLIENT1
{
private:
  int num_contrat;
  QString date_sign,date_expir;
  QString duree_contrat,nom_societe,domaine,ID_EMPLOYE;



public:
   CONTRAT_CLIENT1();
   CONTRAT_CLIENT1(int,QString,QString,QString,QString,QString);

   int getnum_contrat(){return num_contrat;}
   QString getdate_sign(){return date_sign;}
   QString getdate_expir(){return date_expir;}
   QString getnom_societe(){return nom_societe;}
   QString getduree_contrat(){return duree_contrat;}
   QString getdomaine(){return domaine;}
   QString getID_EMPLOYE(){return ID_EMPLOYE;}

   int setnum_contrat(int num_contrat){ this->num_contrat=num_contrat;}
   QString setdate_sign(QString  date_sign){ this->date_sign=date_sign;}
   QString setdate_expir(QString  date_expir){ this->date_expir=date_expir;}
   QString setnom_societe(QString nom_societe){this->nom_societe=nom_societe;}
   QString setduree_contrat(QString duree_contrat){this->duree_contrat=duree_contrat;}
    QString setdomaine(QString domaine){this->domaine=domaine;}
    QString setID_EMPLOYE(QString ID_EMPLOYE){this->ID_EMPLOYE=ID_EMPLOYE;}



  bool ajouter();
  QSqlQueryModel* afficher();
  bool supprimer(int);
  bool modifier();
 QSqlQueryModel * chercher(QString nom_societe);
 QSqlQueryModel *trier();
 QSqlQueryModel *trierASC();
 QStringList listeadresses(QString var);
 int calcul_adresses(QString adresse,QString val);


};

#endif // CONTRAT_CLIENT_H
