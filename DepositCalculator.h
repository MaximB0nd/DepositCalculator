//
// Created by Максим Бондарев on 26.06.2025.
//

#ifndef DEPOSITCALCULATOR_H
#define DEPOSITCALCULATOR_H

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

class DepositCalculator : public QWidget {

    public:

    double percent;

    DepositCalculator(double percent) : QWidget(nullptr), percent(percent) {

        QVBoxLayout *mainLayout = new QVBoxLayout(this);

        QLabel *titleLabel = new QLabel("Моя первая программа");
        titleLabel->setAlignment(Qt::AlignCenter);

        QFormLayout *formLayout = new QFormLayout();

        sumEdit = new QLineEdit();
        sumEdit->setValidator(new QDoubleValidator(0, 100000000, 5, this));
        sumEdit->setText("");
        formLayout->addRow("Сумма (руб):", sumEdit);

        termEdit = new QLineEdit();
        termEdit->setValidator(new QIntValidator(1, 99999999999999, this));
        termEdit->setText("");
        formLayout->addRow("Срок (мес):", termEdit);

        rateLabel = new QLabel();
        rateLabel->setText(QString("%1%").arg(percent, 0, 'd', 2).replace(".", ","));
        formLayout->addRow("Процентная ставка:", rateLabel);

        resultLabel = new QLabel("0,00 ₽");
        formLayout->addRow("Доход:", resultLabel);

        QPushButton *calculateButton = new QPushButton("Рассчитать");

        // Собираем интерфейс
        mainLayout->addWidget(titleLabel);
        mainLayout->addLayout(formLayout);
        mainLayout->addStretch();
        mainLayout->addWidget(calculateButton);

        // Соединяем кнопку с функцией расчета
        connect(calculateButton, &QPushButton::clicked, this, &DepositCalculator::calculate);

        // Первоначальный расчет
        calculate();

        // Настройки окна
        setWindowTitle("Калькулятор вкладов");
        setMinimumSize(350, 300);
        setMaximumSize(350, 300);
    }

    private:

    QLineEdit *sumEdit;
    QLineEdit *termEdit;
    QLabel *rateLabel;
    QLabel *resultLabel;

    void calculate() {
        double sum = sumEdit->text().replace(",", ".").toDouble();
        int term = termEdit->text().toInt();
        double income = sum * percent * term / 1200.0;

        resultLabel->setText(QString("%1 ₽").arg(income, 0, 'f', 2).replace(".", ","));
    }

};

#endif //DEPOSITCALCULATOR_H
