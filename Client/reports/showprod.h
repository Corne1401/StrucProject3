#ifndef SHOWPROD_H
#define SHOWPROD_H

#include <QMainWindow>

namespace Ui {
class ShowProd;
}

class ShowProd : public QMainWindow
{
    Q_OBJECT

public:
    explicit ShowProd(QWidget *parent = nullptr);
    ~ShowProd();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ShowProd *ui;
};

#endif // SHOWPROD_H
