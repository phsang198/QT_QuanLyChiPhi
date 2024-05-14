#include "Control.h"
#include "objectManager.h"
#include "StringProcess.h"

CModel Controller::model;

void Controller::getListExpense()
{
	model.getlistExpense(ObjectManager::lst_expense);
	StringProcess::Sort(ObjectManager::lst_expense);
}

void Controller::getUser(std::string username, std::string password, std::string& msg)
{
	ObjectManager::_user.password = password;
	ObjectManager::_user.username = username;
	model.getUser(ObjectManager::_user); 
}

void Controller::add(std::shared_ptr<object> obj)
{
	bool res = model.add(obj);
	if (obj->type == EXPENSE && res)
		getListExpense(); 
	else
	{

	}
}

void Controller::update(std::shared_ptr<object> obj)
{
	bool res = model.update(obj);
	if (obj->type == EXPENSE && res)
		getListExpense();
}

void Controller::del(std::shared_ptr<object> obj)
{
	bool res = model.del(*obj);
	if (obj->type == EXPENSE && res)
		getListExpense();
}
