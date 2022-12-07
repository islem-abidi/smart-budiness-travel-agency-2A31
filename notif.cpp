#include "notif.h"
#include <QSystemTrayIcon>
#include<QString>
notif::notif()
{
    num=0;
}
notif::notif(QString titre,QString text)
{
  this->text=text;
    this->titre=titre;
}

void notif::afficher()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->setIcon(QIcon("C:/Users/maram/OneDrive/Bureau/integrrr/smart-business-travel-agency-2A31_islem_/smart-business-travel-agency-2A31/noti/a.png"));
    notifyIcon->show();;
    notifyIcon->showMessage(titre,text,QSystemTrayIcon::Information,15000);
}

