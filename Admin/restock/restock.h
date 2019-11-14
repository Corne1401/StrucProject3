#ifndef RESTOCK_H
#define RESTOCK_H

#include <QMainWindow>

namespace Ui {
class ReStock;
}

class ReStock : public QMainWindow
{
    Q_OBJECT

public:
    explicit ReStock(QWidget *parent = nullptr);
    ~ReStock();

private slots:
    void on_backButton_clicked();

    void on_restockButton_clicked();

private:
    Ui::ReStock *ui;
};

#endif // RESTOCK_H
