#ifndef PURCHASE_H
#define PURCHASE_H

#include <QMainWindow>
#include <sstream>
#include <string>

using namespace std;
namespace Ui {
class purchase;
}

class purchase : public QMainWindow
{
    Q_OBJECT

public:
    explicit purchase(QWidget *parent = nullptr);
    ~purchase();

    void setAislesForComboBox(string productsForPurchase);
private:
    Ui::purchase *ui;
};

#endif // PURCHASE_H
