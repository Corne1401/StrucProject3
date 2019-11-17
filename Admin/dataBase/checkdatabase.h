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

private:
    Ui::checkDataBase *ui;
};

#endif // CHECKDATABASE_H
