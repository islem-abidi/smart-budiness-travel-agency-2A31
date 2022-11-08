#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include <QMessageBox>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_employe->setModel(E.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pb_supprimer_clicked()
{
  Employe E1; E1.Set_id(ui->le_id_supp->text().toInt());
  bool test=E1.supprimer(E1.Get_id());
  QMessageBox msgBox;
  if(test)
  {msgBox.setText("Suppression avec succes.");
  ui->tab_employe->setModel(E.afficher());
   ui->le_id_supp->clear();
  }
  else
      msgBox.setText("Echec de suppression");
  msgBox.exec();
}

void MainWindow::on_pb_ajoutter_clicked()
{
    int ID=ui->le_id->text().toInt();
    QString NOM=ui->le_Nom->text();
    QString PRENOM=ui->le_Prenom->text();

    QString EMAIL=ui->le_Mail->text();

        Employe(ID , NOM , PRENOM , EMAIL);
        bool test=E.ajouter();
         QMessageBox msgBox;
         if(test)
            { msgBox.setText("ajout avec succes.");
              ui->tab_employe->setModel(E.afficher());
              ui->le_id->clear();
              ui->le_Nom->clear();
              ui->le_Prenom->clear();
              ui->le_Mail->clear();
         }
         else
             msgBox.setText("Echec de lajout");
         msgBox.exec();
}
////////////////////////////////////////////////////////////////////////////////////////////


void MainWindow::on_pb_modifier_clicked()
{
    Employe E2;
    int ID=ui->le_id_2->text().toInt();
    QString NOM=ui->le_Nom_2->text();
    QString PRENOM=ui->le_Prenom_2->text();
    QString EMAIL=ui->le_Mail_2->text();

        Employe(ID,NOM,PRENOM,EMAIL);
        bool test=E2.modifier(ID);
        if(test)
           {

            ui->tab_employe->setModel(E2.afficher());//refresh
                    ui->le_id_2->clear();
                    ui->le_Nom_2->clear();
                    ui->le_Prenom_2->clear();
                    ui->le_Mail_2->clear();
                QMessageBox::information(nullptr, QObject::tr("Modifier un EMPLOYE "),
                                  QObject::tr("EMPLOYE modifié.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);

        }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("not OK"),
                QObject::tr("modification non Effectuer"),QMessageBox::Cancel);
               }


}


/*void MainWindow::on_pushButton_modifer_clicked()
{
    int NUM_PASS=ui->modID->text().toInt();
    QString nom=ui->modNOM->text();
    QString prenom=ui->modPRENOM->text();
    transport T(NUM_PASS,nom,prenom);
    bool test=T.modifier(NUM_PASS);
    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr("modification Effectuer"),QMessageBox::Cancel);
         //ui->table_etudiant->setModel(Etmp.modifier());


    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("not OK"),
                QObject::tr("modification non Effectuer"),QMessageBox::Cancel);

    }*/
