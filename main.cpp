#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDoubleValidator>
#include <QIntValidator>
#include <QFont>
#include <iostream>
#include "DepositCalculator.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    DepositCalculator calculator(10.3);
    calculator.show();

    return app.exec();
}