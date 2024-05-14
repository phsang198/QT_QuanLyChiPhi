#include "Expense.h"
#include "src/Control.h"
#include "src/object.h"

//-------------------------------register------------------------------//
void Expense::regiter_clear()
{
    ui.username_re->setText("");
    ui.password_re->setText("");
    ui.confirm_password_re->setText("");
    ui.fullname_re->setText("");
    ui.role_re->setCurrentIndex(0);
}
void Expense::on_register_clicked()
{
    std::string username = ui.username_re->text().toStdString();
    std::string password = ui.password_re->text().toStdString();
    std::string confirm_password = ui.confirm_password_re->text().toStdString();
    if (password != confirm_password)
    {
        QMessageBox::warning(this, "Msg", "Password not match with confirm password!");
        return;
    }
    std::string fullname = ui.fullname_re->text().toStdString();
    std::string position = ui.role_re->currentText().toStdString();

    std::shared_ptr<object> obj = std::make_shared<user>(username, password, fullname, position);

    Controller::add(obj);
    QMessageBox::information(this, "Msg", "Add user successfully!");

    if (position == "ADMIN")
    {
        ui.tabwidget->setCurrentIndex(4);
    }
    else if (position == "USER")
    {
        ui.tabwidget->setCurrentIndex(5);
    }
    regiter_clear();
}