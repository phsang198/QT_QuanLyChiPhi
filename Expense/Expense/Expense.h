#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Expense.h"
#include <memory>
#include <QMessageBox>
#include <src/object.h>
#include "ExpenseTable.h"

// Expense: ChartDialog
// Description: [To be used to manager View and some events of view ].
// 

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
    void login_view();
    //-------------------------------register------------------------------//
    void on_register_clicked();
    void Register_view();
    void regiter_clear();
    //-------------------------------forget password------------------------------//
    void on_change_pass_clicked();
    void fotget_passs_view();
    //-------------------------------update user------------------------------//
    void on_update_clicked();
    void on_logout_clicked();
    //-------------------------------adminpage------------------------------//
    void Admin_view();

    //-------------------------------expense------------------------------//
    void on_about_me_clicked();
    void on_add_clicked();
    void on_search_clicked();
    void on_clear_clicked();
    void on_export_clicked();
    void Manager_view();
    void onComboBoxValueChanged();

    void Manager_clear();

    void table_view(std::vector<std::shared_ptr<expense>> lst);

    //-------------------------------About me------------------------------//
    void About_me_view();
private:
    Ui::ExpenseManager ui;
    ExpenseModel* model; 
};
