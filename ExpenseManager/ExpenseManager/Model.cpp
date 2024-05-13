﻿#include "Model.h"
#include "object.h"
#include "StringProcess.h"
sqlite3* CModel::db;
CModel::CModel()
{
	std::string db_path = StringProcess::getExePath() + "Res/db/data.db"; 
	int rc = sqlite3_open(db_path.c_str(), &db);

	if (rc) {
		std::cout << "Can not open db!" << sqlite3_errmsg(db) << std::endl;
	}
	else
	{
		const char* sql = R"(CREATE TABLE IF NOT EXISTS User (
			ID INTEGER PRIMARY KEY AUTOINCREMENT,
			fullname TEXT NOT NULL,
			username TEXT NOT NULL UNIQUE,
			password TEXT NOT NULL,
			position TEXT NOT NULL
			); )";

		rc = sqlite3_exec(db, sql, 0, 0, 0);

		if (rc != SQLITE_OK) {
			std::cout << "Table init error: " << sqlite3_errmsg(db) << std::endl;
			sqlite3_close(db);
		}
		const char* sql2 = R"(CREATE TABLE IF NOT EXISTS Expense (
			id INTEGER PRIMARY KEY AUTOINCREMENT,
			date DATE NOT NULL,
			category TEXT NOT NULL,
			subcategory TEXT,
			amount REAL NOT NULL,
			balance REAL NOT NULL
		); )";

		rc = sqlite3_exec(db, sql2, 0, 0, 0);

		if (rc != SQLITE_OK) {
			std::cout << "Table init error: " << sqlite3_errmsg(db) << std::endl;
			sqlite3_close(db);
		}
	}
}

CModel::~CModel()
{
	if (db) sqlite3_close(db);
}

bool CModel::add(std::shared_ptr<object> obj)
{
	std::string query = "";
	if (obj->type == OBJECT_TYPE::EXPENSE)
	{
		expense _exp = *obj->as<expense>();

		query = R"(INSERT INTO Expense (date, category, subcategory, amount, balance)
					VALUES ('$date', '$category', '$subcategory', $amount, $balance);)";
		StringProcess::ReplaceAll(query, "$date", _exp.date);
		StringProcess::ReplaceAll(query, "$category", _exp.category);
		StringProcess::ReplaceAll(query, "$subcategory", _exp.subcategory);
		StringProcess::ReplaceAll(query, "$amount", StringProcess::to_string_with_precision(_exp.amount));
		StringProcess::ReplaceAll(query, "$balance", StringProcess::to_string_with_precision(_exp.balance));

	}
	else
	{
		query = R"(INSERT INTO User (fullname, username, password, position)
					VALUES ('$fullname', '$username', '$password', '$position');)";

		user _user = *obj->as<user>();

		StringProcess::ReplaceAll(query, "$fullname", _user.fullname);
		StringProcess::ReplaceAll(query, "$username", _user.username);
		StringProcess::ReplaceAll(query, "$password", _user.password);
		StringProcess::ReplaceAll(query, "$position", _user.position);
	}

	int rc = sqlite3_exec(db, query.c_str(), 0, 0, 0);

	if (rc != SQLITE_OK) {
		std::cout << "query error: " << sqlite3_errmsg(db) << std::endl;
		sqlite3_close(db);
		return false;
	}
	return true;
}

bool CModel::update(std::shared_ptr<object> obj)
{
	std::string query = "";
	if (obj->type == OBJECT_TYPE::EXPENSE)
	{
		expense _exp = *obj->as<expense>();

		query = R"(UPDATE Expense 
					SET date = '$date', 
						category = '$category', 
						subcategory = '$subcategory', 
						amount = $amount, 
						balance = $balance
					WHERE id = id_khoan_chi_muon_cap_nhat;)";
		StringProcess::ReplaceAll(query, "$date", _exp.date);
		StringProcess::ReplaceAll(query, "$category", _exp.category);
		StringProcess::ReplaceAll(query, "$subcategory", _exp.subcategory);
		StringProcess::ReplaceAll(query, "$amount", StringProcess::to_string_with_precision(_exp.amount));
		StringProcess::ReplaceAll(query, "$balance", StringProcess::to_string_with_precision(_exp.balance));
		StringProcess::ReplaceAll(query, "$id", std::to_string(_exp.id));

	}
	else
	{
		query = R"(UPDATE User 
					SET fullname = '$fullname', 
						password = '$password', 
						position = '$position'
					WHERE ID = $id;)";

		user _user = *obj->as<user>();

		StringProcess::ReplaceAll(query, "$fullname", _user.fullname);
		StringProcess::ReplaceAll(query, "$username", _user.username);
		StringProcess::ReplaceAll(query, "$password", _user.password);
		StringProcess::ReplaceAll(query, "$position", _user.position);
		StringProcess::ReplaceAll(query, "$id"		, std::to_string(_user.id));
	}

	int rc = sqlite3_exec(db, query.c_str(), 0, 0, 0);

	if (rc != SQLITE_OK) {
		std::cout << "query error: " << sqlite3_errmsg(db) << std::endl;
		sqlite3_close(db);
		return false;
	}
	return true;
}

bool CModel::del(object obj)
{
	std::string query = R"(DELETE FROM $rsc 
							WHERE ID = $id;)";
	if (obj.type == OBJECT_TYPE::EXPENSE)
	{
		StringProcess::ReplaceAll(query, "$rsc", "Expense");
	}
	else
	{
		StringProcess::ReplaceAll(query, "$rsc", "User");
	}
	StringProcess::ReplaceAll(query, "$id", obj.id);

	int rc = sqlite3_exec(db, query.c_str(), 0, 0, 0);

	if (rc != SQLITE_OK) {
		std::cout << "query error: " << sqlite3_errmsg(db) << std::endl;
		sqlite3_close(db);
		return false;
	}
	return true;
}

bool CModel::getUser(user& _user)
{
	std::string query = "SELECT * FROM User WHERE ID = $id";
	StringProcess::ReplaceAll(query, "$id", std::to_string(_user.id));

	sqlite3_stmt* stmt;
	int rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);

	if (rc != SQLITE_OK)
	{
		sqlite3_close(db);
		return false;
	}

	if (sqlite3_step(stmt) == SQLITE_ROW) {
		_user.username = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
		_user.password = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
		_user.fullname = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
		_user.position = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
		_user.id = sqlite3_column_int(stmt, 0);
	}

	sqlite3_finalize(stmt);
	return true;
}
bool CModel::getlistExpense(std::vector<std::shared_ptr<expense>>& lst)
{
	const char* sql = "SELECT * FROM Expense";

	sqlite3_stmt* stmt;
	int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

	if (rc != SQLITE_OK) 
	{
		sqlite3_close(db);
		return false;
	}

	while (sqlite3_step(stmt) == SQLITE_ROW) 
	{
		std::shared_ptr<expense> exp(new expense(
			reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)),
			reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)),
			reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)),
			sqlite3_column_double(stmt, 4),
			sqlite3_column_double(stmt, 5),
			sqlite3_column_int(stmt, 0)
		));
		lst.push_back(exp);
	}

	sqlite3_finalize(stmt);
	return true;
}
