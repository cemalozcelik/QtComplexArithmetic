#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "complexnumber.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addComplexNumbers();
    void subtractComplexNumbers();
    void multiplyComplexNumbers();
    void divideComplexNumbers();

private:
    Ui::MainWindow *ui;
    ComplexNumber parseComplexNumber(const QString& input);
    void performComplexOperation(const QString& operationSymbol, const ComplexNumber& result);
};

#endif // MAINWINDOW_H
