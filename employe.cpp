#include "employe.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Employe::Employe()
{
  ID=0; NOM=""; PRENOM=""; EMAIL="";
}
////////////////////////////////////////////////////
Employe::Employe(int ID,QString NOM,QString PRENOM,QString EMAIL)
{
    this->ID=ID;
    this->NOM=NOM;
    this->PRENOM=PRENOM;
    this->EMAIL=EMAIL;
}
///////////////////////////////////////////////////
bool Employe::ajouter()
{


     QString res=QString::number(ID);
    QSqlQuery query;


    query.prepare("INSERT INTO EMPLOYEEE(ID,NOM,PRENOM,EMAIL) "
                  "VALUES (:ID,  :NOM,  :PRENOM  ,:EMAIL)");
    query.bindValue(":ID", res);

    query.bindValue(":NOM", NOM);
    query.bindValue(":PRENOM", PRENOM);
    query.bindValue(":EMAIL", EMAIL);
    return  query.exec();

}
bool Employe::supprimer(int ID)
{
    QSqlQuery query;

    query.prepare("Delete from EMPLOYEEE where ID=:ID");
    query.bindValue(":ID",ID);

    return  query.exec();

}
QSqlQueryModel* Employe::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM EMPLOYEEE");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("EMAIL"));



    return model;
}
  /*bool modifier()
  {

  }*/
bool Employe::modifier(int ID)
{
    QSqlQuery query;
              QString res=QString::number(ID);


                query.prepare("UPDATE EMPLOYE  SET  NOM=:NOM, PRENOM=:PRENOM where ID=:ID ");


                      query.bindValue(":ID", res);
                      query.bindValue(":NOM",NOM);
                      query.bindValue(":PRENOM", PRENOM);
                       query.bindValue(":EMAIL", EMAIL);



                  return query.exec();
}

