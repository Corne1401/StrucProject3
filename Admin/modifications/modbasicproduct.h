#ifndef MODBASICPRODUCT_H
#define MODBASICPRODUCT_H

#include <QMainWindow>

namespace Ui {
class modBasicProduct;
}

class modBasicProduct : public QMainWindow
{
    Q_OBJECT

public:
    explicit modBasicProduct(QWidget *parent = nullptr);
    ~modBasicProduct();

private slots:
    void on_pushButton_clicked();

private:
    Ui::modBasicProduct *ui;
};

#endif // MODBASICPRODUCT_H
