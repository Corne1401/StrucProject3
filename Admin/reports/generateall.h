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

<<<<<<< Updated upstream
=======
private slots:
    void on_pushButton_clicked();

>>>>>>> Stashed changes
private:
    Ui::GenerateAll *ui;
};

#endif // GENERATEALL_H
