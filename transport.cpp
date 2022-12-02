#include "transport.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlRecord>
#include <cmath>
transport::transport(int NUM_PASS , QString nom , QString prenom,QString depar,QString destinatio,QString datedepar,QString dateretou,QString datenaissanc)
{
 this->NUM_PASS = NUM_PASS;
    this->nom = nom;
    this->prenom = prenom;
    this->depart = depar;
    this->destination = destinatio;
    this->datedepart = datedepar;
    this->dateretour = dateretou;
    this->datenaissance = datenaissanc;


}
bool transport::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(NUM_PASS);
    query.prepare("insert into transport ( NUM_PASS, prenom, nom ,depart ,destination ,datedepart ,dateretour ,datenaissance)""values(:NUM_PASS ,:prenom ,:nom,:depart,:destination,:datedepart,:dateretour,:datenaissance)");
    query.bindValue(":NUM_PASS",res);
    query.bindValue(":prenom",prenom);
    query.bindValue(":nom",nom);
    query.bindValue(":depart",depart);
    query.bindValue(":destination",destination);
    query.bindValue(":datedepart",datedepart);
    query.bindValue(":dateretour",dateretour);
    query.bindValue(":datenaissance",datenaissance);
    checkvoucher(prenom,nom);

    return query.exec();


}
QString transport::randString(int len)
{
    QString str;
    str.resize(len);
    for (int s = 0; s < len ; ++s)
        str[s] = QChar('A' + char(qrand() % ('Z' - 'A')));

    return str;
}
void transport::checkvoucher(QString prenom,QString nom)
{       int s;


        QSqlQuery  q("select count(*) as NUM from transport where nom ='"+nom+"' and prenom ='"+prenom+"'");
                QSqlRecord rec = q.record();
                int nameCol = rec.indexOf("NUM"); // index of the field "name"
                q.next();
                s = q.value(nameCol).toInt();
            if(s  >= 0)
            {
                QString x=randString(20);
                QSqlQuery query;

                query.prepare("UPDATE CONTRACT SET CODE = '"+x+"', isvalid= 'true' where nom ='"+nom+"' and prenom ='"+prenom+"'");
                query.bindValue("isvalid",'true');
                query.prepare("UPDATE CONTRACT SET PRIX= PRIX*0.9  where isvalid= 'true'");



                query.exec();

            }




}

QSqlQueryModel *transport::afficher()
{

    QSqlQueryModel *model =new QSqlQueryModel();
    model->setQuery("select * from transport");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("Numero Passport"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));

    return model;
}


bool transport::supprimer(int NUM_PASS)
{
    QSqlQuery query;

    query.prepare("Delete from transport where NUM_PASS = :NUM_PASS");
    query.bindValue(0,NUM_PASS);
    return query.exec();

}
/*
bool transport::modifier(int NUM_PASS)
{
    QSqlQuery query;
              QString res=QString::number(NUM_PASS);


                query.prepare("UPDATE transport "" SET NUM_PASS=:NUM_PASS, nom=:nom, prenom=:prenom where NUM_PASS='"+res+"' ");


                      query.bindValue(":NUM_PASS", res);
                      query.bindValue(":nom", nom);
                      query.bindValue(":prenom", prenom);



                  return query.exec();
}
*/
QSqlQueryModel *transport::chercher(int NUM_PASS)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QString str ;
    //Connexion Conn;
    //Conn.ouvrirConnexion();
    //Conn.openBD();
    if(NUM_PASS== NULL){
        str="SELECT * FROM  transport";
    }

         str="select * from transport where NUM_PASS ="+QString::number(NUM_PASS);
        model->setQuery(str);
    //Conn.fermerConnexion() ;
        return model;

}

