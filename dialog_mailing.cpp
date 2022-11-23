#include "dialog_mailing.h"
#include "ui_dialog_mailing.h"
#include "smtp.h"
#include <QMessageBox>
dialog_mailing::dialog_mailing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_mailing)
{
    ui->setupUi(this);
    connect(ui->envoyer_dialog, SIGNAL(clicked()),this, SLOT(sendMail()));
        connect(ui->annuler_mail, SIGNAL(clicked()),this, SLOT(close()));
}

dialog_mailing::~dialog_mailing()
{
    delete ui;
}
dialog_mailing::dialog_mailing(QString e,QString n,QString s,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_mailing)
{
    QString contenu="Contenu";
    ui->setupUi(this);

    ui->recipient->setText(e);
    ui->uname_2->setText("tinyyhues@gmail.com");
    ui->passwd->setText("yovwlwapvanzgdqz");
    ui->passwd->setEchoMode(QLineEdit::Password);

    if (s=="Homme")
    {
        ui->message->setText("Cher Monsieur "+n+",\n\n"+contenu+"\n\n"+"Cordialement,\n");
    }
    else if (s=="Femme")
    {
        ui->message->setText("Chère Madame "+n+",\n\n"+contenu+"\n\n"+"Cordialement,\n");
    }

}
/*void dialog_mailing::on_envoyer_dialog_2_clicked()
{QString status;
    Smtp* smtp = new Smtp(ui->uname_2->text(), ui->passwd->text(), "smtp.gmail.com", 465); //smtp.gmail.com

    smtp->sendMail(ui->uname_2->text(), ui->recipient->text() , ui->subjectLineEdit->text() ,ui->message->toPlainText());

    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}*/


void dialog_mailing::on_envoyer_dialog_clicked()
{
    QString status;
        Smtp* smtp = new Smtp(ui->uname_2->text(), ui->passwd->text(), "smtp.gmail.com", 465); //smtp.gmail.com

        smtp->sendMail(ui->uname_2->text(), ui->recipient->text() , ui->subjectLineEdit->text() ,ui->message->toPlainText());

        if(status == "Message sent")
            QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}
