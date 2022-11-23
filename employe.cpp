#include "employe.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlQueryModel>
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

   QSqlQuery query;
     QString res=QString::number(ID);



    query.prepare("INSERT INTO EMPLOY(ID,NOM,PRENOM,EMAIL) "
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


                query.prepare("UPDATE EMPLOY SET  NOM=:NOM, PRENOM=:PRENOM where ID=:ID ");


                      query.bindValue(":ID", res);
                      query.bindValue(":NOM",NOM);
                      query.bindValue(":PRENOM", PRENOM);
                       query.bindValue(":EMAIL", EMAIL);



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
/*
QSqlQueryModel* Voyageur::rechercher(QString a)
{
     QSqlQueryModel * query=new QSqlQueryModel();
     query->setQuery("select * from EMPLOY where ( NOM like '%"+a+"%' or PRENOM like '%"+a+"%'  ) ");
     return    query;
}
*/
QSqlQueryModel* Employe::Rechercher(QString a){
    /*// QSqlQueryModel * model = new QSqlQueryModel();
       QSqlQuery qry;


        qry.prepare("SELECT * FROM EMPLOY where ID=:ID");
         qry.bindValue(":ID",ID);
          qry.exec();
         QSqlQueryModel *model= new QSqlQueryModel;
         model->setQuery(qry);
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("EMAIL"));*/
        //model->setQuery(qry);
       // return model;

    QSqlQueryModel * query=new QSqlQueryModel();
    query->setQuery("select * from EMPLOY where ( NOM like '%"+a+"%' or PRENOM like '%"+a+"%'  ) ");
    return    query;
}
