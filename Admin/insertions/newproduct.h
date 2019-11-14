#ifndef NEWPRODUCT_H
#define NEWPRODUCT_H

#include <QMainWindow>

namespace Ui {
class newProduct;
}

class newProduct : public QMainWindow
{
    Q_OBJECT

public:
    explicit newProduct(QWidget *parent = nullptr);
    ~newProduct();

private slots:
    void on_newProductConfirm_clicked();

private:
    Ui::newProduct *ui;
};

#endif // NEWPRODUCT_H
