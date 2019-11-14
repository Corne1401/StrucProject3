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
    void on_reportsBack_clicked();

    void on_reportsGenerate_clicked();

private:
    Ui::Reports *ui;
};

#endif // REPORTS_H
