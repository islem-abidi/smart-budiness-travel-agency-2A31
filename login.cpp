
#include "login.h"
#include "contrat_client.h"
#include "ui_login.h"
#include "arduino.h"
#include "employees.h"
Employees currentEmp;
QString cardUID="";
QString test="";
int yo=0;


QTimer *timerAuthRfid = new QTimer();



login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

   int ret=AE.connect_arduino(); // lancer la connexion à arduino
        switch(ret){
        case(0):qDebug()<< "arduino is available and connected to : "<< AE.getarduino_port_name();
            break;
        case(1):qDebug() << "arduino is available but not connected to :" <<AE.getarduino_port_name();
           break;
        case(-1):qDebug() << "arduino is not available";
        }
         QObject::connect(AE.getserial(),SIGNAL(readyRead()),this,SLOT(getCardUid())); // permet de lancer
         //le slot update_label suite à la reception du signal readyRead (reception des données).

   this->setAttribute(Qt::WA_DeleteOnClose);

    connect(timerAuthRfid, SIGNAL(timeout()), this, SLOT(authRFID()));
yo=0;
}

login::~login()
{
    delete ui;
}

/*void login::on_pb_connecter_clicked()
{
    QString email = ui->login_email->text();
    QString password = ui->login_password->text();

    if(email == "" && password == ""){
        QMessageBox::critical(nullptr, QObject::tr("login status"),QObject::tr("please fill the email and password input.\nClick Cancel to exit."), QMessageBox::Cancel);
    }else {
        Employees e(email.toLower(),password);

    //    qDebug()<< e.authEmp();
        if(e.authEmp()){
            QSqlQuery emp = e.afficherEmp(email.toLower());
            emp.next();
            qDebug()<< emp.value(0).toString();
            Employees test(emp.value(0).toInt(), emp.value(2).toString(), emp.value(1).toString(), emp.value(7).toString(), emp.value(8).toString(), emp.value(9).toString(), emp.value(3).toInt(), emp.value(8).toInt(), emp.value(6).toString());
            currentEmp = test;
            int you;
            you=AE.close_arduino();
            qDebug()<<"testt ="<<you;
                this->close();
                //GestionEmp gEmp;
                Integration integ;
                integ.show();
                QEventLoop loop;

                disconnect(timerAuthRfid, SIGNAL(timeout()), this, SLOT(authRFID()));
                yo=0;

                connect(&integ, SIGNAL(closed()), &loop, SLOT(quit()));

                loop.exec();
        }else {
            QMessageBox::critical(nullptr, QObject::tr("login status"),QObject::tr("email or password are incorrect.\nClick Cancel to exit."), QMessageBox::Cancel);
        }


    }

}*/
void login::getCardUid()
{
    if(yo==1){
        timerAuthRfid->start(100);
    }
    data=AE.read_from_arduino();
    //test = data;

    test = "D1 3E 15 1A";
    if(test.length() <11){
        test += data;
    }

    if(test.length() ==11){
//        qDebug()<<test;
        cardUID = test;
        test="";
    }
//qDebug()<<test;}

}


void login::on_loginButton_clicked()
{
    QString email = ui->login_email->text();
    QString password = ui->login_password->text();

    if(email == "" && password == ""){
        QMessageBox::critical(nullptr, QObject::tr("login status"),QObject::tr("please fill the email and password input.\nClick Cancel to exit."), QMessageBox::Cancel);
    }else {
        Employees e(email.toLower(),password);

    //    qDebug()<< e.authEmp();
        if(e.authEmp()){
            QSqlQuery emp = e.afficherEmp(email.toLower());
            emp.next();
            qDebug()<< emp.value(0).toString();
            Employees test(emp.value(0).toInt(), emp.value(2).toString(), emp.value(1).toString(), emp.value(7).toString(), emp.value(8).toString(), emp.value(9).toString(), emp.value(3).toInt(), emp.value(8).toInt(), emp.value(6).toString());
            currentEmp = test;
            int you;
            you=AE.close_arduino();
            qDebug()<<"testt ="<<you;
                this->close();
                //GestionEmp gEmp;
                MainWindow M;
                M.show();
                QEventLoop loop;

                disconnect(timerAuthRfid, SIGNAL(timeout()), this, SLOT(authRFID()));
                yo=0;

                connect(&M, SIGNAL(closed()), &loop, SLOT(quit()));

                loop.exec();
        }else {
            QMessageBox::critical(nullptr, QObject::tr("login status"),QObject::tr("email or password are incorrect.\nClick Cancel to exit."), QMessageBox::Cancel);
            QSqlQuery q;
            int x=rand()%1000;
            q.prepare("INSERT INTO COMPTE(email) values (:email)");
            q.bindValue(":email",x);
            q.exec();
            AE.write_to_arduino("1");

        }


    }
}
void login::authRFID()
{
//    qDebug()<<cardUID;
    Employees e(cardUID);
    qDebug()<<e.getCard();

    if(e.authEmpCardRfid()){
        disconnect(timerAuthRfid, SIGNAL(timeout()), this, SLOT(authRFID()));
        yo=0;
        QSqlQuery emp = e.afficherEmpByCardNum(e.getCard());
        emp.next();
        qDebug()<< emp.value(0).toString();
        Employees test(emp.value(0).toInt(), emp.value(2).toString(), emp.value(1).toString(), emp.value(7).toString(), emp.value(8).toString(), emp.value(9).toString(), emp.value(3).toInt(), emp.value(8).toInt(), emp.value(6).toString());
        currentEmp = test;

        int you;
        you=AE.close_arduino();
        qDebug()<<"testt ="<<you;
            this->close();
            //GestionEmp gEmp;
          MainWindow M;


            M.show();
            QEventLoop loop;
            connect(&M, SIGNAL(closed()), &loop, SLOT(quit()));


            loop.exec();

    }else {
        QMessageBox::critical(nullptr, QObject::tr("login status"),QObject::tr("Card not valid.\nClick Cancel to exit."), QMessageBox::Cancel);
    }

    timerAuthRfid->stop();
}
void login::on_scanCardButton_clicked()
{
    yo=1;
}
