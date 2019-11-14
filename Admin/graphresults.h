#ifndef GRAPHRESULTS_H
#define GRAPHRESULTS_H

#include <QMainWindow>

namespace Ui {
class graphResults;
}

class graphResults : public QMainWindow
{
    Q_OBJECT

public:
    explicit graphResults(QString data, QWidget *parent = nullptr);
    QString data;
    ~graphResults();

private:
    Ui::graphResults *ui;
};

#endif // GRAPHRESULTS_H
