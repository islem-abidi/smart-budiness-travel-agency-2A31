#include "connexion.h"

  Connexion::Connexion()
{

}

bool Connexion::createconnect()
{
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Facture");
    db.setUserName("SYSTEM");//inserer nom de l'utilisateur
    db.setPassword("211JFT6577");//inserer mot de passe de cet utilisateur

    if (db.open())
     test=true;





        return  test;

}
