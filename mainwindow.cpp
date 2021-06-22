#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QDebug>
#include <QDir>
#include <QtMath>
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    qsrand(time(0));
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(slot_read()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(slot_otjig()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_read()
{
    MainWindow::read_file();
}

void MainWindow::slot_otjig()
{
    MainWindow::main_function();
}

int MainWindow::random_int(int last_value)
{
    int r = 0 + qrand() % last_value;
    //qDebug()<<"r = "<<r;
    return r;
}

float MainWindow::random()
{
    float r = (qrand()%1)/(100 * 1.0);
    //qDebug()<<"r = "<<r;
    return r;
}

double MainWindow::probability(double delta, double t)
{
    double p = 0;
    p = qExp(-delta/t);
    //qDebug()<<"p = "<<p;
    return p;
}

int MainWindow::transition()
{
    int a = 0;
    double rand_ch = (double)random();
    double p = probability(delta, temperatura);

    if(rand_ch <= p)
        a = 1;
    else
        a = 0;

    return a;
}

void MainWindow::read_file()
{
    ui->progressBar->setValue(0);
    city_mas.clear();
    path_mas.clear();
    path = 0;

    QPair<double, double> tmp;

    QFile inputFile(QDir::currentPath() + "//" + ui->lineEdit->text());

    int i_str = 0;

    if (inputFile.open(QIODevice::ReadOnly))
    {
       QTextStream in(&inputFile);
       in.setCodec("cp1251");

       while(!in.atEnd())
       {
          QString line = in.readLine();

          if(line != "EOF")
          {
          if(i_str > 5)
          {
          QStringList list = line.split(QRegExp("\\s+"), QString::SkipEmptyParts);

          tmp.first = list[1].toDouble();
          tmp.second = list[2].toDouble();

          city_mas.push_back(tmp);
          }
          i_str++;
          }
          else
          {
            break;
          }
       }
       qDebug()<<"ЧТЕНИЕ ФАЙЛА: УСПЕШНО";
       inputFile.close();
    }

    double path = 0;

    QGraphicsScene *scene = new QGraphicsScene(ui->graphicsView);
    QPen pen0(Qt::gray,1);

    for(int i = 0; i < city_mas.count(); i++)
    {
        for(int j = 0; j < city_mas.count(); j++)
        {
            if(i != j)
            {
            QPair<int,int> tm;
            tm.first = i;
            tm.second = j;
            distanse[tm] = dist_change(city_mas[i], city_mas[j]);
            scene->addLine(city_mas[i].first, city_mas[i].second, city_mas[j].first,city_mas[j].second,pen0);
            }
        }
    }

    QPen pen2(Qt::blue,3);

    for(int i= 0; i < city_mas.count();i++)
    {
    if(i == 0)
    {
      scene->addLine(city_mas[i].first,city_mas[i].second,city_mas[city_mas.count()-1].first,city_mas[city_mas.count()-1].second,pen2);
      path +=  dist_change(city_mas[i], city_mas[city_mas.count()-1]);
    }
    else
    {
      scene->addLine(city_mas[i-1].first,city_mas[i-1].second,city_mas[i].first,city_mas[i].second,pen2);
      path +=  dist_change(city_mas[i-1], city_mas[i]);
    }
    }
    ui->label_2->setText("Длина пути: " + QString::number(path));
   // qDebug() << path;

    for(int i = 0; i < city_mas.count(); i++)
    {
        path_mas.push_back(i);
    }
     ui->graphicsView->setScene(scene);

 }

QVector<int> MainWindow::inventor()
{
    QGraphicsScene *scene = new QGraphicsScene(ui->graphicsView);
    QPen pen2(Qt::blue,3);
    QPen pen0(Qt::gray,1);
/*
    for(int i = 0; i < city_mas.count(); i++)
    {
        for(int j = 0; j < city_mas.count(); j++)
        {
            if(i != j)
            {
            QPair<int,int> tm;
            tm.first = i;
            tm.second = j;
            distanse[tm] = dist_change(city_mas[i], city_mas[j]);
            scene->addLine(city_mas[i].first, city_mas[i].second, city_mas[j].first,city_mas[j].second,pen0);
            }
        }
    }

    QString s;

    for(int x: path_mas)
    {
       s += QString::number(x) + " ";
    }
    qDebug()<<s;
*/

    int gorod_1 = random_int(city_mas.count());
    int gorod_2 = random_int(city_mas.count());

    QVector <int> tmp_vector = path_mas;
    int g = 0;

    if(gorod_1 < gorod_2)
    {
        g = gorod_2;

        for(int i = gorod_1; i < gorod_2; i++)
        {
             tmp_vector[i] = path_mas[g];
             g--;
        }
        tmp_vector[g] = path_mas[g];
    }
    else
    {
        g = gorod_1;

        for(int i = gorod_2; i < gorod_1; i++)
        {
             tmp_vector[i] = path_mas[g];
             g--;
        }
        tmp_vector[g] = path_mas[g];
    }
/*
    QString s1;

    for(int x: tmp_vector)
    {
       s1 += QString::number(x)+" ";
    }
    qDebug()<<s1;
    qDebug()<<gorod_1<<" "<<gorod_2;
*/

    //path_tmp || tmp_vector

    //---------------------------------------------------------------------------------------------------
    //ui->graphicsView->setScene(scene);

    return tmp_vector;
}

void MainWindow::main_function()
{
    QTime time;
    time.start ();
    double temp = 100.0;

    ui->progressBar->setMaximum(temp);
    double progress = 0;

while(temp > 0)
{
    QVector<int> tmp_vector = inventor();

    int path_tmp = 0;

    for(int i = 0; i < tmp_vector.count();i++)
    {
        int a = 0;
        int b = 0;

    if(i == 0)
    {
      a = tmp_vector[i];
      b = tmp_vector[tmp_vector.count()-1];

        //scene->addLine(city_mas[b].first,city_mas[b].second,city_mas[a].first,city_mas[a].second,pen2);
        path_tmp +=  dist_change(city_mas[b], city_mas[a]);
    }
    else
    {
        a = tmp_vector[i-1];
        b = tmp_vector[i];

        //scene->addLine(city_mas[a].first,city_mas[a].second,city_mas[b].first,city_mas[b].second,pen2);
        path_tmp +=  dist_change(city_mas[a], city_mas[b]);
    }
    }

    if(path_tmp < path)
    {
        path_mas = tmp_vector;
        path = path_tmp;
    }
    else
    {
        double p = probability(path_tmp - path, temp);
        int a = 0;
        double rand_ch = (double)random();

        if(rand_ch <= p)
            a = 1;
        else
            a = 0;

        if(a == 1)
        {
            path_mas = tmp_vector;
            path = path_tmp;
        }
    }
        temp -= 0.001;
        progress += 0.001;
        ui->progressBar->setValue(progress);

        if(temp > 0)
        ui->label_3->setText("Температура: " + QString::number(temp));
        else
        ui->label_3->setText("Температура: " + QString::number(0));
    }
   double t = time.elapsed();
   ui->label_4->setText("Температура: " + QString::number(t) +" ms");
   paint(path_mas);
}

void MainWindow::paint(QVector<int> vector)
{
    QGraphicsScene *scene = new QGraphicsScene(ui->graphicsView);
    QPen pen0(Qt::gray,1);

    for(int i = 0; i < city_mas.count(); i++)
    {
        for(int j = 0; j < city_mas.count(); j++)
        {
            if(i != j)
            {
            QPair<int,int> tm;
            tm.first = i;
            tm.second = j;
            distanse[tm] = dist_change(city_mas[i], city_mas[j]);
            scene->addLine(city_mas[i].first, city_mas[i].second, city_mas[j].first,city_mas[j].second,pen0);
            }
        }
    }

    QPen pen2(Qt::blue,3);
    double pt = 0;

    for(int i = 0; i < vector.count();i++)
    {
        int a = 0;
        int b = 0;

    if(i == 0)
    {
      a = vector[i];
      b = vector[vector.count()-1];

        scene->addLine(city_mas[b].first,city_mas[b].second,city_mas[a].first,city_mas[a].second,pen2);
        pt +=  dist_change(city_mas[b], city_mas[a]);
    }
    else
    {
        a = vector[i-1];
        b = vector[i];

        scene->addLine(city_mas[a].first,city_mas[a].second,city_mas[b].first,city_mas[b].second,pen2);
        pt +=  dist_change(city_mas[a], city_mas[b]);
    }
    }

    ui->label_2->setText("Длина пути: " + QString::number(path));
   // qDebug() << path;
    ui->graphicsView->setScene(scene);
}


double MainWindow::dist_change(QPair<double, double> city_1, QPair<double, double> city_2)
{
    double d = 0;
    d =  qSqrt(qPow((city_2.first - city_1.first),2)+qPow((city_2.second - city_1.second),2));
    return d;
}


















/* int l = 0;
 double R = 6371;//радиус Земли
 double d = 0;

 double m = 2*R * qAsin(qSqrt(qPow(qSin((city_2.first - city_1.first)/2), 2) + qCos(city_1.first) * qCos(city_2.first) * qPow(qSin((city_2.second - city_1.second)/2), 2)));
 l=(int)m;

*/
