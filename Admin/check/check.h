#ifndef CHECK_H
#define CHECK_H

#include <QMainWindow>

namespace Ui {
class Check;
}

class Check : public QMainWindow
{
    Q_OBJECT

public:
    explicit Check(QWidget *parent = nullptr);
    ~Check();

private slots:
    void on_backButton_clicked();

private:
    Ui::Check *ui;
};

#endif // CHECK_H
