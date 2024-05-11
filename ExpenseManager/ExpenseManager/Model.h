#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <memory>
#include <sqlite3.h>

class object;
class user; 
class expense;

class CModel
{
public:
	CModel();
	~CModel();
public:
	static sqlite3* db;
public:
	bool add(std::shared_ptr<object> ) ;
	bool update(std::shared_ptr<object>) ;
	bool del(object);
public:
	bool getUser(user&);
	bool getlistExpense(std::vector<std::shared_ptr<expense>>&);

};