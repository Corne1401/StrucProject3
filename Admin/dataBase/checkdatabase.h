#ifndef CHECKDATABASE_H
#define CHECKDATABASE_H

#include <QMainWindow>

namespace Ui {
class checkDataBase;
}

class checkDataBase : public QMainWindow
{
    Q_OBJECT

public:
    explicit checkDataBase(QWidget *parent = nullptr);
    ~checkDataBase();

private slots:
    void on_checkAisles_clicked();
    void on_checkBrands_clicked();
    void on_checkProd_clicked();
    void on_backBtn_clicked();

private:
    Ui::checkDataBase *ui;
};

#endif // CHECKDATABASE_H
