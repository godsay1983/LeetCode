#pragma once
#include <vector>

using namespace std;

class MinStack
{
	vector<int> data;
public:
	MinStack();
	~MinStack();
	void push(int number);
	int pop();
	int min();
};

