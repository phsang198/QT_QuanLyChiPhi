#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Expense.h"

class Expense : public QMainWindow
{
    Q_OBJECT

public:
    Expense(QWidget *parent = nullptr);
    ~Expense();

private:
    Ui::Form ui;
};
