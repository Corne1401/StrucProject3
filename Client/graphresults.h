#ifndef GRAPHRESULTS_H
#define GRAPHRESULTS_H

#include <QMainWindow>

namespace Ui {
class GraphResults;
}

class GraphResults : public QMainWindow
{
    Q_OBJECT

public:
    explicit GraphResults(QString data, QWidget *parent = nullptr);

    ~GraphResults();
    QString data;
private slots:
    void on_returnBtn_clicked();

private:
    Ui::GraphResults *ui;
};

#endif // GRAPHRESULTS_H
