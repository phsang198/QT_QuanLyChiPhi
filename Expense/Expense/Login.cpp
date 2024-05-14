#include "Expense.h"
#include "src/Control.h"
#include "src/object.h"

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