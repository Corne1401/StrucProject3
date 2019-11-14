/********************************************************************************
** Form generated from reading UI file 'insertions.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTIONS_H
#define UI_INSERTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_insertions
{
public:
    QWidget *centralwidget;
    QPushButton *insertClient;
    QPushButton *insertProduct;
    QPushButton *insertAisle;
    QPushButton *insertBrand;
    QPushButton *insertBack;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *insertions)
    {
        if (insertions->objectName().isEmpty())
            insertions->setObjectName(QString::fromUtf8("insertions"));
        insertions->resize(800, 600);
        centralwidget = new QWidget(insertions);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        insertClient = new QPushButton(centralwidget);
        insertClient->setObjectName(QString::fromUtf8("insertClient"));
        insertClient->setGeometry(QRect(540, 160, 80, 21));
        insertProduct = new QPushButton(centralwidget);
        insertProduct->setObjectName(QString::fromUtf8("insertProduct"));
        insertProduct->setGeometry(QRect(170, 160, 80, 21));
        insertAisle = new QPushButton(centralwidget);
        insertAisle->setObjectName(QString::fromUtf8("insertAisle"));
        insertAisle->setGeometry(QRect(540, 50, 80, 21));
        insertBrand = new QPushButton(centralwidget);
        insertBrand->setObjectName(QString::fromUtf8("insertBrand"));
        insertBrand->setGeometry(QRect(170, 50, 80, 21));
        insertBack = new QPushButton(centralwidget);
        insertBack->setObjectName(QString::fromUtf8("insertBack"));
        insertBack->setGeometry(QRect(360, 240, 80, 21));
        insertions->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(insertions);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        insertions->setStatusBar(statusbar);

        retranslateUi(insertions);

        QMetaObject::connectSlotsByName(insertions);
    } // setupUi

    void retranslateUi(QMainWindow *insertions)
    {
        insertions->setWindowTitle(QApplication::translate("insertions", "MainWindow", nullptr));
        insertClient->setText(QApplication::translate("insertions", "Insert Client", nullptr));
        insertProduct->setText(QApplication::translate("insertions", "Insert Product", nullptr));
        insertAisle->setText(QApplication::translate("insertions", "Insert Aisle", nullptr));
        insertBrand->setText(QApplication::translate("insertions", "Insert Brand", nullptr));
        insertBack->setText(QApplication::translate("insertions", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class insertions: public Ui_insertions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTIONS_H
