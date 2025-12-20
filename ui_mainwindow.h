/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "indicator.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *pbn_changeFrame;
    Indicator *indicate;
    QSpacerItem *horizontalSpacer;
    QPushButton *pbn_changeIndicate;
    QPushButton *pbn_changeText;
    QPushButton *pbn_changeState;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(466, 198);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(68, 73, 104, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        MainWindow->setPalette(palette);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pbn_changeFrame = new QPushButton(centralwidget);
        pbn_changeFrame->setObjectName(QString::fromUtf8("pbn_changeFrame"));

        gridLayout->addWidget(pbn_changeFrame, 2, 1, 1, 1);

        indicate = new Indicator(centralwidget);
        indicate->setObjectName(QString::fromUtf8("indicate"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(indicate->sizePolicy().hasHeightForWidth());
        indicate->setSizePolicy(sizePolicy);
        indicate->setMinimumSize(QSize(55, 65));
        indicate->setMaximumSize(QSize(55, 65));

        gridLayout->addWidget(indicate, 0, 0, 5, 1);

        horizontalSpacer = new QSpacerItem(319, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 5, 0, 1, 1);

        pbn_changeIndicate = new QPushButton(centralwidget);
        pbn_changeIndicate->setObjectName(QString::fromUtf8("pbn_changeIndicate"));

        gridLayout->addWidget(pbn_changeIndicate, 0, 1, 1, 1);

        pbn_changeText = new QPushButton(centralwidget);
        pbn_changeText->setObjectName(QString::fromUtf8("pbn_changeText"));

        gridLayout->addWidget(pbn_changeText, 3, 1, 1, 1);

        pbn_changeState = new QPushButton(centralwidget);
        pbn_changeState->setObjectName(QString::fromUtf8("pbn_changeState"));

        gridLayout->addWidget(pbn_changeState, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 466, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pbn_changeFrame->setText(QCoreApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\200\320\260\320\274\320\272\320\270", nullptr));
        pbn_changeIndicate->setText(QCoreApplication::translate("MainWindow", "\320\222\320\272\320\273\321\216\321\207\320\270\321\202\321\214 \320\270\320\275\320\264\320\270\320\272\320\260\321\206\320\270\321\216", nullptr));
        pbn_changeText->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217 \320\276\321\210\320\270\320\261\320\272\320\270", nullptr));
        pbn_changeState->setText(QCoreApplication::translate("MainWindow", "\320\241\320\274\320\265\320\275\320\270\321\202\321\214 \321\201\320\276\321\201\321\202\320\276\321\217\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
