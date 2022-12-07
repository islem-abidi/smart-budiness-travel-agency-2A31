#include "contrat_client.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

CONTRAT_CLIENT1::CONTRAT_CLIENT1()
{
    num_contrat=0;
    date_sign="";
    date_expir="";
    nom_societe="";
    duree_contrat="";
    domaine="";
    ID_EMPLOYE="";
}
CONTRAT_CLIENT1::CONTRAT_CLIENT1(int,QString,QString,QString,QString,QString)
{
     this->num_contrat=num_contrat;
    this->date_sign=date_sign;
    this->date_expir=date_expir;
    this->nom_societe=nom_societe;
    this->duree_contrat=duree_contrat;
    this->domaine=domaine;
    this->ID_EMPLOYE=ID_EMPLOYE;
 }


/*int CONTRAT_CLIENT::     getnum_contrat(){return num;}
void CONTRAT_CLIENT::setnum_contrat(int  num_contrat){num= num_contrat;};

QString CONTRAT_CLIENT::     getdurée_contrat=(){return durée_contrat;}
QString CONTRAT_CLIENT::     getdate_sign=(){return date_sign;}
QString CONTRAT_CLIENT::     getdate_expir(){return date_expir ;}
QString CONTRAT_CLIENT::     getnom_societe(){return nom_societe;}

*/
bool CONTRAT_CLIENT1::ajouter()
{    QSqlQuery query;
     QString num = QString::number(num_contrat);

     query.prepare("INSERT INTO  CONTRAT_CLIENT1(num_contrat,date_sign,date_expir,nom_societe,duree_contrat,domaine,ID_EMPLOYE)" "VALUES(:num_contrat,:date_sign,:date_expir,:nom_societe,:duree_contrat,:domaine,:ID_EMPLOYE)");
     query.bindValue(":num_contrat",num);
     query.bindValue(":date_sign",date_sign);
     query.bindValue(":date_expir",date_expir);
     query.bindValue(":nom_contrat",nom_societe);
     query.bindValue(":duree_contrat",duree_contrat);
      query.bindValue(":domaine",domaine);
      query.bindValue(":ID_EMPLOYE",ID_EMPLOYE);
     return query.exec();
}

bool CONTRAT_CLIENT1::supprimer(int)
{
    QSqlQuery query;
    QString num=QString::number(num_contrat);
    query.prepare("Delete from CONTRAT_CLIENT1 where NUM_CONTRAT=:num_contrat");
    query.bindValue(":num_contrat"
                    "",num );
    return query.exec();

}

bool CONTRAT_CLIENT1::modifier()
{
        QSqlQuery query;
        QString num=QString::number(num_contrat);

        query.prepare("UPDATE CONTRAT_CLIENT1 SET date_sign=:date_sign,date_expir=:date_expir,nom_societe=:nom_societe,duree_contrat=:duree_contrat,domaine=:domaine WHERE num_contrat=:num_contrat" );

        query.bindValue(":num_contrat",num );

        query.bindValue(":date_sign",date_sign );
        query.bindValue(":date_expir",date_expir );
        query.bindValue(":nom_societe",nom_societe);
        query.bindValue(":duree_contrat",duree_contrat );
        query.bindValue(":domaine",domaine);
        return query.exec();
    }


QSqlQueryModel *CONTRAT_CLIENT1::chercher(QString nom_societe )
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from CONTRAT_CLIENT1 where nom_societe like '" +nom_societe+"'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("num_contrat"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("date_sign"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("date_expir"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("nom_societe"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("duree_contrat"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("domaine"));

    return model;
  }
QSqlQueryModel* CONTRAT_CLIENT1::afficher()
{
   QSqlQueryModel* model=new QSqlQueryModel() ;
   model->setQuery("SELECT* FROM CONTRAT_CLIENT1");
   model->setHeaderData(0, Qt::Horizontal, QObject::tr("num_contrat"));
   model->setHeaderData(1, Qt::Horizontal, QObject::tr("date_sign"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_expir"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom_societe"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("duree_contrat"));
   model->setHeaderData(5,Qt::Horizontal,  QObject::tr("domaine"));
       return model;

}
QSqlQueryModel * CONTRAT_CLIENT1::trier()
{

    {

               QSqlQuery * q = new  QSqlQuery ();
                      QSqlQueryModel * model = new  QSqlQueryModel ();
                      q->prepare("SELECT * from CONTRAT_CLIENT1 order by nom_societe DESC");
                      q->exec();
                      model->setQuery(*q);
                      return model;
    }
}
QSqlQueryModel * CONTRAT_CLIENT1::trierASC()
{

    {

               QSqlQuery * q = new  QSqlQuery ();
                      QSqlQueryModel * model = new  QSqlQueryModel ();
                      q->prepare("SELECT * from CONTRAT_CLIENT1 order by nom_societe ASC");
                      q->exec();
                      model->setQuery(*q);
                      return model;
    }
}
QStringList CONTRAT_CLIENT1::listeadresses(QString var){
    QSqlQuery query;
    query.prepare("select DISTINCT("+var+") from CONTRAT_CLIENT1");
    query.exec();
    QStringList list;
    while(query.next())
    {
        list.append(query.value(0).toString());
    }

    return list;
}
int CONTRAT_CLIENT1::calcul_adresses(QString adresse,QString val)
{
    QSqlQuery query;
     query.prepare("select  * from CONTRAT_CLIENT1  WHERE "+val+"=:adresse");
     query.bindValue(":adresse", adresse );
     query.exec();
     int total=0;
     while(query.next())
     {
       total++;
     }
     return total;
}
