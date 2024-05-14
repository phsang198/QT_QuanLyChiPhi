#include "Expense.h"
#include "src/Control.h"
#include "src/object.h"


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
