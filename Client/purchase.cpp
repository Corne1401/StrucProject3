#include "purchase.h"
#include "ui_purchase.h"
#include "globalClient.h"
#include <sstream>
#include <iostream>

purchase::purchase(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::purchase)
{
    ui->setupUi(this);
}

purchase::~purchase()
{
    delete ui;
}

void purchase::setAislesForComboBox(string productsForPurchase){
    std::istringstream f(productsForPurchase);
        std::string line;
        while (std::getline(f, line)) {
            ui->aisles->addItem(QString::fromStdString(line));
        }
}
