#include "Expense.h"
#include "src/Control.h"
#include "src/object.h"
#include "src/objectManager.h"

Expense::Expense(QWidget *parent)
    : QMainWindow(parent)
{
    ObjectManager::init(); 
    ui.setupUi(this);

    connect(ui.login, &QPushButton::clicked, this, &Expense::on_login_clicked);
    connect(ui.no_account_btn, &QPushButton::clicked, this, &Expense::on_no_account_clicked);
    connect(ui.forget_pass_btn, &QPushButton::clicked, this, &Expense::on_forget_pass_clicked);
    connect(ui.change, &QPushButton::clicked, this, &Expense::on_change_pass_clicked);

    connect(ui.about_me, &QPushButton::clicked, this, &Expense::on_about_me_clicked);

    connect(ui.update_btn, &QPushButton::clicked, this, &Expense::on_update_clicked);
    connect(ui.logout, &QPushButton::clicked, this, &Expense::on_logout_clicked);

    connect(ui.register_btn, &QPushButton::clicked, this, &Expense::on_register_clicked);
    
    connect(ui.categorycbb, &QComboBox::currentTextChanged, this, &Expense::onComboBoxValueChanged);

    connect(ui.about_me_ex, &QPushButton::clicked, this, &Expense::on_about_me_clicked);
    connect(ui.add, &QPushButton::clicked, this, &Expense::on_add_clicked);
    connect(ui.search, &QPushButton::clicked, this, &Expense::on_search_clicked);
    connect(ui.clear, &QPushButton::clicked, this, &Expense::on_clear_clicked);
    connect(ui.export_btn, &QPushButton::clicked, this, &Expense::on_export_clicked);
}

Expense::~Expense()
{}

