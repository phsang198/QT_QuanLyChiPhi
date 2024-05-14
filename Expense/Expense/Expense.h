#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Expense.h"
#include <QMessageBox>

class Expense : public QMainWindow
{
    Q_OBJECT

public:
    Expense(QWidget *parent = nullptr);
    ~Expense();

private slots:
    void on_button_clicked();

private:
    Ui::Form ui;
};
