#include "logement.h"

Logement::Logement()
{

}

Logement::Logement(int idc,int idh,QString adr,QDate d){
    this->id = id;
    this->id_client = idc;
    this->id_hotel = idh;
    this->adresse = adr;
    date_log = d;
}


bool Logement::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("INSERT INTO LOGEMENT (id_hotel, id_client,adresse,date_log) "
                  "VALUES (:id_hotel, :id_client,:adresse,:date_log)");
    query.bindValue(":id_hotel", id_hotel);
    query.bindValue(":id_client", id_client);
    query.bindValue(":adresse", adresse);
    query.bindValue(":date_log", date_log);

    return    query.exec();
}


bool Logement::ajouter_historique(QString n)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("INSERT INTO HISTORIQUE (nom, date_op) "
                  "VALUES (:nom, :date_op)");
    query.bindValue(":nom", n);
    query.bindValue(":date_op", QDateTime::currentDateTime());

    return    query.exec();
}

QSqlQueryModel * Logement::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from LOGEMENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_hotel"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("id_client"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_log"));


    return model;
}



QSqlQueryModel * Logement::afficher_historique()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from HISTORIQUE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date"));


    return model;
}



QSqlQueryModel * Logement::tri_adr()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from LOGEMENT ORDER BY adresse");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_hotel"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("id_client"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_log"));


    return model;
}

QSqlQueryModel * Logement::tri_idc()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from LOGEMENT ORDER BY id_client");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_hotel"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("id_client"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_log"));


    return model;
}


QSqlQueryModel * Logement::tri_idh()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from LOGEMENT ORDER BY id_hotel");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_hotel"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("id_client"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_log"));


    return model;
}


QSqlQueryModel * Logement::recherche(QString a)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from LOGEMENT WHERE id_hotel LIKE '%"+a+"%' OR date_log LIKE '%"+a+"%' OR adresse LIKE '%"+a+"%'");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_hotel"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("id_client"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_log"));


    return model;
}

bool Logement::supprimer(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("Delete from LOGEMENT where ID = :id ");
    query.bindValue(":id", res);
    return    query.exec();
}

bool Logement::supprimer_historique(int idd)
{
    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("Delete from HISTORIQUE where ID = :id ");
    query.bindValue(":id", res);
    return    query.exec();
}


void Logement::setId(int id){
    this->id= id;
}

bool Logement::modifier()
{   QSqlQuery query;
    query.prepare( "UPDATE LOGEMENT SET id_hotel=:id_hotel,id_client=:id_client,adresse=:adresse,date_log=:date_log WHERE ID=:id");
    query.bindValue(":id",id);
    query.bindValue(":id_hotel",id_hotel);
    query.bindValue(":id_client",id_client);
    query.bindValue(":adresse",adresse);
    query.bindValue(":date_log", date_log);



    return query.exec();
}

void Logement::notification(QString title,QString body){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->setVisible(true);
   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des Promotions ","Un Promotion est modifiée",QSystemTrayIcon::Information,15000);
    notifyIcon->setVisible(true);

}

/*  QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des Promotions ","Nouvelle Promotion ajoutée ",QSystemTrayIcon::Information,15000);*/
