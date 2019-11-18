#ifndef CHECKPROD_H
#define CHECKPROD_H

#include <QMainWindow>

namespace Ui {
class CheckProd;
}

class CheckProd : public QMainWindow
{
    Q_OBJECT

public:
    explicit CheckProd(QWidget *parent = nullptr);
    void on_pushButton_clicked();
    ~CheckProd();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CheckProd *ui;
};

#endif // CHECKPROD_H
