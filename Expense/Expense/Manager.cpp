#include "Expense.h"
#include "src/Control.h"
#include "src/object.h"
#include "src/objectManager.h"
#include "ExpenseTable.h"
#include "ExpenseChart.h"
#include "src/StringProcess.h"

// Function: Manager
// Description: [include some functions for expense manager's task in view].
// 
//-------------------------------expense------------------------------//
void Expense::on_about_me_clicked()
{
    About_me_view();
}
void Expense::on_add_clicked()
{
    std::string cate = ui.categorycbb->currentText().toStdString();
    std::string subcate = ui.subcategorycbb->currentText().toStdString();
    std::string amount = ui.amounttxt->text().toStdString();

    std::string balance = ui.balancetxt->text().toStdString();
    std::string date = ui.datetxt->text().toStdString();

    if (cate == "" || date == "" || amount == "" || balance == "")
    {
        QMessageBox::warning(this, "Error", "Empty input!");
        return;
    }

    std::shared_ptr<object> obj = std::make_shared<expense>(ObjectManager::_user.id, date,cate, subcate, std::stod(amount),std::stod(balance));

    std::string msg = "";
    Controller::add(obj, msg);
    if (msg != "")
    {
        QMessageBox::warning(this, "Error", msg.c_str());
    }
    else
    {
        QMessageBox::information(this, "Msg", "Add expense successfully!");
        Controller::getListExpense();
        table_view(ObjectManager::lst_expense);
    }
    
}
void Expense::on_search_clicked()
{
    Controller::getListExpense();

    std::string key = ui.filtertxt->text().toStdString();
    std::string dateFr = ui.dateFromtxt->text().toStdString();
    std::string dateTo = ui.dateTotxt->text().toStdString();

    if (StringProcess::compareDates(dateFr, dateTo) == 1)
    {
        QMessageBox::warning(this, "Error", "From date after To date!");
        return;
    }
    if (key == "" || dateFr == "" || dateTo == "")
    {
        QMessageBox::warning(this, "Error", "Empty input!");
        return;
    }
    Controller::search(dateFr, dateTo, key); 
    table_view(ObjectManager::lst_expense);
}
void Expense::on_clear_clicked()
{
    ui.dateFromtxt->setText("");
    ui.dateTotxt->setText("");
    ui.filtertxt->setText("");

    Controller::getListExpense();
    table_view(ObjectManager::lst_expense);
}
void Expense::on_export_clicked()
{
    if (ObjectManager::lst_expense.size() == 1 )
    {
        QMessageBox::information(this, "MSG", "data has only one row!");
        return;
    }
    std::map<std::string, bool> check_cat, check_sub; 
    for (auto& x : ObjectManager::lst_expense)
    {
        check_cat[x->category] = true;
        if ( x->subcategory != "") 
            check_sub[x->subcategory] = true;
    }
    if (check_cat.size() > 1 )
    {
        QMessageBox::warning(this, "Error", "More than one type for drawing chart!");
        return; 
    }
    std::string type = "";
    if (check_cat.size() == 1)
        type = "category";
    else type = "subcategory"; 

    ChartDialog dialog(this, ObjectManager::lst_expense, type);
    dialog.resize(800, 600);
    dialog.exec();
    ChartDialog2 dialog2(this, ObjectManager::lst_expense, type);
    dialog2.resize(800, 600);
    dialog2.exec();
}
void Expense::onComboBoxValueChanged()
{
    ui.subcategorycbb->clear();
    std::string category = ui.categorycbb->currentText().toStdString(); 
    for (auto subcate : ObjectManager::lst_category[category])
        ui.subcategorycbb->addItem(subcate.c_str());
}
void Expense::Manager_clear()
{
    ui.categorycbb->clear();
    ui.subcategorycbb->clear();
    ui.amounttxt->setText("");
    ui.balancetxt->setText("");
    ui.datetxt->setText("");
    ui.dateFromtxt->setText("");
    ui.dateTotxt->setText("");
    ui.filtertxt->setText("");
}

void Expense::table_view(std::vector<std::shared_ptr<expense>> lst)
{
    if ( model ) 
        model->clearData(); 
    model = new ExpenseModel(lst, this);
    ui.tableView->setModel(model);
    ui.tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}
void Expense::Manager_view()
{
    ui.tabwidget->setCurrentIndex(5);
    Manager_clear(); 
    std::string first = ""; 
    for (auto cate : ObjectManager::lst_category)
    {
        ui.categorycbb->addItem(cate.first.c_str());
        if (first == "") first = cate.first; 
    }
    ui.categorycbb->setCurrentText(first.c_str());

    Controller::getListExpense(); 
    table_view(ObjectManager::lst_expense); 
    //delete model;

    //setCentralWidget(ui.tableView);
}