#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <indicator.h>
#include <QDebug>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Демонстрация работы виджета");
    ind=ui->indicate;
    connect(ui->pbn_changeState,&QPushButton::clicked,ind,&Indicator::changeState);
    connect(ui->pbn_changeIndicate,&QPushButton::clicked,ind,&Indicator::changeState);
    connect(ui->pbn_changeFrame,&QPushButton::clicked,ind,&Indicator::changeFrame);
    connect(ui->pbn_changeText,&QPushButton::clicked,ind,&Indicator::changeName);
    connect(ind,&Indicator::changeColorState,ind,&Indicator::updateStatePainter);
    connect(ind,&Indicator::changeState,ind,&Indicator::updateStatePainter);
    connect(ind,&Indicator::changeName,ind,&Indicator::updateStatePainter);
    connect(ind,&Indicator::changeFrame,ind,&Indicator::updateStatePainter);
    ind->setInformMessage("Все прекрасно, ошибки нет");
    ind->setErrorMessage("Для исправления данной ошибки выполните следующие действия:\n"
                         "1...\n"
                         "2...\n");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbn_changeState_clicked()
{
    STATE currentState = static_cast<STATE>(ind->property("state").toInt());
    ind->setProperty("state", QVariant::fromValue(currentState == STATE::On ? STATE::Error : STATE::On));
}

void MainWindow::on_pbn_changeIndicate_clicked()
{
    STATE currentState = static_cast<STATE>(ind->property("state").toInt());
    ind->setProperty("state", QVariant::fromValue(currentState == STATE::Off ? STATE::On : STATE::Off));
    if(currentState==STATE::Off)
    {
        ui->pbn_changeIndicate->setText("Отключить индикацию");

    }
    else if(currentState==STATE::On)
    {
        ui->pbn_changeIndicate->setText("Включить индикацию");
    }
    else
    {
        return;
    }
}

void MainWindow::on_pbn_changeFrame_clicked()
{
    auto color=QColorDialog::getColor(Qt::white,nullptr,"Выберите цвет рамки виджета",QColorDialog::ShowAlphaChannel);
    QPen m_frame;
    m_frame.setColor(color);// рамка виджета
    m_frame.setWidth(2);
    m_frame.setStyle(Qt::SolidLine);
    ind->setProperty("frame",QVariant(m_frame));
}

void MainWindow::on_pbn_changeText_clicked()
{
    bool ok;
    QString name = QInputDialog::getText(this, "Введите название индикатора ",
                                         "Имя индикатора:",
                                         QLineEdit::Normal, "", &ok);
    auto color=QColorDialog::getColor(Qt::white,nullptr,"Выберите цвет текста с именем ошибки ",QColorDialog::ShowAlphaChannel);
    ind->setProperty("color_text",QVariant(color));
    ind->setProperty("name",QVariant(name));
}

