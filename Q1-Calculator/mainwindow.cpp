#include "mainwindow.h"

#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow()
{
    QWidget *centralWidget = new QWidget(this);

    display = new QLineEdit();

    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    display->setMinimumHeight(50);

    QGridLayout *grid = new QGridLayout();

    QString buttons[4][4] =
    {
        {"7", "8", "9", "/"},
        {"4", "5", "6", "*"},
        {"1", "2", "3", "-"},
        {"0", ".", "C", "+"}
    };

    // Create buttons
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            QPushButton *button =
                new QPushButton(buttons[i][j]);

            button->setMinimumSize(60, 50);

            grid->addWidget(button, i, j);

            connect(button, &QPushButton::clicked,
                    this, [this, button]()
            {
                buttonClicked(button->text());
            });
        }
    }

    QPushButton *equalButton = new QPushButton("=");

    equalButton->setMinimumHeight(50);

    grid->addWidget(equalButton, 4, 0, 1, 4);

    connect(equalButton, &QPushButton::clicked,
            this, [this]()
    {
        calculate();
    });

    QVBoxLayout *mainLayout = new QVBoxLayout();

    mainLayout->addWidget(display);
    mainLayout->addLayout(grid);

    centralWidget->setLayout(mainLayout);

    setCentralWidget(centralWidget);

    // Window settings
    setWindowTitle("Calculator");
    resize(300, 400);
}


// Handle button clicks
void MainWindow::buttonClicked(QString value)
{
    if(value == "C")
    {
        display->clear();

        firstNumber = 0;
        operation.clear();
    }

    else if(value == "+" ||
            value == "-" ||
            value == "*" ||
            value == "/")
    {
        firstNumber = display->text().toDouble();

        operation = value;

        display->clear();
    }

    // Number and decimal buttons
    else
    {
        display->setText(display->text() + value);
    }
}


// Perform calculation
void MainWindow::calculate()
{
    double secondNumber = display->text().toDouble();

    double result = 0;

    if(operation == "+"){
        result = firstNumber + secondNumber;
    }

    else if(operation == "-"){
        result = firstNumber - secondNumber;
    }

    else if(operation == "*"){
        result = firstNumber * secondNumber;
    }

    else if(operation == "/"){
        if(secondNumber == 0){
            display->setText("Error");
            return;
        }

        result = firstNumber / secondNumber;
    }

    display->setText(QString::number(result));
}
