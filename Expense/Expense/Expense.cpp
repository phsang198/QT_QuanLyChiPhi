#include "Expense.h"

Expense::Expense(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    connect(ui.login, &QPushButton::clicked, this, &Expense::on_button_clicked);
}

Expense::~Expense()
{}

void Expense::on_button_clicked()
{
    QMessageBox::information(this, "Button Clicked", "You have clicked the button!");
}