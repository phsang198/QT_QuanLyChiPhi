#pragma once
#include "Model.h"

class Controller
{
public:
	Controller() {};
	~Controller() {};

public:
	static CModel model;
public:
	static void getListExpense(); 
	static void getUser(std::string , std::string, std::string& );
	static void add(std::shared_ptr<object>);
	static void update(std::shared_ptr<object>);
	static void del(std::shared_ptr<object>);
};
