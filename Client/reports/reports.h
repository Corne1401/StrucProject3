#ifndef REPORTS_H
#define REPORTS_H

#include <QMainWindow>

namespace Ui {
class Reports;
}

class Reports : public QMainWindow
{
    Q_OBJECT

public:
    explicit Reports(QWidget *parent = nullptr);
    ~Reports();

private slots:
    void on_aislesBtn_clicked();

    void on_prodBtn_clicked();

    void on_brandsBtn_clicked();

    void on_backBtn_clicked();

private:
    Ui::Reports *ui;
};

#endif // REPORTS_H
