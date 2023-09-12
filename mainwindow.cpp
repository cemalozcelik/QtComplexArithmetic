#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "complexnumber.h"
#include "complexlineedit.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString styleSheet = "QLineEdit {"
                         "    border: 2px solid gray;"
                         "    border-radius: 5px;"
                         "    padding: 2px 4px;"
                         "    background: white;"
                         "    color: black;"
                         "    font-weight: bold;"
                         "    text-align: center;"
                         "    text-shadow: 1px 1px 2px rgba(0, 0, 0, 0.5);" // Shadow effect
                         "}";





    connect(ui->addButton, SIGNAL(clicked()), this, SLOT(addComplexNumbers()));
    connect(ui->subtractButton, SIGNAL(clicked()), this, SLOT(subtractComplexNumbers()));
    connect(ui->multiplyButton, SIGNAL(clicked()), this, SLOT(multiplyComplexNumbers()));
    connect(ui->divideButton, SIGNAL(clicked()), this, SLOT(divideComplexNumbers()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addComplexNumbers() {
    QString input1 = ui->lineEdit1->text();
    QString input2 = ui->lineEdit2->text();

    ComplexNumber num1 = parseComplexNumber(input1);
    ComplexNumber num2 = parseComplexNumber(input2);
    ComplexNumber result = num1 + num2;

    ui->resultLabel->setText("Result: " + QString::fromStdString(result.toString()));
}

void MainWindow::subtractComplexNumbers() {
    QString input1 = ui->lineEdit1->text();
    QString input2 = ui->lineEdit2->text();

    ComplexNumber num1 = parseComplexNumber(input1);
    ComplexNumber num2 = parseComplexNumber(input2);
    std::cout << "Subtracting: " << num1 << " and " << num2 << std::endl;

    ComplexNumber result = num1 - num2;

    ui->resultLabel->setText("Result: " + QString::fromStdString(result.toString()));
}


void MainWindow::multiplyComplexNumbers() {
    QString input1 = ui->lineEdit1->text();
    QString input2 = ui->lineEdit2->text();

    ComplexNumber num1 = parseComplexNumber(input1);
    ComplexNumber num2 = parseComplexNumber(input2);

    ComplexNumber result = num1 * num2;

    ui->resultLabel->setText("Result: " + QString::fromStdString(result.toString()));
}


void MainWindow::divideComplexNumbers() {
    QString input1 = ui->lineEdit1->text();
    QString input2 = ui->lineEdit2->text();

    ComplexNumber num1 = parseComplexNumber(input1);
    ComplexNumber num2 = parseComplexNumber(input2);

    if (num2.getReal() == 0.0 && num2.getImaginary() == 0.0) {
        ui->resultLabel->setText("Result: Division by zero is undefined.");
    } else {
        ComplexNumber result = num1 / num2;
        ui->resultLabel->setText("Result: " + QString::fromStdString(result.toString()));
    }
}


ComplexNumber MainWindow::parseComplexNumber(const QString& input) {
    QStringList parts = input.split("+");
    if (parts.size() != 2) {
        // Handle invalid input here, e.g., display an error message.
        return ComplexNumber(0.0, 0.0);
    }

    bool ok1, ok2;
    double real = parts[0].trimmed().toDouble(&ok1);
    double imaginary = parts[1].trimmed().left(parts[1].size() - 1).toDouble(&ok2);

    if (!ok1 || !ok2) {
        // Handle conversion errors here, e.g., display an error message.
        return ComplexNumber(0.0, 0.0);
    }

    return ComplexNumber(real, imaginary);
}

