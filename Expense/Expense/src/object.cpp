#include "object.h"

object::object(OBJECT_TYPE _type, int _id)
{
	type = _type; 
	id = _id;
}

user::user(std::string _username, std::string _password, std::string _fullname, std::string _position, int _id)
{
	type = USER;
	username = _username; 
	password = _password;
	fullname = _fullname;
	position = _position;
	id		 = _id; 
}

std::string date;
std::string category;
std::string subcategory;
double amount;
double balance;
int id;
expense::expense(std::string _date, std::string _category, std::string _subcategory, double _amount, double _balance, int _id)
{
	type = EXPENSE;
	date = _date; 
	category = _category;
	subcategory = _subcategory;
	amount = _amount;
	balance = _balance;
	id = _id;
}
