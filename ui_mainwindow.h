/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QLineEdit *lineEdit_ID;
    QLineEdit *lineEdit_nom;
    QLineEdit *lineEdit_prenom;
    QLineEdit *lineEdit_depart;
    QLineEdit *lineEdit_destination;
    QPushButton *pushButton_ajouter;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QDateEdit *dateDepart;
    QDateEdit *dateRetour;
    QDateEdit *dateNaissance;
    QPushButton *pushButton_supprimer;
    QLineEdit *lineEdit_IDS;
    QGroupBox *groupBox_2;
    QLineEdit *lineEditR;
    QTableView *table_transport;
    QPushButton *pushButton_3;
    QPushButton *PDF;
    QPushButton *pushButtonS;
    QComboBox *comboBox;
    QPushButton *Weather;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1198, 632);
        MainWindow->setStyleSheet(QStringLiteral("background-color:rgb(85, 170, 255)"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 10, 291, 491));
        groupBox->setStyleSheet(QLatin1String("QGroupBox {\n"
"	\n"
"   font: 10pt \"MS Shell Dlg 2\";\n"
"font: bold;\n"
"text-align:center;\n"
"    border: 2px solid white;\n"
"    border-radius: 5px;\n"
"    margin-top: 1ex;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
" \n"
"    subcontrol-position: top center; /* position at the top center */\n"
"  \n"
"}"));
        lineEdit_ID = new QLineEdit(groupBox);
        lineEdit_ID->setObjectName(QStringLiteral("lineEdit_ID"));
        lineEdit_ID->setGeometry(QRect(150, 50, 113, 20));
        lineEdit_nom = new QLineEdit(groupBox);
        lineEdit_nom->setObjectName(QStringLiteral("lineEdit_nom"));
        lineEdit_nom->setGeometry(QRect(150, 90, 113, 20));
        lineEdit_prenom = new QLineEdit(groupBox);
        lineEdit_prenom->setObjectName(QStringLiteral("lineEdit_prenom"));
        lineEdit_prenom->setGeometry(QRect(150, 130, 113, 20));
        lineEdit_depart = new QLineEdit(groupBox);
        lineEdit_depart->setObjectName(QStringLiteral("lineEdit_depart"));
        lineEdit_depart->setGeometry(QRect(150, 170, 113, 20));
        lineEdit_destination = new QLineEdit(groupBox);
        lineEdit_destination->setObjectName(QStringLiteral("lineEdit_destination"));
        lineEdit_destination->setGeometry(QRect(150, 210, 113, 20));
        pushButton_ajouter = new QPushButton(groupBox);
        pushButton_ajouter->setObjectName(QStringLiteral("pushButton_ajouter"));
        pushButton_ajouter->setGeometry(QRect(174, 420, 91, 23));
        pushButton_ajouter->setStyleSheet(QLatin1String("QPushButton {\n"
"    border: 2px solid black;\n"
"    border-radius: 6px;\n"
"    background-color: #2E2EFF;\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 50, 71, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 90, 47, 14));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 130, 47, 14));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 170, 47, 14));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 210, 71, 16));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(30, 260, 51, 16));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 290, 61, 16));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 330, 81, 16));
        dateDepart = new QDateEdit(groupBox);
        dateDepart->setObjectName(QStringLiteral("dateDepart"));
        dateDepart->setGeometry(QRect(150, 250, 110, 22));
        dateRetour = new QDateEdit(groupBox);
        dateRetour->setObjectName(QStringLiteral("dateRetour"));
        dateRetour->setGeometry(QRect(150, 290, 110, 22));
        dateNaissance = new QDateEdit(groupBox);
        dateNaissance->setObjectName(QStringLiteral("dateNaissance"));
        dateNaissance->setGeometry(QRect(150, 330, 110, 22));
        pushButton_supprimer = new QPushButton(groupBox);
        pushButton_supprimer->setObjectName(QStringLiteral("pushButton_supprimer"));
        pushButton_supprimer->setGeometry(QRect(40, 420, 75, 23));
        lineEdit_IDS = new QLineEdit(groupBox);
        lineEdit_IDS->setObjectName(QStringLiteral("lineEdit_IDS"));
        lineEdit_IDS->setGeometry(QRect(20, 390, 113, 20));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(340, 30, 581, 441));
        lineEditR = new QLineEdit(groupBox_2);
        lineEditR->setObjectName(QStringLiteral("lineEditR"));
        lineEditR->setGeometry(QRect(20, 30, 141, 20));
        lineEditR->setStyleSheet(QLatin1String("background-color:rgb(202, 255, 227); \n"
"border: 2px solid gray; \n"
"border-radius: 10px; \n"
"padding: 0 8px; \n"
"selection-background-color: darkgray; \n"
" font-size: 16px;\n"
"  focus {  \n"
"   background-color:rgb(192, 192, 255)}"));
        table_transport = new QTableView(groupBox_2);
        table_transport->setObjectName(QStringLiteral("table_transport"));
        table_transport->setGeometry(QRect(10, 100, 561, 271));
        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(230, 390, 84, 23));
        pushButton_3->setStyleSheet(QLatin1String("QPushButton {\n"
"    border: 2px solid black;\n"
"    border-radius: 6px;\n"
"    background-color: #2E2EFF;\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));
        PDF = new QPushButton(groupBox_2);
        PDF->setObjectName(QStringLiteral("PDF"));
        PDF->setGeometry(QRect(460, 390, 84, 23));
        PDF->setStyleSheet(QLatin1String("QPushButton {\n"
"    border: 2px solid black;\n"
"    border-radius: 6px;\n"
"    background-color: #2E2EFF;\n"
"    min-width: 80px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
"}\n"
"\n"
"QPushButton:flat {\n"
"    border: none; /* no border for a flat push button */\n"
"}\n"
"\n"
"QPushButton:default {\n"
"    border-color: navy; /* make the default button prominent */\n"
"}"));
        pushButtonS = new QPushButton(groupBox_2);
        pushButtonS->setObjectName(QStringLiteral("pushButtonS"));
        pushButtonS->setGeometry(QRect(450, 30, 75, 23));
        comboBox = new QComboBox(groupBox_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(30, 390, 81, 22));
        Weather = new QPushButton(groupBox_2);
        Weather->setObjectName(QStringLiteral("Weather"));
        Weather->setGeometry(QRect(320, 30, 75, 23));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1198, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Clients", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Ajout", Q_NULLPTR));
        pushButton_ajouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Num Passport", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Nom", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Prenom", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Depart", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Destination", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Date Aller", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Date Retour", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Date Naissance", Q_NULLPTR));
        pushButton_supprimer->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        pushButton_3->setText(QApplication::translate("MainWindow", "Tracking", Q_NULLPTR));
        PDF->setText(QApplication::translate("MainWindow", "PDF", Q_NULLPTR));
        pushButtonS->setText(QApplication::translate("MainWindow", "Statistique", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Par Defaut", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Num Pass", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Par Nom", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Par Prenom", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Par Destination", Q_NULLPTR)
        );
        Weather->setText(QApplication::translate("MainWindow", "Weather", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
