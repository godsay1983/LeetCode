#include "NestedInteger.h"



NestedInteger::NestedInteger(int number)
{
	bInteger = true;
	this->number = number;
}

NestedInteger::NestedInteger(std::vector<int> intList)
{
	bInteger = false;
	this->intList.clear();
	for (auto int_list : intList)
	{
		this->intList.push_back(int_list);
	}
}

NestedInteger::~NestedInteger()
{
}

bool NestedInteger::isInteger() const
{
	return bInteger;
}

int NestedInteger::getInteger() const
{
	return number;
}

const std::vector<NestedInteger>& NestedInteger::getList() const
{
	return intList;
}
