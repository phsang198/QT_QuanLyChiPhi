#include "Expense.h"

Expense::Expense(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    connect(ui.login, &QPushButton::clicked, this, &Expense::on_login_clicked);
    connect(ui.no_account_btn, &QPushButton::clicked, this, &Expense::on_no_account_clicked);
    connect(ui.forget_pass_btn, &QPushButton::clicked, this, &Expense::on_forget_pass_clicked);
    connect(ui.change, &QPushButton::clicked, this, &Expense::on_change_pass_clicked);

    connect(ui.about_me, &QPushButton::clicked, this, &Expense::on_about_me_clicked);
    connect(ui.about_me_ex, &QPushButton::clicked, this, &Expense::on_about_me_clicked);

    connect(ui.update_btn, &QPushButton::clicked, this, &Expense::on_update_clicked);
    connect(ui.logout, &QPushButton::clicked, this, &Expense::on_logout_clicked);

    connect(ui.register_btn, &QPushButton::clicked, this, &Expense::on_register_clicked);
}

Expense::~Expense()
{}

//-------------------------------login------------------------------//
void Expense::on_login_clicked()
{
    ui.tabwidget->setCurrentIndex(5);
}
void Expense::on_no_account_clicked()
{
    ui.tabwidget->setCurrentIndex(2);
}
void Expense::on_forget_pass_clicked()
{
    ui.tabwidget->setCurrentIndex(1);
}
//-------------------------------register------------------------------//
void Expense::on_register_clicked()
{
    ui.tabwidget->setCurrentIndex(0);
}
//-------------------------------forget password------------------------------//
void Expense::on_change_pass_clicked()
{
    ui.tabwidget->setCurrentIndex(0);
}
//-------------------------------update user------------------------------//
void Expense::on_update_clicked()
{
    //ui.tabwidget->setCurrentIndex(0);
    QMessageBox::information(this, "Msg", "Update successfully!");
}
//-------------------------------adminpage------------------------------//
void Expense::on_logout_clicked()
{
    ui.tabwidget->setCurrentIndex(0);
}
//-------------------------------expense------------------------------//
void Expense::on_about_me_clicked()
{
    ui.tabwidget->setCurrentIndex(3);
}