#include "employe.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlQueryModel>
Employe::Employe()
{
  ID=0; NOM=""; PRENOM=""; EMAIL=""; ETAT="";
}
////////////////////////////////////////////////////
Employe::Employe(int ID,QString NOM,QString PRENOM,QString EMAIL,QString ETAT)
{
    this->ID=ID;
    this->NOM=NOM;
    this->PRENOM=PRENOM;
    this->EMAIL=EMAIL;
    this->ETAT=ETAT;
}
///////////////////////////////////////////////////
bool Employe::ajouter()
{

   QSqlQuery query;
     QString res=QString::number(ID);



    query.prepare("INSERT INTO EMPLOY(ID,NOM,PRENOM,EMAIL,ETAT) "
                  "VALUES (:ID,  :NOM,  :PRENOM  ,:EMAIL, :ETAT)");
    query.bindValue(":ID", res);

    query.bindValue(":NOM", NOM);
    query.bindValue(":PRENOM", PRENOM);
    query.bindValue(":EMAIL", EMAIL);
    query.bindValue(":ETAT", ETAT);
    return  query.exec();

}
bool Employe::supprimer(int ID)
{
    QSqlQuery query;

    query.prepare("Delete from EMPLOY where ID=:ID");
    query.bindValue(":ID",ID);

    return  query.exec();

}
QSqlQueryModel* Employe::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM EMPLOY");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("ETAT"));




    return model;
}
  /*bool modifier()
  {

  }*/
bool Employe::modifier(int ID)
{
    QSqlQuery query;
              QString res=QString::number(ID);


                query.prepare("UPDATE EMPLOY SET  NOM=:NOM, PRENOM=:PRENOM where ID=:ID ");


                      query.bindValue(":ID", res);
                      query.bindValue(":NOM",NOM);
                      query.bindValue(":PRENOM", PRENOM);
                       query.bindValue(":EMAIL", EMAIL);
                       query.bindValue(":ETAT", ETAT);




                  return query.exec();
}
bool Employe::modifierEtat(int ID,QString etat)
{
    QSqlQuery query;
              QString res=QString::number(ID);


                query.prepare("UPDATE EMPLOY SET  ETAT=:etat where ID=:ID ");
                       query.bindValue(":ID", ID);
                       query.bindValue(":etat", etat);




                  return query.exec();
}
//////////////////////////////////
///////////////////////////////////////////
///


QSqlQueryModel * Employe::tri()
{
     //ml Z-A
    {

               QSqlQuery * q = new  QSqlQuery ();
                      QSqlQueryModel * model = new  QSqlQueryModel ();
                      q->prepare("SELECT * from Employ order by ID");
                      q->exec();
                      model->setQuery(*q);
                      return model;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////

QSqlQueryModel* Employe::Rechercher(QString a){


    QSqlQueryModel * query=new QSqlQueryModel();
    query->setQuery("select * from EMPLOY where ( NOM like '%"+a+"%' or PRENOM like '%"+a+"%'  ) ");
    return    query;
}
