#ifndef MAPGRAPH_H
#define MAPGRAPH_H

#include <QMainWindow>

namespace Ui {
class mapGraph;
}

class mapGraph : public QMainWindow
{
    Q_OBJECT

public:
    explicit mapGraph(QWidget *parent = nullptr);
    ~mapGraph();

private slots:
    void on_primBtn_clicked();

    void on_kurskalBtn_clicked();

    void on_dijkstraBtn_clicked();

    void on_articulationBtn_clicked();

    void on_DFSBtn_clicked();

    void on_BFSBtn_clicked();

private:
    Ui::mapGraph *ui;
};

#endif // MAPGRAPH_H
