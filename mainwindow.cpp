#include <mainwindow.h>
#include "ui_mainwindow.h"
#include "arduino1.h"
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
#include "smtp1.h"
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include <QTextDocument>
#include "excel.h"
#include "chat.h"
#include "notif.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    //tab islem
    ui->tab_employe->setModel(E.afficher());
    int ret=A.connect_arduino();
    switch(ret){
    case(0):qDebug ()<<"arduino is available and connected to :"<<A.getarduino_port_name();
         break;
    case(1):qDebug ()<<"arduino is available but not connected to :"<<A.getarduino_port_name();
        break;
    case(-1):qDebug ()<<"arduino is not  available ";
        break;
        //////////////////////////////
        //islem
        int ret1 =A1.connect_arduino();//lancer la connection to arduino
                switch (ret1) {

                case(0):qDebug()<<"arduino is available and connect to : "<<A1.getarduino_port_name();
                    break;
                case(1):qDebug()<<"arduino is available and not  connect to : "<<A1.getarduino_port_name();
                    break;
                case(-1):qDebug()<<"arduino is not available ";
                    break;}
    }

    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
          QObject::connect(A1.getserial(),SIGNAL(readyRead()),this,SLOT(update_Employ()));
    ui->tableView->setModel(C.afficher());
    ui->table_recherche->setModel(C.afficher());

    ui->table_transport->setModel(T.afficher());
    ui->tableView_2->setModel(L.afficher());
    ui->tableView_historique->setModel(L.afficher_historique());


}
    MainWindow::~MainWindow()
{
    delete ui;
}

    /*void MainWindow::on_pushButton_clicked()
    {
           int NUM_PASS=ui->lineEdit_ID->text().toInt();
           QString nom=ui->lineEdit_prenom->text();
           QString prenom=ui->lineEdit_nom->text();
           transport T(NUM_PASS,nom,prenom);
           bool test=T.ajouter();
           if(test)
           {
               QMessageBox::information(nullptr,QObject::tr("OK"),
                       QObject::tr("Ajout Effectuer"),QMessageBox::Cancel);
                //ui->table_transport->setModel(T.afficher());

           }
           else
           {
               QMessageBox::critical(nullptr,QObject::tr("not OK"),
                       QObject::tr("Ajout non Effectuer"),QMessageBox::Cancel);

           }
    }*/
    void MainWindow::on_pushButton_supprimer_clicked()
    {
        int NUM_PASS=ui->lineEdit_IDS->text().toInt();
        bool test=T.supprimer(NUM_PASS);
       if (test)
        {
            /*QMessageBox::information(nullptr,QObject::tr("OK"),
                    QObject::tr("Suppression Effectuer"),QMessageBox::Cancel);*/
            ui->table_transport->setModel(T.afficher());
        }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("not OK"),
                    QObject::tr("Suppression non Effectuer"),QMessageBox::Cancel);
        }
    }


    /*
    void MainWindow::on_pushButton_modifer_clicked()
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

        }

    }
    */

    void MainWindow::on_pushButton_ajouter_clicked()
    {
        int NUM_PASS=ui->lineEdit_ID->text().toInt();
        QString nom=ui->lineEdit_prenom->text();
        QString prenom=ui->lineEdit_nom->text();
        QString depart=ui->lineEdit_depart->text();
        QString destination=ui->lineEdit_destination->text();
       QString datedepart = ui->dateDepart->dateTime().toString("dd/MM/yyyy");
       QString dateretour = ui->dateRetour->dateTime().toString("dd/MM/yyyy");
        QString datenaissance = ui->dateNaissance->dateTime().toString("dd/MM/yyyy");
        transport T(NUM_PASS,nom,prenom,depart,destination,datedepart,dateretour,datenaissance);
        bool test=T.ajouter();
        if(test)
        {

    ReleaseCapture();

            QMessageBox::information(nullptr,QObject::tr("OK"),
                    QObject::tr("Ajout Effectuer"),QMessageBox::Cancel);
            ReleaseCapture();
             ui->table_transport->setModel(T.afficher());

        }
        else
        {
            ReleaseCapture();
            QMessageBox::critical(nullptr,QObject::tr("not OK"),
                    QObject::tr("Ajout non Effectuer"),QMessageBox::Cancel);
ReleaseCapture();
        }

    }



    /*void MainWindow::on_pushButton_rechercher_clicked()
    {
        QSqlQueryModel * modal= new QSqlQueryModel ();
            QSqlQuery*qry=new QSqlQuery();
            QString NUM_PASS=ui->lineEditR->text();


            if(NUM_PASS.isEmpty())
            {
                ui->table_transport->setModel(T.afficher());

            }
            else
            {
                //
                qry->prepare ("SELECT * from transport where ( NUM_PASS LIKE'%"+NUM_PASS+"%' OR nom LIKE'%"+NUM_PASS+"%' OR prenom LIKE'%"+NUM_PASS+"%') ");
                qry->exec();
                modal->setQuery(*qry);
                ui->table_transport->setModel(modal);
                //qry->prepare("select * from employes where CIN='"+CIN+"'"); //like
                //qry->exec();
                //modal->setQuery(*qry);
                //ui->tableView_3->setModel(modal);
            }
    }
    */


    void MainWindow::on_PDF_clicked()
    {
        QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                             "/home",
                                                             QFileDialog::ShowDirsOnly
                                                             | QFileDialog::DontResolveSymlinks);
                 qDebug()<<dir;
                 QPdfWriter pdf(dir+"/PdfList.pdf");
                                        QPainter painter(&pdf);
                                       int i = 4000;

                                       painter.drawPixmap(QRect(100,100,2000,2000),QPixmap(" C:/users/used/Desktop/t.png"));
                                       painter.drawText(900,650,"Tiny hues");

                                            //painter.drawPixmap(QRect(7600,100,2100,2700),QPixmap("C:/Users/Admin/Desktop/logo.png"));

                                            painter.setPen(Qt::blue);
                                            painter.setFont(QFont("Time New Roman", 25));
                                            painter.drawText(3000,1400,"Liste Des Reservations");
                                            painter.setPen(Qt::black);
                                            painter.setFont(QFont("Time New Roman", 15));
                                            painter.drawRect(100,100,9400,2500);
                                            painter.drawRect(100,3000,9400,500);
                                            painter.setFont(QFont("Time New Roman", 9));
                                            painter.drawText(300,3300,"Numero Passport");
                                            painter.drawText(2300,3300,"Prenom");
                                            painter.drawText(4300,3300,"Nom");
                                            painter.drawText(6300,3300,"Depart");
                                            painter.drawText(7500,3300,"Destination");
                                           /* painter.drawText(8500,3300,"Date Depart");
                                            painter.drawText(9500,3300,"Date Retour");
                                            painter.drawText(10500,3300,"Date Naissance");*/

                                            painter.drawRect(100,3000,9400,10700);


                                            QTextDocument previewDoc;
                                            QString pdflist = QDate::currentDate().toString("'data_'MM_dd_yyyy'.txt'");


                                            QTextCursor cursor(&previewDoc);



                                            QSqlQuery query;
                                            query.prepare("select * from transport");
                                            query.exec();
                                            while (query.next())
                                            {
                                                painter.drawText(300,i,query.value(0).toString());
                                                painter.drawText(2300,i,query.value(1).toString());
                                                painter.drawText(4300,i,query.value(2).toString());
                                                painter.drawText(6300,i,query.value(3).toString());
                                                painter.drawText(7500,i,query.value(4).toString());
                                               /* painter.drawText(8500,i,query.value(5).toString());
                                                painter.drawText(9500,i,query.value(6).toString());
                                                painter.drawText(10500,i,query.value(7).toString());*/




                                               i = i +500;
                                            }
                                            int reponse = QMessageBox::question(this, "Générer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?",
                                                                                QMessageBox::Yes|QMessageBox::No);
                                                if (reponse == QMessageBox::Yes)
                                                {
                                                    QDesktopServices::openUrl(QUrl::fromLocalFile(dir+"/PdfList.pdf"));

                                                    painter.end();
                                                }
                                                else
                                                {
                                                     painter.end();
       }


           }

    /*void MainWindow::on_pushButtonS_clicked()
    {
        statistique s;
            s.exec();
    }
    */
    void MainWindow::on_pushButton_3_clicked()
    {
      system("start C:/Users/used/Desktop/debug/debug/MightyFlighty.exe");
    }


    void MainWindow::on_lineEditR_textChanged(const QString &arg1)
    {
        QSqlQueryModel * modal= new QSqlQueryModel ();
            QSqlQuery*qry=new QSqlQuery();
            QString NUM_PASS=ui->lineEditR->text();


            if(NUM_PASS.isEmpty())
            {
                ui->table_transport->setModel(T.afficher());

            }
            else
            {
                //
                qry->prepare ("SELECT * from transport where ( NUM_PASS LIKE'%"+NUM_PASS+"%' OR nom LIKE'%"+NUM_PASS+"%' OR prenom LIKE'%"+NUM_PASS+"%') ");
                qry->exec();
                modal->setQuery(*qry);
                ui->table_transport->setModel(modal);

            }
    }

    void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
    {
        QSqlQueryModel * model= new QSqlQueryModel ();
                QSqlQuery*qry=new QSqlQuery();
                QString type=ui->comboBox->currentText();
                if (type=="Par defaut")
                {
                    qry->prepare("select * from transport");
                    qry->exec();
                    model->setQuery(*qry);
                    ui->table_transport->setModel(model);
                }
                    else if (type=="Num Pass"){
                    qry->prepare("select * from transport order by NUM_PASS");
                    qry->exec();
                    model->setQuery(*qry);

                        ui->table_transport->setModel(model);


                    }
                    else if (type=="Par Nom"){
                    qry->prepare("select * from transport order by NOM");
                    qry->exec();
                    model->setQuery(*qry);

                    ui->table_transport->setModel(model);


                    }
                    else if (type=="Par Prenom"){
                    qry->prepare("select * from transport order by PRENOM");
                    qry->exec();
                    model->setQuery(*qry);

                        ui->table_transport->setModel(model);


                    }
                    else if (type=="Par Destination"){
                    qry->prepare("select * from transport order by DESTINATION");
                    qry->exec();
                    model->setQuery(*qry);

                        ui->table_transport->setModel(model);
                    }

    }

    void MainWindow::on_Weather_clicked()
    {
        system("start file:///C:/Users/used/Desktop/build-weather-checker-Desktop_Qt_5_9_9_MinGW_32bit-Debug/debug/weather-checker.exe");
    }

void MainWindow::on_pb_ajouter_clicked()
{

  int num_contrat=ui->le_num_contrat->text().toInt();
  QString date_sign=ui->le_date_sign->text();
  QString date_expir=ui->le_date_expir->text();
  QString nom_societe=ui->le_nom_societe->text();
  QString duree_contrat=ui->le_duree_contrat->text();
  QString domaine=ui->le_domaine->text();

  CONTRAT_CLIENT1 C (num_contrat,date_sign,date_expir,nom_societe,duree_contrat,domaine);
  bool test=C.ajouter();
  if(test)
  {
      QMessageBox::information(nullptr,QObject::tr("database is open"),QObject::tr("Ajout effectué\n" "Click Cancel to exit."),QMessageBox::Cancel);
        ui->tableView->setModel(C.afficher());
         A.write_to_arduino("1");
  }

  else
      QMessageBox::critical(nullptr,QObject::tr("data base not open"),QObject::tr("Ajout non effectué.\n" "Click Cancel to exit."));
}

void MainWindow::on_pb_supprimer_clicked()
{

    CONTRAT_CLIENT1 C;
       C.setnum_contrat(ui->lineEdit->text().toInt());
       bool test =C.supprimer(C.getnum_contrat());
       if(test )
       {
           QMessageBox::information(nullptr, QObject::tr("database is open"),
                       QObject::tr("supprimer successful.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);
           ui->tableView->setModel(C.afficher());



       }
       else{
           QMessageBox::information(nullptr, QObject::tr("database is not open"),
                       QObject::tr("supprimer failed.\n"

                         "Click Cancel to exit."), QMessageBox::Cancel);}
       A.write_to_arduino("0") ;
       }



void MainWindow::on_pb_modifier_clicked()
{
    int num_contrat=ui->le_num_contrat_2->text().toInt();
    QString date_sign=ui->le_date_sign_2->text();
    QString date_expir=ui->le_date_expir_2->text();
    QString nom_societe=ui->le_nom_societe_2->text();
    QString duree_contrat=ui->le_duree_contrat_2->text();
    QString domaine=ui->le_domaine_3->text();


    CONTRAT_CLIENT1 C (num_contrat,date_sign,date_expir,nom_societe,duree_contrat,domaine);
    bool test=C.modifier();
                       if(test )
                       {
                           QMessageBox::information(nullptr, QObject::tr("database is open"),
                                       QObject::tr("modifier successful.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
     ui->tableView->setModel(C.afficher());

                       }
                       else{
                           QMessageBox::information(nullptr, QObject::tr("database is not open"),
                                       QObject::tr("modifier failed.\n"

                                         "Click Cancel to exit."), QMessageBox::Cancel);}
                       }



void MainWindow::on_pb_trier_clicked()

    {
        ui->tableView->setModel(C.trier());
    }







void MainWindow::on_pb_chercher_clicked()
{
    QString nom_societe=ui->le_recherche->text();
    if(nom_societe=="")
    {
        QMessageBox::information(nullptr,QObject::tr("Champ vide"),QObject::tr("Veuiller insérer un NOM!"),QMessageBox::Cancel);
        ui->table_recherche->setModel(C.afficher());
    }
    else
    {
        ui->table_recherche->setModel(C.chercher(nom_societe));
    }
    }



void MainWindow::on_pb_mail_clicked()
{
    QString link="https://www.google.com/intl/fr/gmail/about/";
            QDesktopServices::openUrl(link);
}




void MainWindow::on_pb_pdf_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                              "/home",
                                                              QFileDialog::ShowDirsOnly
                                                              | QFileDialog::DontResolveSymlinks);
   qDebug()<<dir;
   QPdfWriter pdf(dir+"/PdfList.pdf");
   QPainter painter(&pdf);
   int i = 4000;

   painter.setPen(Qt::blue);
   painter.setFont(QFont("Time New Roman", 25));
   painter.drawText(3000,1400,"Liste Des contrats");
   painter.setPen(Qt::black);
   painter.setFont(QFont("Time New Roman", 15));
   painter.drawRect(100,100,9400,2500);
   painter.drawRect(100,3000,9400,500);
   painter.setFont(QFont("Time New Roman", 9));
   painter.drawText(300,3300,"num_contrat");
   painter.drawText(2300,3300,"date_sign");
   painter.drawText(4300,3300,"date_expir");
   painter.drawText(6300,3300,"nom_societe");
   painter.drawText(7500,3300,"duree_contrat");
   painter.drawText(8500,3300,"domaine");
   painter.drawRect(100,3000,9400,10700);
   QTextDocument previewDoc;
   QTextCursor cursor(&previewDoc);
   QSqlQuery query;
   query.prepare("select * from CONTRAT_CLIENT1");
   query.exec();
   while (query.next())
   {
   painter.drawText(300,i,query.value(0).toString());
   painter.drawText(2300,i,query.value(1).toString());
   painter.drawText(4300,i,query.value(2).toString());
   painter.drawText(6300,i,query.value(3).toString());
   painter.drawText(7500,i,query.value(4).toString());
   painter.drawText(8500,i,query.value(4).toString());
   i = i +500;
   }
   int reponse = QMessageBox::question(this, "Générer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?",
                                                                              QMessageBox::Yes|QMessageBox::No);
   if (reponse == QMessageBox::Yes)
   {
   QDesktopServices::openUrl(QUrl::fromLocalFile(dir+"/PdfList.pdf"));

   painter.end();
   }
   else
   {
       painter.end();
   }
}






/*void MainWindow::stat()
{
    QSqlQuery q,q1;
    q.prepare("select count(domaine) , niveau from CONTRAT_CLIENT1 group by niveau;");
    q1.prepare("select count(domaine)) from CONTRAT_CLIENT1;");


    ui->progressBar->setValue(0);
    ui->progressBar_2->setValue(0);
    ui->progressBar_3->setValue(0);

    int total;
    if(q.exec())
    if(q1.exec()){
    q1.next();
    total=q1.value(0).toInt();
    while (q.next())
    {
      if( q.value(1).toString().compare("sport")==0)ui->progressBar->setValue(q.value(0).toInt()*100/total);
      if( q.value(1).toString().compare("petrole")==0)ui->progressBar_2->setValue(q.value(0).toInt()*100/total);
      if( q.value(1).toString().compare("informatique")==0)ui->progressBar_3->setValue(q.value(0).toInt()*100/total);
 }
}
}*/

/*void MainWindow::on_pb_stat_clicked()
{
QPieSeries *series = new QPieSeries();


               QStringList list=C.listeadresses("domaine");



               for (int i =0; i< list.size();i++)
               {
                   series->append(list[i],j.calcul_adresses(list[i],"domaine"));

               }
               QPieSlice *slice = series->slices().at(1);
               slice->setLabelVisible();
               slice->setExploded();


               QtCharts::QChart *chart =new QtCharts::QChart();
               chart->addSeries(series);
               chart->setTitle("Statistiques");
               chart->setAnimationOptions(QChart::AllAnimations);
               QChartView *chartview=new QChartView(chart);
               QGridLayout *mainLayout=new QGridLayout();
               mainLayout->addWidget(chartview,0,0);
               ui->statistiques_4->setLayout(mainLayout);


}


/*void MainWindow::on_pb_envoyer_clicked()
{

            smtp = new smtp("//adresse mail//gmail.com" , "//motdepasse de l'adresse", "smtp.gmail.com",465);
            connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

            QString msg=ui->plainTextEdit_contenu_d->toPlainText();

            smtp->sendMail("nom du test_test",ui->le_de->text(),ui->le_objet->text(),msg);

            QMessageBox::information(nullptr, QObject::tr("SENT"),
                                     QObject::tr("Email Sent Successfully.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
        }

*/


void MainWindow::on_pb_sent_clicked()
{
    QString link="https://calendar.google.com/calendar/u/0/r";
    QDesktopServices::openUrl(link);
}


void MainWindow::on_pb_tri_asc_clicked()
{
    ui->tableView->setModel(C.trierASC());

}
/////////////////////////////////////////////////////////
//////////////////////////////////////
/// islem
void MainWindow::on_pb_supprimer_2_clicked()
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
    QString ETAT=ui->le_Etat->text();
        Employe E1(ID , NOM , PRENOM , EMAIL , ETAT);
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


void MainWindow::on_pb_modifier_2_clicked()
{
   // Employe E2;
    int ID=ui->le_id_2->text().toInt();
    QString NOM=ui->le_Nom_2->text();
    QString PRENOM=ui->le_Prenom_2->text();
    QString EMAIL=ui->le_Mail_2->text();
    QString ETAT=ui->le_Etat_2->text();

        Employe E2(ID,NOM,PRENOM,EMAIL,ETAT);
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

    Employe E;
      ui->tab_employe->setModel(E.Rechercher(ui->le_rech->text()));
}


void MainWindow::on_pb_trier_2_clicked()
{

     ui->tab_employe->setModel(E.tri());
}

void MainWindow::on_pb_pdf_2_clicked()
{
    /*QString strStream;
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
               document->print(&printer);*/


    QString strStream;
    QTextStream out(&strStream);

     const int rowCount = ui->tab_employe->model()->rowCount();
     const int columnCount = ui->tab_employe->model()->columnCount();
    out <<  "<html>\n"
    "<head>\n"
                     "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                     <<  QString("<title>%1</title>\n").arg("strTitle")
                     <<  "</head>\n"
                     "<body bgcolor=#ffffff link=#5000A0>\n"

                    //     "<align='right'> " << datefich << "</align>"
                     "<center> <H1>Liste des Employees </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                 // headers
                 out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                 for (int column = 0; column < columnCount; column++)
                     if (!ui->tab_employe->isColumnHidden(column))
                         out << QString("<th>%1</th>").arg(ui->tab_employe->model()->headerData(column, Qt::Horizontal).toString());
                 out << "</tr></thead>\n";

                 // data table
                 for (int row = 0; row < rowCount; row++) {
                     out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                     for (int column = 0; column < columnCount; column++) {
                         if (!ui->tab_employe->isColumnHidden(column)) {
                             QString data = ui->tab_employe->model()->data(ui->tab_employe->model()->index(row, column)).toString().simplified();
                             out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                         }
                     }
                     out << "</tr>\n";
                 }
                 out <<  "</table> </center>\n"
                     "</body>\n"
                     "</html>\n";

           QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
             if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

            QPrinter printer (QPrinter::PrinterResolution);
             printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setPaperSize(QPrinter::A4);
           printer.setOutputFileName(fileName);

            QTextDocument doc;
             doc.setHtml(strStream);
             doc.setPageSize(printer.pageRect().size());
             doc.print(&printer);

}

void MainWindow::on_pb_excel_3_clicked()
{

    //exportation
        QString fileName = QFileDialog::getSaveFileName(this, tr("Exportation en fichier Excel islem "), qApp->applicationDirPath (),
                                                                  tr("Fichiers d'extension Excel (*.xls)"));
                  if (fileName.isEmpty())
                      return;

                  EXCEL obj(fileName, "GEST_EMPLOYE", ui->tab_employe);

                  // you can change the column order and
                  // choose which colum to export
                  obj.addField(0, "ID",    "number");
                  obj.addField(1, "NOM", "char(20)");
                  obj.addField(2, "PRENOM", "char(20)");
                  obj.addField(3, "EMAIL", "char(20)");
                  obj.addField(4, "ETAT", "char(20)");




                  int retVal = obj.export2Excel();

                  if( retVal > 0)
                  {
                      QMessageBox::information(this, tr("FAIS!"),
                                               QString(tr("%1 enregistrements exportées!")).arg(retVal)
                                               );
                  }
}

/*void MainWindow::on_pB_sts_2_clicked()
{
    dialog_mailing mail;
        mail.setModal(true);
        mail.exec();
}*/

void MainWindow::on_pb_chat_clicked()
{
   Chat ch;
   ch.setModal(true);
   ch.exec();
}
/////////////////////////////////////////////////////////////////////////////////////////////////

/// //////////////////////////////////////////////////////////////////////////////////
///islem
void MainWindow::on_pushButton_send_clicked()
{
    smtp1 = new Smtp1("tinyyhues@gmail.com" , "yovwlwapvanzgdqz", "smtp1.gmail.com",465);
    connect(smtp1, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    msg=ui->message_mail->toPlainText();

    smtp1->sendMail("ilyes_test",ui->a_mail->text(),ui->objet_mail->text(),msg);

    QMessageBox::information(nullptr, QObject::tr("SENT"),
                             QObject::tr("Email Sended Successfully.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
}
/////////////////////////////////////////////////////////////////////////


void MainWindow::update_Employ()
{

Employe e ;
    data=A1.read_from_arduino();

   if (data=="1"){
        e.modifierEtat(1,"present");
          ui->label_2->setText("Welcome amine");
          ui->tab_employe->setModel(e.afficher());

   }
   if (data=="2"){
        e.modifierEtat(2,"present");
        ui->label_2->setText("Welcome Ahmed");
        ui->tab_employe->setModel(e.afficher());


   }
   if (data=="0"){
       ui->label_2->setText("Acces Denied");

   }
}


void MainWindow::on_pushButton_modif_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    int idc = ui->lineEdit_idc_2->text().toInt();
    int idh = ui->lineEdit_idh_2->text().toInt();
    QDate d = ui->dateEdit_date_2->date();
    QString adr = ui->lineEdit_adresse_2->text();

    Logement l(idc,idh,adr,d);
    l.setId(id);
    bool test = l.modifier();
    if(test)
            {
        notif m("Logement","logement Modifer");
        L.ajouter_historique("logement modifie");
        m.afficher();
         L.notification("gestion logements","logement modifié");
        ui->tableView_2->setModel(L.afficher());
        ui->tableView_historique->setModel(L.afficher_historique());

                QMessageBox::information(nullptr, QObject::tr("modif logement"),
                                         QObject::tr("logement modifie.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("Ajouter logement"),
                                      QObject::tr("Erreur !.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_supprimer_2_clicked()
{
    int id=ui->tableView_2->model()->data(ui->tableView_2->model()->index(ui->tableView_2->currentIndex().row(),0)).toInt();
    bool test = L.supprimer(id);
    if(test)
            {
            notif m("Logement","logement Supprimer");
            L.ajouter_historique("logement supprime");
            m.afficher();

        ui->tableView_2->setModel(L.afficher());
        ui->tableView_historique->setModel(L.afficher_historique());

                QMessageBox::information(nullptr, QObject::tr("supprimer logement"),
                                         QObject::tr("logement supprimé.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("supprimer logement"),
                                      QObject::tr("Erreur !.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_2_clicked()
{
    QString strStream;
                      QTextStream out(&strStream);

                       const int rowCount = ui->tableView_2->model()->rowCount();
                       const int columnCount = ui->tableView_2->model()->columnCount();
                      out <<  "<html>\n"
                      "<head>\n"
                                       "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                       <<  QString("<title>%1</title>\n").arg("strTitle")
                                       <<  "</head>\n"
                                       "<body bgcolor=#ffffff link=#5000A0>\n"

                                      //     "<align='right'> " << datefich << "</align>"
                                       "<center> <H1>Liste des logements</H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                                   // headers
                                   out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                                   out<<"<cellspacing=10 cellpadding=3>";
                                   for (int column = 0; column < columnCount; column++)
                                       if (!ui->tableView_2->isColumnHidden(column))
                                           out << QString("<th>%1</th>").arg(ui->tableView_2->model()->headerData(column, Qt::Horizontal).toString());
                                   out << "</tr></thead>\n";

                                   // data table
                                   for (int row = 0; row < rowCount; row++) {
                                       out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                       for (int column = 0; column < columnCount; column++) {
                                           if (!ui->tableView_2->isColumnHidden(column)) {
                                               QString data = ui->tableView_2->model()->data(ui->tableView_2->model()->index(row, column)).toString().simplified();
                                               out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                           }
                                       }
                                       out << "</tr>\n";
                                   }
                                   out <<  "</table> </center>\n"
                                       "</body>\n"
                                       "</html>\n";

                             QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                               if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                              QPrinter printer (QPrinter::PrinterResolution);
                               printer.setOutputFormat(QPrinter::PdfFormat);
                            //  printer.setPaperSize(QPrinter::A4);
                             printer.setOutputFileName(fileName);

                              QTextDocument doc;
                               doc.setHtml(strStream);
                               //doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                               doc.print(&printer);
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    ui->tableView_2->setModel(L.recherche(arg1));

}

void MainWindow::on_radioButton_clicked()
{
    ui->tableView_2->setModel(L.tri_idh());

}

void MainWindow::on_radioButton_2_clicked()
{
    ui->tableView_2->setModel(L.tri_idc());

}

void MainWindow::on_radioButton_3_clicked()
{
    ui->tableView_2->setModel(L.tri_adr());

}

void MainWindow::on_pushButton_send_2_clicked()
{
    smtp = new Smtp("service.logement.contact@gmail.com" , "fxxdjttitpklrnkn", "smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    msg=ui->message_mail->toPlainText();

    smtp->sendMail("ilyes_test",ui->a_mail->text(),ui->objet_mail->text(),msg);

    QMessageBox::information(nullptr, QObject::tr("SENT"),
                             QObject::tr("Email Sended Successfully.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_supprimer_3_clicked()
{
    int id=ui->tableView_historique->model()->data(ui->tableView_historique->model()->index(ui->tableView_historique->currentIndex().row(),0)).toInt();
    bool test = L.supprimer_historique(id);
    if(test)
            {
            notif m("historique","historique Supprimer");
            m.afficher();

        ui->tableView_2->setModel(L.afficher());
        ui->tableView_historique->setModel(L.afficher_historique());

                QMessageBox::information(nullptr, QObject::tr("supprimer historique"),
                                         QObject::tr("historique supprimé.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("supprimer historique"),
                                      QObject::tr("Erreur !.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_4_clicked()
{
    int idc = ui->lineEdit_idc->text().toInt();
    int idh = ui->lineEdit_idh->text().toInt();
    QDate d = ui->dateEdit_date->date();
    QString adr = ui->lineEdit_adresse->text();

    Logement l(idc,idh,adr,d);
    if(adr.isEmpty())
                     {
                         QMessageBox::critical(0,qApp->tr("ERREUR"),qApp->tr("veillez remplir les champs vides."),QMessageBox::Cancel);
                     }
    else{
    bool test = l.ajouter();
    if(test)
            {
        notif m("Logement","logement Ajouter");
        L.ajouter_historique("logement ajoute");
        m.afficher();
        ui->tableView_2->setModel(L.afficher());
        ui->tableView_historique->setModel(L.afficher_historique());

                QMessageBox::information(nullptr, QObject::tr("Ajouter logement"),
                                         QObject::tr("logement ajoutée.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("Ajouter logement"),
                                      QObject::tr("Erreur !.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);

}
}


