#ifndef MAINWINDOW_H 
#define MAINWINDOW_H 
#include <QMainWindow> 
#include <QKeyEvent> 
#include <QEvent>
QT_BEGIN_NAMESPACE 
namespace Ui { 
class MainWindow; 
} 
QT_END_NAMESPACE 
class MainWindow : public QMainWindow 
{ 
Q_OBJECT 
public: 
explicit MainWindow(QWidget *parent = nullptr); 
~MainWindow() override; 
private: 
double firstnumber; 
QString operation; 
bool newnumber; 
private slots: 
void on_button7_clicked(); 
void on_button8_clicked(); 
void on_button9_clicked(); 
void on_button4_clicked(); 
void on_button5_clicked(); 
void on_button6_clicked(); 
void on_button1_clicked(); 
void on_button2_clicked(); 
void on_button3_clicked(); 
void on_button0_clicked(); 
void on_buttonplus_clicked(); 
void on_buttonEquals_clicked(); 
void on_buttonMinus_clicked();
void on_buttonMultiply_clicked(); 
void on_buttonDivide_clicked(); 
void on_clearbutton_clicked(); 
protected: 
void keyPressEvent(QKeyEvent *event) override; 
bool eventFilter(QObject *obj, QEvent *event) override; 
private: 
Ui::MainWindow *ui; 
}; 
#endif // MAINWINDOW_H
