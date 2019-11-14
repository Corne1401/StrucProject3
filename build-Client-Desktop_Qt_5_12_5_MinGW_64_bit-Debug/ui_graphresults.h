/********************************************************************************
** Form generated from reading UI file 'graphresults.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHRESULTS_H
#define UI_GRAPHRESULTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphResults
{
public:
    QWidget *centralwidget;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GraphResults)
    {
        if (GraphResults->objectName().isEmpty())
            GraphResults->setObjectName(QString::fromUtf8("GraphResults"));
        GraphResults->resize(800, 600);
        centralwidget = new QWidget(GraphResults);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 20, 751, 531));
        textEdit->setReadOnly(true);
        GraphResults->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GraphResults);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        GraphResults->setMenuBar(menubar);
        statusbar = new QStatusBar(GraphResults);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        GraphResults->setStatusBar(statusbar);

        retranslateUi(GraphResults);

        QMetaObject::connectSlotsByName(GraphResults);
    } // setupUi

    void retranslateUi(QMainWindow *GraphResults)
    {
        GraphResults->setWindowTitle(QApplication::translate("GraphResults", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GraphResults: public Ui_GraphResults {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHRESULTS_H
