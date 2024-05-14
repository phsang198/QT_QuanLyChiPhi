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
    //-------------------------------login------------------------------//
    void on_login_clicked();
    void on_no_account_clicked();
    void on_forget_pass_clicked();
    //-------------------------------register------------------------------//
    void on_register_clicked();
    //-------------------------------forget password------------------------------//
    void on_change_pass_clicked();
    //-------------------------------update user------------------------------//
    void on_update_clicked();
    void on_logout_clicked();
    //-------------------------------adminpage------------------------------//

    //-------------------------------expense------------------------------//
    void on_about_me_clicked();

private:
    Ui::Form ui;
};
