/********************************************************************************
** Form generated from reading UI file 'mapgraph.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPGRAPH_H
#define UI_MAPGRAPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mapGraph
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *DFSBtn;
    QPushButton *kurskalBtn;
    QPushButton *articulationBtn;
    QLabel *label_3;
    QLabel *label_2;
    QPushButton *BFSBtn;
    QPushButton *primBtn;
    QPushButton *dijkstraBtn;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *mapGraph)
    {
        if (mapGraph->objectName().isEmpty())
            mapGraph->setObjectName(QString::fromUtf8("mapGraph"));
        mapGraph->resize(869, 678);
        centralwidget = new QWidget(mapGraph);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 611, 591));
        DFSBtn = new QPushButton(centralwidget);
        DFSBtn->setObjectName(QString::fromUtf8("DFSBtn"));
        DFSBtn->setGeometry(QRect(430, 600, 80, 25));
        kurskalBtn = new QPushButton(centralwidget);
        kurskalBtn->setObjectName(QString::fromUtf8("kurskalBtn"));
        kurskalBtn->setGeometry(QRect(130, 600, 80, 25));
        articulationBtn = new QPushButton(centralwidget);
        articulationBtn->setObjectName(QString::fromUtf8("articulationBtn"));
        articulationBtn->setGeometry(QRect(330, 600, 80, 25));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(630, 80, 181, 421));
        QFont font;
        font.setPointSize(12);
        label_3->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(630, 50, 81, 31));
        label_2->setFont(font);
        BFSBtn = new QPushButton(centralwidget);
        BFSBtn->setObjectName(QString::fromUtf8("BFSBtn"));
        BFSBtn->setGeometry(QRect(530, 600, 80, 25));
        primBtn = new QPushButton(centralwidget);
        primBtn->setObjectName(QString::fromUtf8("primBtn"));
        primBtn->setGeometry(QRect(30, 600, 80, 25));
        dijkstraBtn = new QPushButton(centralwidget);
        dijkstraBtn->setObjectName(QString::fromUtf8("dijkstraBtn"));
        dijkstraBtn->setGeometry(QRect(230, 600, 80, 25));
        mapGraph->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(mapGraph);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        mapGraph->setStatusBar(statusbar);

        retranslateUi(mapGraph);

        QMetaObject::connectSlotsByName(mapGraph);
    } // setupUi

    void retranslateUi(QMainWindow *mapGraph)
    {
        mapGraph->setWindowTitle(QApplication::translate("mapGraph", "MainWindow", nullptr));
        label->setText(QApplication::translate("mapGraph", "<html><head/><body><p><img src=\":/images/Graph.png\"/></p></body></html>", nullptr));
        DFSBtn->setText(QApplication::translate("mapGraph", "Depth FS", nullptr));
        kurskalBtn->setText(QApplication::translate("mapGraph", "Kurskal", nullptr));
        articulationBtn->setText(QApplication::translate("mapGraph", "Articulation", nullptr));
        label_3->setText(QApplication::translate("mapGraph", "0 : Supermercado\n"
"1 : Liberia\n"
"2 : Tilaran\n"
"3 : Bagaces\n"
"4 : Pital\n"
"5 : San Jose\n"
"6 : Samara\n"
"7 : Parrita\n"
"8 : Jaco\n"
"9 :  Buenos Aires\n"
"10 : Heredia\n"
"11 : Cartago\n"
"12 : Puerto Viejo\n"
"13 : Siquirres\n"
"14 : Matina\n"
"15 : Telire\n"
"16 : Bodega", nullptr));
        label_2->setText(QApplication::translate("mapGraph", "Legend", nullptr));
        BFSBtn->setText(QApplication::translate("mapGraph", "Breadth FS", nullptr));
        primBtn->setText(QApplication::translate("mapGraph", "Prim", nullptr));
        dijkstraBtn->setText(QApplication::translate("mapGraph", "Dijkstra", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mapGraph: public Ui_mapGraph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPGRAPH_H
