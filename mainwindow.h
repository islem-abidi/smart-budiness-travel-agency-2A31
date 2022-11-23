#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "employe.h"
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


    void on_pb_supprimer_clicked();

    void on_pb_ajoutter_clicked();

    void on_pb_modifier_clicked();

    void on_pb_rechercher_clicked();

    void on_pb_trier_clicked();

    void on_pb_pdf_clicked();

    void on_pb_excel_clicked();

    void on_pB_sts_2_clicked();

    void on_pb_chat_clicked();

private:
    Ui::MainWindow *ui;
    Employe E;
};

#endif // MAINWINDOW_H
