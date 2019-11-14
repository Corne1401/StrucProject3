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

class Ui_MapGraph
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *primBtn;
    QPushButton *kurskalBtn;
    QPushButton *dijkstraBtn;
    QPushButton *articulationBtn;
    QPushButton *DFSBtn;
    QPushButton *BFSBtn;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MapGraph)
    {
        if (MapGraph->objectName().isEmpty())
            MapGraph->setObjectName(QString::fromUtf8("MapGraph"));
        MapGraph->resize(982, 654);
        centralwidget = new QWidget(MapGraph);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, -30, 611, 591));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(620, 10, 81, 31));
        QFont font;
        font.setPointSize(12);
        label_2->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(620, 40, 181, 421));
        label_3->setFont(font);
        primBtn = new QPushButton(centralwidget);
        primBtn->setObjectName(QString::fromUtf8("primBtn"));
        primBtn->setGeometry(QRect(20, 560, 80, 25));
        kurskalBtn = new QPushButton(centralwidget);
        kurskalBtn->setObjectName(QString::fromUtf8("kurskalBtn"));
        kurskalBtn->setGeometry(QRect(120, 560, 80, 25));
        dijkstraBtn = new QPushButton(centralwidget);
        dijkstraBtn->setObjectName(QString::fromUtf8("dijkstraBtn"));
        dijkstraBtn->setGeometry(QRect(220, 560, 80, 25));
        articulationBtn = new QPushButton(centralwidget);
        articulationBtn->setObjectName(QString::fromUtf8("articulationBtn"));
        articulationBtn->setGeometry(QRect(320, 560, 80, 25));
        DFSBtn = new QPushButton(centralwidget);
        DFSBtn->setObjectName(QString::fromUtf8("DFSBtn"));
        DFSBtn->setGeometry(QRect(420, 560, 80, 25));
        BFSBtn = new QPushButton(centralwidget);
        BFSBtn->setObjectName(QString::fromUtf8("BFSBtn"));
        BFSBtn->setGeometry(QRect(520, 560, 80, 25));
        MapGraph->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MapGraph);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MapGraph->setStatusBar(statusbar);

        retranslateUi(MapGraph);

        QMetaObject::connectSlotsByName(MapGraph);
    } // setupUi

    void retranslateUi(QMainWindow *MapGraph)
    {
        MapGraph->setWindowTitle(QApplication::translate("MapGraph", "MainWindow", nullptr));
        label->setText(QApplication::translate("MapGraph", "<html><head/><body><p><img src=\":/image/Graph.png\"/></p></body></html>", nullptr));
        label_2->setText(QApplication::translate("MapGraph", "Legend", nullptr));
        label_3->setText(QApplication::translate("MapGraph", "0 : Supermercado\n"
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
        primBtn->setText(QApplication::translate("MapGraph", "Prim", nullptr));
        kurskalBtn->setText(QApplication::translate("MapGraph", "Kurskal", nullptr));
        dijkstraBtn->setText(QApplication::translate("MapGraph", "Dijkstra", nullptr));
        articulationBtn->setText(QApplication::translate("MapGraph", "Articulation", nullptr));
        DFSBtn->setText(QApplication::translate("MapGraph", "Depth FS", nullptr));
        BFSBtn->setText(QApplication::translate("MapGraph", "Breadth FS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MapGraph: public Ui_MapGraph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPGRAPH_H
