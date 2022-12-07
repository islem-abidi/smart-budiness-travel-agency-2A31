#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <contrat_client.h>
#include<login.h>
#include <QMainWindow>
#include <QMessageBox>
#include<QString>
#include<QtWidgets>
#include<QTableView>
#include <QDialog>
#include<QAbstractItemModel>
#include<QString>
#include<QMessageBox>
#include<QTableView>
#include<QSqlQueryModel>
#include <QAbstractItemModel>
#include<QSqlQuery>
#include "smtp.h"
#include <QtCore>
#include "transport.h"
#include <arduino1.h>
#include <arduino.h>
#include "smtp1.h"
#include "employe.h"
#include"QPdfWriter"

#include"QPainter"
#include <QPrintDialog>
#include "smtp.h"
#include "logement.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pb_ajouter_clicked();
    void on_pb_supprimer_clicked();
    void on_pb_modifier_clicked();
    void on_pb_trier_clicked();

    void on_pb_chercher_clicked();

    void on_pb_mail_clicked();
    //void stat();
    void on_pb_pdf_clicked();

    //void on_pb_stat_clicked();

    //void on_pb_envoyer_clicked();

    void on_pb_sent_clicked();

    void on_pb_tri_asc_clicked();
  //  void on_pushButton_clicked();

   // void on_pushButton_supprimer_clicked();

    //void on_pushButton_modifer_clicked();

    void on_pushButton_ajouter_clicked();

    void on_pushButton_supprimer_clicked();

   // void on_pushButton_rechercher_clicked();

 //   void on_pushButtonT_clicked();

    void on_PDF_clicked();

  //  void on_pushButtonS_clicked();

    void on_pushButton_3_clicked();

  //  void on_recherche_textChanged(const QString &arg1);

    void on_lineEditR_textChanged(const QString &arg1);

    void on_comboBox_currentTextChanged(const QString &arg1);


    void on_Weather_clicked();

   // void on_pushButtonV_clicked();


 //   void on_pushButton123_clicked();
    //btn islem
    void on_pb_supprimer_2_clicked();

        void on_pb_ajoutter_clicked();

        void on_pb_modifier_2_clicked();

        void on_pb_rechercher_clicked();

        void on_pb_trier_2_clicked();

        void on_pb_pdf_2_clicked();

        void on_pb_excel_3_clicked();


        void on_pb_chat_clicked();

        void on_pushButton_send_clicked();
         void update_Employ();


         void on_pushButton_modif_clicked();

         void on_pushButton_supprimer_2_clicked();

         void on_pushButton_2_clicked();

         void on_lineEdit_2_textChanged(const QString &arg1);

         void on_radioButton_clicked();

         void on_radioButton_2_clicked();

         void on_radioButton_3_clicked();

         void on_pushButton_send_2_clicked();

         void on_pushButton_supprimer_3_clicked();

         void on_pushButton_4_clicked();


private:
    Ui::MainWindow *ui;
    CONTRAT_CLIENT1 C;
    transport T;
    transport *TP;
    Arduino A;
    //islem
    Employe E;
        Smtp1* smtp1;
                QString msg;
                QString mail;

                //Arduino
                 QByteArray data;
                 Arduino A1;
                 QSqlDatabase test_bd;
                 Logement L;
                 Smtp* smtp;
                  //   QString msg;
                  //   QString mail;
};
#endif // MAINWINDOW_H
