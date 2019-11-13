#ifndef DELETEPRODUCT_H
#define DELETEPRODUCT_H

#include <QMainWindow>

namespace Ui {
class DeleteProduct;
}

class DeleteProduct : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeleteProduct(QWidget *parent = nullptr);
    ~DeleteProduct();

private:
    Ui::DeleteProduct *ui;
};

#endif // DELETEPRODUCT_H
