#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTableView>
#include "employe.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QDialog>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDialog>
#include <QDesktopWidget>
#include <QSettings>
#include <QPrinter>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include <QTextDocument>
#include "excel.h"
#include <dialog_mailing.h>
#include "chat.h"
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

        Employe E1(ID , NOM , PRENOM , EMAIL);
        bool test=E1.ajouter();
         QMessageBox msgBox;
         if(test)
            { msgBox.setText("ajout avec succes.");
              ui->tab_employe->setModel(E.afficher());

         }
         else
             msgBox.setText("Echec de lajout");
         msgBox.exec();
}
////////////////////////////////////////////////////////////////////////////////////////////


void MainWindow::on_pb_modifier_clicked()
{
   // Employe E2;
    int ID=ui->le_id_2->text().toInt();
    QString NOM=ui->le_Nom_2->text();
    QString PRENOM=ui->le_Prenom_2->text();
    QString EMAIL=ui->le_Mail_2->text();

        Employe E2(ID,NOM,PRENOM,EMAIL);
        bool test=E2.modifier(ID);
        if(test)
           {

            ui->tab_employe->setModel(E2.afficher());//refresh

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


void MainWindow::on_pb_rechercher_clicked()
{
   /* QString marque=ui->le_id->text();

    if(marque.isEmpty())
            {
                QMessageBox::critical(0,qApp->tr("erreur"),
                                      qApp->tr("veillez remplir le champs vide"),QMessageBox::Cancel);
            }
        else
        {

        ui->tab_employe->setModel(E.Rechercher(E.Get_id()));

           }*/
    Employe E;
      ui->tab_employe->setModel(E.Rechercher(ui->le_rech->text()));
}


void MainWindow::on_pb_trier_clicked()
{
   /* QString modele=ui->le_Nom->text();

    if(modele.isEmpty())
            {
                QMessageBox::critical(0,qApp->tr("erreur"),
                                      qApp->tr("veillez remplir le champs vide"),QMessageBox::Cancel);
            }
        else
        {

        ui->tab_employe->setModel(E.tri(E.Get_nom()));
    }*/
     ui->tab_employe->setModel(E.tri());
}
/*
QString strStream;
                   QTextStream out(&strStream);
                   const int rowCount = ui->tab_employe->model()->rowCount();
                   const int columnCount =ui->tab_employe->model()->columnCount();


                   out <<  "<html>\n"
                           "<head>\n"
                           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                           <<  QString("<title>%1</title>\n").arg("eleve")
                           <<  "</head>\n"
                           "<body bgcolor=#CFC4E1 link=#5000A0>\n"
                               "<h1>Liste des voyageurs</h1>"

                               "<table border=1 cellspacing=0 cellpadding=2>\n";

                   // headers
                       out << "<thead><tr bgcolor=#f0f0f0>";
                       for (int column = 0; column < columnCount; column++)
                           if (!ui->tableView->isColumnHidden(column))
                               out << QString("<th>%1</th>").arg(ui->tab_employe->model()->headerData(column, Qt::Horizontal).toString());
                       out << "</tr></thead>\n";
                       // data table
                          for (int row = 0; row < rowCount; row++) {
                              out << "<tr>";
                              for (int column = 0; column < columnCount; column++) {
                                  if (!ui->tab_employe->isColumnHidden(column)) {
                                      QString data = ui->tab_employe->model()->data(ui->tab_employe->model()->index(row, column)).toString().simplified();
                                      out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                  }
                              }
                              out << "</tr>\n";
                          }
                          out <<  "</table>\n"
                              "</body>\n"
                              "</html>\n";



         QTextDocument *document = new QTextDocument();
         document->setHtml(strStream);


          // QTextDocument *document;
             //  document->setHtml(strStream);
         //  document->setHtml(html);
           QPrinter printer(QPrinter::PrinterResolution);
           printer.setOutputFormat(QPrinter::PdfFormat);
           printer.setOutputFileName("mypdffile.pdf");
           document->print(&printer);
*/
void MainWindow::on_pb_pdf_clicked()
{
    QString strStream;
                       QTextStream out(&strStream);
                       const int rowCount = ui->tab_employe->model()->rowCount();
                       const int columnCount =ui->tab_employe->model()->columnCount();


                       out <<  "<html>\n"
                               "<head>\n"
                               "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                               <<  QString("<title>%1</title>\n").arg("eleve")
                               <<  "</head>\n"
                               "<body bgcolor=#CFC4E1 link=#5000A0>\n"
                                   "<h1>Liste des employés</h1>"

                                   "<table border=1 cellspacing=0 cellpadding=2>\n";

                       // headers
                           out << "<thead><tr bgcolor=#f0f0f0>";
                           for (int column = 0; column < columnCount; column++)
                               if (!ui->tab_employe->isColumnHidden(column))
                                   out << QString("<th>%1</th>").arg(ui->tab_employe->model()->headerData(column, Qt::Horizontal).toString());
                           out << "</tr></thead>\n";
                           // data table
                              for (int row = 0; row < rowCount; row++) {
                                  out << "<tr>";
                                  for (int column = 0; column < columnCount; column++) {
                                      if (!ui->tab_employe->isColumnHidden(column)) {
                                          QString data = ui->tab_employe->model()->data(ui->tab_employe->model()->index(row, column)).toString().simplified();
                                          out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                      }
                                  }
                                  out << "</tr>\n";
                              }
                              out <<  "</table>\n"
                                  "</body>\n"
                                  "</html>\n";



             QTextDocument *document = new QTextDocument();
             document->setHtml(strStream);


              // QTextDocument *document;
                 //  document->setHtml(strStream);
             //  document->setHtml(html);
               QPrinter printer(QPrinter::PrinterResolution);
               printer.setOutputFormat(QPrinter::PdfFormat);
               printer.setOutputFileName("mypdffile.pdf");
               document->print(&printer);
}
/*
QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                            tr("Excel Files (*.xls)"));
            if (fileName.isEmpty())
                return;

            ExportExcelObject obj(fileName, "mydata", ui->tab_employe);

            obj.addField(0, "ID", "char(20)");
            obj.addField(1, "NOM", "char(20)");
            obj.addField(2, "PRENOM", "char(20)");
            obj.addField(3, "EMAIL", "char(20)");




            int retVal = obj.export2Excel();

            if( retVal > 0)
            {
                QMessageBox::information(this, tr("Done"),
                                         QString(tr("%1 records exported!")).arg(retVal)
                                         );
            }
*/
void MainWindow::on_pb_excel_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                                tr("Excel Files (*.xls)"));
                if (fileName.isEmpty())
                    return;

                ExportExcelObject obj(fileName, "mydata", ui->tab_employe);

                obj.addField(0, "ID", "char(20)");
                obj.addField(1, "NOM", "char(20)");
                obj.addField(2, "PRENOM", "char(20)");
                obj.addField(3, "EMAIL", "char(20)");




                int retVal = obj.export2Excel();

                if( retVal > 0)
                {
                    QMessageBox::information(this, tr("Done"),
                                             QString(tr("%1 records exported!")).arg(retVal)
                                             );
                }
}

void MainWindow::on_pB_sts_2_clicked()
{
    dialog_mailing mail;
        mail.setModal(true);
        mail.exec();
}

void MainWindow::on_pb_chat_clicked()
{
   Chat ch;
   ch.setModal(true);
   ch.exec();
}
