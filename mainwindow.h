#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <contrat_client.h>
#include<login.h>
#include<arduino.h>
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
#include <QtSerialPort>

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
    //void update_label();
    void on_pb_chercher_clicked();

    void on_pb_mail_clicked();
    //void stat();
    void on_pb_pdf_clicked();

    //void on_pb_stat_clicked();

    //void on_pb_envoyer_clicked();

    void on_pb_sent_clicked();

    void on_pb_tri_asc_clicked();

private:
    Ui::MainWindow *ui;
    CONTRAT_CLIENT1 C;
    arduino A;
    QByteArray data;

};
#endif // MAINWINDOW_H
