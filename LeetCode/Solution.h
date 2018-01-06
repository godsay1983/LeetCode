#pragma once
#include <vector>


struct ListNode
{
	int val;
	ListNode* next;

	ListNode(int x) : val(x), next(NULL)
	{
	}
};

class Solution
{
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target);
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
	int lengthOfLongestSubstring(std::string s);
	int lengthOfLongestSubstring2(std::string s);
};
