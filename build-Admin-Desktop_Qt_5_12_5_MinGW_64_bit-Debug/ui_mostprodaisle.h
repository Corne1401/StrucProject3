/********************************************************************************
** Form generated from reading UI file 'mostprodaisle.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOSTPRODAISLE_H
#define UI_MOSTPRODAISLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MostProdAisle
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *generateButton;
    QLineEdit *aisleCode;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MostProdAisle)
    {
        if (MostProdAisle->objectName().isEmpty())
            MostProdAisle->setObjectName(QString::fromUtf8("MostProdAisle"));
        MostProdAisle->resize(800, 600);
        centralwidget = new QWidget(MostProdAisle);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(375, 90, 61, 16));
        generateButton = new QPushButton(centralwidget);
        generateButton->setObjectName(QString::fromUtf8("generateButton"));
        generateButton->setGeometry(QRect(349, 190, 91, 21));
        aisleCode = new QLineEdit(centralwidget);
        aisleCode->setObjectName(QString::fromUtf8("aisleCode"));
        aisleCode->setGeometry(QRect(340, 120, 113, 21));
        MostProdAisle->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MostProdAisle);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MostProdAisle->setStatusBar(statusbar);

        retranslateUi(MostProdAisle);

        QMetaObject::connectSlotsByName(MostProdAisle);
    } // setupUi

    void retranslateUi(QMainWindow *MostProdAisle)
    {
        MostProdAisle->setWindowTitle(QApplication::translate("MostProdAisle", "MainWindow", nullptr));
        label->setText(QApplication::translate("MostProdAisle", "Aisle code", nullptr));
        generateButton->setText(QApplication::translate("MostProdAisle", "Generate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MostProdAisle: public Ui_MostProdAisle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOSTPRODAISLE_H
