#ifndef MOSTPRODAISLE_H
#define MOSTPRODAISLE_H

#include <QMainWindow>

namespace Ui {
class MostProdAisle;
}

class MostProdAisle : public QMainWindow
{
    Q_OBJECT

public:
    explicit MostProdAisle(QWidget *parent = nullptr);
    ~MostProdAisle();

private slots:


    void on_generateButton_clicked();

private:
    Ui::MostProdAisle *ui;
};

#endif // MOSTPRODAISLE_H
