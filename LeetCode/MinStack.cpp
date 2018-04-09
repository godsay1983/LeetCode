#include "MinStack.h"

MinStack::MinStack()
{
}

MinStack::~MinStack()
{
}

void MinStack::push(int number)
{
	data.push_back(number);
}

int MinStack::pop()
{
	int last = data.back();
	data.pop_back();
	return last;
}

int MinStack::min()
{
	int min = data.front();
	for (int i = 1; i < data.size(); ++i)
	{
		if (min > data[i])
		{
			min = data[i];
		}
	}
	return min;
}
