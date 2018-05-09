#pragma once
#include <vector>

class NestedInteger
{
private:
	int number;
	bool bInteger;
	std::vector<NestedInteger> intList;
public:
	NestedInteger(int number);
	NestedInteger(std::vector<int> intList);
	~NestedInteger();
	bool isInteger() const;
	int getInteger() const;
	const std::vector<NestedInteger> &getList() const;
};

