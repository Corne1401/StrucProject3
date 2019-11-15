#include "reports.h"
#include "ui_reports.h"
#include "menu.h"
#include "globalAdmin.h"
#include "reports/mostprodaisle.h"
#include "reports/prodlist.h"
#include "reports/brandlist.h"
#include "reports/generateall.h"

Reports::Reports(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Reports)
{
    ui->setupUi(this);
}

Reports::~Reports()
{
    delete ui;
}

void Reports::on_reportsBack_clicked()
{
    Menu *menu = new Menu;
    menu->show();
    this->close();
}


void Reports::on_reportsGenerate_clicked()
{
    QString request;

    if(ui->selectReport->currentIndex()==0){
        request = "36;"+adminID;
        emit adminSock.send(request.toUtf8());
    }
    else if(ui->selectReport->currentIndex()==1){
        request = "37;"+adminID;
        emit adminSock.send(request.toUtf8());
    }
    else if(ui->selectReport->currentIndex()==2){

        MostProdAisle *mostProd = new MostProdAisle;
        mostProd->show();

    }
    else if(ui->selectReport->currentIndex()==3){
        request = "39;"+adminID;
        emit adminSock.send(request.toUtf8());
    }
    else if(ui->selectReport->currentIndex()==4){
        request = "40;"+adminID;
        emit adminSock.send(request.toUtf8());
    }
    else if(ui->selectReport->currentIndex()==5){
        request = "41;"+adminID;
        emit adminSock.send(request.toUtf8());
    }
    else if(ui->selectReport->currentIndex()==6){
        request = "42;"+adminID;
        emit adminSock.send(request.toUtf8());
    }
    else if(ui->selectReport->currentIndex()==7){
        request = "43;"+adminID;
        emit adminSock.send(request.toUtf8());
    }
    else if(ui->selectReport->currentIndex()==8){
        request = "44;"+adminID;
        emit adminSock.send(request.toUtf8());
    }
    else if(ui->selectReport->currentIndex()==9){
        ProdList *prodList = new ProdList;
        prodList->show();

    }
    else if(ui->selectReport->currentIndex()==10){
        BrandList *brandList = new BrandList;
        brandList->show();

    }
    else if(ui->selectReport->currentIndex()==11){
        request = "47;"+adminID;
        emit adminSock.send(request.toUtf8());
    }
    else if(ui->selectReport->currentIndex()==12){
        request = "48;"+adminID;
        emit adminSock.send(request.toUtf8());
    }
    else if(ui->selectReport->currentIndex()==13){

        GenerateAll *genAll = new GenerateAll;
        genAll->show();
    }

}
