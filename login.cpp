#include "login.h"
#include "contrat_client.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pb_connecter_clicked()
{
      QString nom_utilisateur=ui->le_nom->text();
      QString mdp=ui-> le_mdp->text();
      QSqlQuery query;
      query.prepare("select * from EMPLOYÉS where ID_EMPLOYE=:ID_EMPLOYE and mdp=:mdp");
      query.addBindValue(ui->le_nom->text());
      query.addBindValue(ui-> le_mdp->text());
      query.exec();
          bool alreadyExist = false;
          alreadyExist = query.next();
          if(alreadyExist)
          {

                ui->le_nom->setText("");
                ui->le_mdp->setText("");
                this->hide();
                M=new MainWindow(this);
                M->show();
                //CONTRAT_CLIENT1 C;




               /*QMessageBox msgbox ;
               msgbox.setText("Bienvenue "+C.getnom_societe+"") ;
               msgbox.exec() ;*/



          }
          else
              {
              QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                                               QObject::tr("NOM D'UTILISATEUR OU MOT DE PASSE INCORRECTE.\n" "Click Cancel to exit."), QMessageBox::Cancel);
              ui->le_nom->setText("");
              ui->le_mdp->setText("");
               }


}

