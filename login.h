#ifndef LOGIN_H
#define LOGIN_H
#include <QDialog>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QMainWindow>
#include<QMessageBox>
#include "contrat_client.h"
#include<mainwindow.h>
#include "ui_mainwindow.h"
#include "arduino.h"
#include "employees.h"
extern Employees currentEmp;
namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();


private slots:
   // void on_pb_connecter_clicked();
    void getCardUid();
    void on_loginButton_clicked();

    void on_scanCardButton_clicked();
  //  void readyReadSlot();
    void authRFID();


private:
    Ui::login *ui;
   QMainWindow *M;
   QByteArray data; // variable contenant les données reçu
   Arduino AE; // objet temporaire

};

#endif // LOGIN_H
