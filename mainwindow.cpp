#include <mainwindow.h>
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{

    ui->setupUi(this);
   int ret=A.connect_arduino();
   switch(ret){
   case(0):qDebug ()<<"arduino is available and connected to :"<<A.getarduino_port_name();
        break;
   case(1):qDebug ()<<"arduino is available but not connected to :"<<A.getarduino_port_name();
       break;
   case(-1):qDebug ()<<"arduino is not  available ";
       break;
   }

   QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
   //le slot update_label suite à la reception du signal readyRead (reception des données).





    ui->tableView->setModel(C.afficher());
    ui->table_recherche->setModel(C.afficher());
}
    MainWindow::~MainWindow()
{
    delete ui;
}
   /*void MainWindow::update_label()
    {
        data=A.read_from_arduino();

        if(data=="1")

            ui->label_3->setText("ON"); // si les données reçues de arduino via la liaison série sont égales à 1
        // alors afficher ON

        else if (data=="0")

            ui->label_3->setText("OFF");   // si les données reçues de arduino via la liaison série sont égales à 0
         //alors afficher ON
    }*/

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
           A.write_to_arduino("0") ;
           /*QSqlQuery query;

               QByteArray message;

               QString ch;



               query.prepare("select TRANSIT from CONTRATCLIENT1 where num_contrat  = "+C.getnum_contrat()+"");
               if (query.exec())
                                   {
                                       while(query.next())
                                       {
                                        ch =query.value(0).toString();

                                       }

                                       message=ch.toUtf8();
                                       A.write_to_arduino("0") ;
                                        A.write_to_arduino(message) ;}





       }
       else{
           QMessageBox::information(nullptr, QObject::tr("database is not open"),
                       QObject::tr("supprimer failed.\n"

                         "Click Cancel to exit."), QMessageBox::Cancel);}*/
       }
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

