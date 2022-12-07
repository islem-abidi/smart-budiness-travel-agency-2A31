#include "connexion.h"

  Connexion::Connexion()
{

}

bool Connexion::createconnect()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("2A_projet");
    db.setUserName("system");//inserer nom de l'utilisateur
    db.setPassword("muhamedaliclay13022002");//inserer mot de passe de cet utilisateur

    if (db.open())
     test=true;





        return  test;

}
