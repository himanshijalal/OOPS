#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>

class MainWindow : public QMainWindow
{
private:
    QLineEdit *display;

    double firstNumber = 0;
    QString operation;

    void buttonClicked(QString value);
    void calculate();

public:
    MainWindow();
};
