#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "logement.h"
#include <QMainWindow>
#include"QPdfWriter"
#include"QtPrintSupport/QPrinter"
#include"QPainter"
#include <QPrintDialog>
#include "smtp.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_modif_clicked();

    void on_pushButton_supprimer_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_send_clicked();

private:
    Ui::MainWindow *ui;
    Logement L;
    Smtp* smtp;
        QString msg;
        QString mail;
};

#endif // MAINWINDOW_H
