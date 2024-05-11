#pragma once
#include <vector>
#include <memory>
#include "object.h"


class ObjectManager
{
public:
	ObjectManager() {};
	~ObjectManager() {};

public:
	static std::vector<std::shared_ptr<expense>> lst_expense; 
	static user _user; 

};