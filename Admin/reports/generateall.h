#ifndef GENERATEALL_H
#define GENERATEALL_H

#include <QMainWindow>

namespace Ui {
class GenerateAll;
}

class GenerateAll : public QMainWindow
{
    Q_OBJECT

public:
    explicit GenerateAll(QWidget *parent = nullptr);
    ~GenerateAll();


private slots:
    void on_pushButton_clicked();

private:
    Ui::GenerateAll *ui;
};

#endif // GENERATEALL_H
