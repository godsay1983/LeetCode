#include "LFUCache.h"

int LFUCache::findLowestUsedNode()
{
	int key = -1;
	int lowestFreq = INT_MAX;
	for (auto it = caches.begin(); it != caches.end(); ++it)
	{
		Node node = it->second;
		if (lowestFreq > node.freq)
		{
			lowestFreq = node.freq;
			key = it->first;
		}
		else if (lowestFreq == node.freq && node.count < caches[key].count)
		{
			lowestFreq = node.freq;
			key = it->first;
		}
	}
	return key;
}

LFUCache::LFUCache(int capacity)
{
	this->capacity = capacity;
	this->count = 0;
}

LFUCache::~LFUCache()
{
}

void LFUCache::set(int key, int value)
{
	auto it = caches.find(key);
	if (it != caches.end())
	{
		caches[key].count = count;
		caches[key].value = value;
		caches[key].freq++;
	}
	else
	{
		if (caches.size() == capacity)
		{
			int lowestKey = findLowestUsedNode();
			caches.erase(lowestKey);
		}
		caches[key] = Node(value, count);
	}
	count++;
}

int LFUCache::get(int key)
{
	auto it = caches.find(key);
	if (it != caches.end())
	{
		count++;
		caches[key].count = count;
		caches[key].freq++;
		return caches[key].value;
	}
	return -1;
}
