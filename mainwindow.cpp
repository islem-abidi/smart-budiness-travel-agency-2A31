#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logement.h"
#include "notif.h"
#include <QMessageBox>
#include <QDesktopServices>
#include <QFileDialog>
#include <QPrinter>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(L.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int idc = ui->lineEdit_idc->text().toInt();
    int idh = ui->lineEdit_idh->text().toInt();
    QDate d = ui->dateEdit_date->date();
    QString adr = ui->lineEdit_adresse->text();

    Logement l(idc,idh,adr,d);
    bool test = l.ajouter();
    if(test)
            {
        notif m("Logement","logement Ajouter");
        m.afficher();
        ui->tableView->setModel(L.afficher());
                QMessageBox::information(nullptr, QObject::tr("Ajouter logement"),
                                         QObject::tr("logement ajoutée.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("Ajouter logement"),
                                      QObject::tr("Erreur !.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);

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
        m.afficher();
         L.notification("gestion logements","logement modifié");
        ui->tableView->setModel(L.afficher());
                QMessageBox::information(nullptr, QObject::tr("modif logement"),
                                         QObject::tr("logement modifie.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("Ajouter logement"),
                                      QObject::tr("Erreur !.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_pushButton_supprimer_clicked()
{
    int id=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0)).toInt();
    bool test = L.supprimer(id);
    if(test)
            {
            notif m("Logement","logement Supprimer");
            m.afficher();

        ui->tableView->setModel(L.afficher());
                QMessageBox::information(nullptr, QObject::tr("supprimer logement"),
                                         QObject::tr("logement supprimé.\n"
                                                     "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("supprimer logement"),
                                      QObject::tr("Erreur !.\n"
                                                  "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    QString id=ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->currentIndex().row(),0)).toString();
    ui->lineEdit_id->setText(id);
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
     ui->tableView->setModel(L.recherche(arg1));
}


void MainWindow::on_radioButton_clicked()
{
    ui->tableView->setModel(L.tri_idh());
}


void MainWindow::on_radioButton_2_clicked()
{
    ui->tableView->setModel(L.tri_idc());
}


void MainWindow::on_radioButton_3_clicked()
{
    ui->tableView->setModel(L.tri_adr());
}


void MainWindow::on_pushButton_2_clicked()
{
    QString strStream;
                      QTextStream out(&strStream);

                       const int rowCount = ui->tableView->model()->rowCount();
                       const int columnCount = ui->tableView->model()->columnCount();
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
                                       if (!ui->tableView->isColumnHidden(column))
                                           out << QString("<th>%1</th>").arg(ui->tableView->model()->headerData(column, Qt::Horizontal).toString());
                                   out << "</tr></thead>\n";

                                   // data table
                                   for (int row = 0; row < rowCount; row++) {
                                       out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                       for (int column = 0; column < columnCount; column++) {
                                           if (!ui->tableView->isColumnHidden(column)) {
                                               QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
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


void MainWindow::on_pushButton_send_clicked()
{
    smtp = new Smtp("service.logement.contact@gmail.com" , "fxxdjttitpklrnkn", "smtp.gmail.com",465);
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    msg=ui->message_mail->toPlainText();

    smtp->sendMail("ilyes_test",ui->a_mail->text(),ui->objet_mail->text(),msg);

    QMessageBox::information(nullptr, QObject::tr("SENT"),
                             QObject::tr("Email Sended Successfully.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
}

