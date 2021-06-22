/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QPushButton *pushButton;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QGraphicsView *graphicsView;
    QProgressBar *progressBar;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1011, 711);
        QFont font;
        font.setPointSize(8);
        font.setBold(true);
        font.setWeight(75);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(0, 40));
        pushButton->setFont(font1);

        gridLayout->addWidget(pushButton, 2, 0, 1, 2);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        gridLayout->addWidget(label_4, 0, 4, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font1);

        gridLayout->addWidget(label_3, 0, 3, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(50, 0));
        label->setMaximumSize(QSize(130, 16777215));
        label->setFont(font1);
        label->setTextFormat(Qt::PlainText);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(0, 30));
        lineEdit->setMaximumSize(QSize(250, 16777215));
        lineEdit->setFont(font1);

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 40));
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QStringLiteral("background-color: rgb(34, 178, 255); color: white;"));

        gridLayout->addWidget(pushButton_2, 2, 2, 1, 3);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setSceneRect(QRectF(0, 0, 1000, 1000));
        graphicsView->setResizeAnchor(QGraphicsView::NoAnchor);

        gridLayout->addWidget(graphicsView, 5, 0, 1, 5);

        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        gridLayout->addWidget(progressBar, 3, 0, 1, 5);


        verticalLayout->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1011, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\320\224\320\273\320\270\320\275\320\260 \320\277\321\203\321\202\320\270: 0", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\320\222\321\200\320\265\320\274\321\217: 0", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\320\242\320\265\320\274\320\277\320\265\321\200\320\260\321\202\321\203\321\200\320\260: 0", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\320\237\321\203\321\202\321\214 \320\272 \321\204\320\260\320\271\320\273\321\203:", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("MainWindow", "ch10.txt", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\240\320\260\321\201\321\201\321\207\320\270\321\202\320\260\321\202\321\214 \320\276\320\277\321\202\320\270\320\274\320\260\320\273\321\214\320\275\321\213\320\271 \320\274\320\260\321\200\321\210\321\200\321\203\321\202", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
