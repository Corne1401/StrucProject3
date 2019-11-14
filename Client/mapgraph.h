#ifndef MAPGRAPH_H
#define MAPGRAPH_H

#include <QMainWindow>

namespace Ui {
class MapGraph;
}

class MapGraph : public QMainWindow
{
    Q_OBJECT

public:
    explicit MapGraph(QWidget *parent = nullptr);
    ~MapGraph();

private slots:
    void on_primBtn_clicked();

private:
    Ui::MapGraph *ui;
};

#endif // MAPGRAPH_H
