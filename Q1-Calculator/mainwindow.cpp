#include "mainwindow.h" 
#include "./ui_mainwindow.h" 
MainWindow::MainWindow(QWidget *parent) 
: QMainWindow(parent) 
, ui(new Ui::MainWindow) 
{ 
ui->setupUi(this); 
newnumber=true; 
ui->display->installEventFilter(this); 
} 
MainWindow::~MainWindow() 
{ 
delete ui; 
} 
void MainWindow::on_button7_clicked() 
{ 
if (newnumber) 
{ 
ui->display->setText("7"); 
newnumber = false; 
} 
else 
{ 
ui->display->setText(ui->display->text() + "7"); 
} 
}
void MainWindow::on_button8_clicked() 
{ 
if (newnumber) 
{ 
ui->display->setText("8"); 
newnumber = false; 
} 
else 
{ 
ui->display->setText(ui->display->text() + "8"); 
} 
} 
void MainWindow::on_button9_clicked() 
{ 
if (newnumber) 
{ 
ui->display->setText("9"); 
newnumber = false; 
} 
else 
{ 
ui->display->setText(ui->display->text() + "9"); 
} 
} 
void MainWindow::on_button4_clicked() 
{ 
if (newnumber) 
{ 
ui->display->setText("4"); 
newnumber = false; 
} 
else 
{ 
ui->display->setText(ui->display->text() + "4"); 
} 
} 
void MainWindow::on_button5_clicked() 
{
    if (newnumber) 
{ 
ui->display->setText("5"); 
newnumber = false; 
} 
else 
{ 
ui->display->setText(ui->display->text() + "5"); 
} 
} 
void MainWindow::on_button6_clicked() 
{ 
if (newnumber) 
{ 
ui->display->setText("6"); 
newnumber = false; 
} 
else 
{ 
ui->display->setText(ui->display->text() + "6"); 
} 
} 
void MainWindow::on_button1_clicked() 
{ 
if (newnumber) 
{ 
ui->display->setText("1"); 
newnumber = false; 
} 
else 
{ 
ui->display->setText(ui->display->text() + "1"); 
} 
} 
void MainWindow::on_button2_clicked() 
{ 
if (newnumber) 
{ 
ui->display->setText("2"); 
newnumber = false;
} 
else 
{ 
ui->display->setText(ui->display->text() + "2"); 
} 
} 
void MainWindow::on_button3_clicked() 
{ 
if (newnumber) 
{ 
ui->display->setText("3"); 
newnumber = false; 
} 
else 
{ 
ui->display->setText(ui->display->text() + "3"); 
} 
} 
void MainWindow::on_button0_clicked() 
{ 
if (newnumber) 
{ 
ui->display->setText("0"); 
newnumber = false; 
} 
else 
{ 
ui->display->setText(ui->display->text() + "0"); 
} 
} 
void MainWindow::on_buttonplus_clicked() 
{ 
firstnumber = ui->display->text().toDouble(); 
operation = "+"; 
ui->display->clear(); 
} 
void MainWindow::on_buttonEquals_clicked() 
{ 
double secondnumber = ui->display->text().toDouble(); 
if (operation == "+") 
{ 
ui->display->setText(QString::number(firstnumber + secondnumber)); 
} 
else if (operation == "-") 
{ 
ui->display->setText(QString::number(firstnumber - secondnumber)); 
} 
else if (operation == "*") 
{ 
ui->display->setText(QString::number(firstnumber * secondnumber)); 
} 
else if (operation == "/") 
{ 
if (secondnumber != 0) 
{ 
ui->display->setText(QString::number(firstnumber / secondnumber)); 
} 
else 
{ 
ui->display->setText("Error"); 
} 
} 
newnumber=true; 
} 
void MainWindow::on_buttonMinus_clicked() 
{ 
firstnumber = ui->display->text().toDouble(); 
operation = "-"; 
ui->display->clear(); 
} 
void MainWindow::on_buttonMultiply_clicked() 
{ 
firstnumber = ui->display->text().toDouble(); 
operation = "*"; 
ui->display->clear(); 
} 
void MainWindow::on_buttonDivide_clicked() 
{ 
firstnumber = ui->display->text().toDouble(); 
operation = "/"; 
ui->display->clear(); 
} 
void MainWindow::on_clearbutton_clicked() 
{ 
ui->display->clear(); 
firstnumber=0; 
operation = ""; 
newnumber = true; 
} 
void MainWindow::keyPressEvent(QKeyEvent *event) 
{ 
if (event->key() == Qt::Key_0) 
on_button0_clicked(); 
else if (event->key() == Qt::Key_1) 
on_button1_clicked(); 
else if (event->key() == Qt::Key_2) 
on_button2_clicked(); 
else if (event->key() == Qt::Key_3) 
on_button3_clicked(); 
else if (event->key() == Qt::Key_4) 
on_button4_clicked(); 
else if (event->key() == Qt::Key_5) 
on_button5_clicked(); 
else if (event->key() == Qt::Key_6) 
on_button6_clicked(); 
else if (event->key() == Qt::Key_7) 
on_button7_clicked(); 
else if (event->key() == Qt::Key_8) 
on_button8_clicked(); 
else if (event->key() == Qt::Key_9) 
on_button9_clicked(); 
else if (event->key() == Qt::Key_Plus) 
on_buttonplus_clicked(); 
else if (event->key() == Qt::Key_Minus) 
on_buttonMinus_clicked(); 
else if (event->key() == Qt::Key_Asterisk) 
on_buttonMultiply_clicked(); 
else if (event->key() == Qt::Key_Slash) 
on_buttonDivide_clicked(); 
else if (event->key() == Qt::Key_Return || 
event->key() == Qt::Key_Enter) 
{ 
on_buttonEquals_clicked(); 
} 
else if (event->key() == Qt::Key_Escape) 
{ 
on_clearbutton_clicked(); 
} 
else if (event->key() == Qt::Key_Backspace) 
{ 
QString text = ui->display->text(); 
if (!text.isEmpty()) 
{ 
text.chop(1); 
ui->display->setText(text); 
} 
} 
} 
bool MainWindow::eventFilter(QObject *obj, QEvent *event) 
{ 
if (obj == ui->display && event->type() == QEvent::KeyPress) 
{ 
QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event); 
if (keyEvent->key() == Qt::Key_Backspace) 
{ 
QString text = ui->display->text();
if (!text.isEmpty()) 
{ 
text.chop(1); 
ui->display->setText(text); 
} 
 
return true; 
} 
} 
 
return QMainWindow::eventFilter(obj, event); 
}
