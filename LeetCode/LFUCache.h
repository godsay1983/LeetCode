#pragma once
#include <map>

class Node
{
public:
	Node()
	{
		this->freq = 0;
		this->value = 0;
		this->count = 0;
	}
	Node(int value, int count)
	{
		this->freq = 0;
		this->value = value;
		this->count = count;
	}
	int freq;
	int value;
	int count;
};

class LFUCache
{
private:
	std::map<int, Node> caches;
	int capacity;
	int count;
	int findLowestUsedNode();

public:
	LFUCache(int capacity);
	~LFUCache();

	void set(int key, int value);
	int get(int key);
};

