#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <indicator.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Indicator *ind;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pbn_changeState_clicked();

    void on_pbn_changeIndicate_clicked();

    void on_pbn_changeFrame_clicked();

    void on_pbn_changeText_clicked();



private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
