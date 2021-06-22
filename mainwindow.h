#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPair>
#include <QVector>
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    double path = 0;
    double temperatura = 0;
    double delta = 0;
    QVector <QPair<double, double>> city_mas;
    QVector <int> path_mas;
    QMap <QPair<int,int>, double> distanse;
    void read_file();
    QVector<int> inventor();
    void main_function();
    double probability(double delta, double t);
    int transition();
    float random();
    double dist_change(QPair<double, double> city_1, QPair<double, double> city_2);
    int random_int(int last_value);
    void paint(QVector<int> vector);

private slots:
    void slot_read();
    void slot_otjig();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
