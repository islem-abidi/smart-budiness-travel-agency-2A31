/********************************************************************************
** Form generated from reading UI file 'statistique.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTIQUE_H
#define UI_STATISTIQUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_statistique
{
public:
    QGroupBox *groupBox;
    QLabel *label_6;
    QWidget *widget_3;
    QLabel *label_5;
    QWidget *widget_4;
    QLabel *label_4;
    QWidget *widget_2;
    QWidget *widget_5;
    QLabel *label_8;
    QLabel *label;
    QWidget *widget;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *statistique)
    {
        if (statistique->objectName().isEmpty())
            statistique->setObjectName(QStringLiteral("statistique"));
        statistique->resize(921, 633);
        groupBox = new QGroupBox(statistique);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(90, 10, 731, 531));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(510, 170, 111, 16));
        label_6->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        widget_3 = new QWidget(groupBox);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(480, 170, 21, 20));
        widget_3->setStyleSheet(QLatin1String("background-color: rgb(0, 255, 0);\n"
"background-color: rgb(255, 0, 0);"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(510, 140, 111, 16));
        label_5->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        widget_4 = new QWidget(groupBox);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(480, 140, 20, 20));
        widget_4->setStyleSheet(QLatin1String("background-color: rgb(0, 255, 0);\n"
"background-color: rgb(255, 255, 0);"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(510, 110, 131, 16));
        label_4->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        widget_2 = new QWidget(groupBox);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(480, 110, 20, 20));
        widget_2->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        widget_5 = new QWidget(groupBox);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setGeometry(QRect(480, 80, 20, 20));
        widget_5->setStyleSheet(QStringLiteral("background-color: rgb(0, 255, 0);"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(50, 440, 631, 41));
        label_8->setStyleSheet(QLatin1String("font: 18pt \"MS Shell Dlg 2\";\n"
"color: rgb(0, 170, 255);"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(480, 20, 131, 31));
        label->setStyleSheet(QStringLiteral("font: 75 italic 14pt \"Arial\";"));
        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(480, 50, 20, 20));
        widget->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 255);"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(510, 50, 111, 16));
        label_2->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(510, 80, 111, 16));
        label_3->setStyleSheet(QStringLiteral("font: 12pt \"MS Shell Dlg 2\";"));

        retranslateUi(statistique);

        QMetaObject::connectSlotsByName(statistique);
    } // setupUi

    void retranslateUi(QDialog *statistique)
    {
        statistique->setWindowTitle(QApplication::translate("statistique", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("statistique", "Statistique", Q_NULLPTR));
        label_6->setText(QApplication::translate("statistique", "Milan", Q_NULLPTR));
        label_5->setText(QApplication::translate("statistique", "Berlin", Q_NULLPTR));
        label_4->setText(QApplication::translate("statistique", "Bruxelles", Q_NULLPTR));
        label_8->setText(QApplication::translate("statistique", "Statistique des destinations de voyageurs", Q_NULLPTR));
        label->setText(QApplication::translate("statistique", "Pourcentage", Q_NULLPTR));
        label_2->setText(QApplication::translate("statistique", "Amsterdam", Q_NULLPTR));
        label_3->setText(QApplication::translate("statistique", "Paris", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class statistique: public Ui_statistique {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTIQUE_H
