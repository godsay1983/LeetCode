#include "Solution.h"
#include <set>
#include <algorithm>

std::vector<int> Solution::twoSum(std::vector<int>& nums, int target)
{
	std::vector<int> result;
	for (int i = 0; i < nums.size() - 1; ++i)
	{
		for (int j = i + 1; j < nums.size(); ++j)
		{
			if (nums[i] + nums[j] == target)
			{
				result.push_back(i);
				result.push_back(j);
				return result;
			}
		}
	}
	return result;
}

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode* res = new ListNode(-1);
	ListNode* cur = res;
	int carry = 0;
	while (l1 || l2)
	{
		int n1 = l1 ? l1->val : 0;
		int n2 = l2 ? l2->val : 0;
		int sum = n1 + n2 + carry;
		carry = sum / 10;
		cur->next = new ListNode(sum % 10);
		cur = cur->next;
		if (l1) l1 = l1->next;
		if (l2) l2 = l2->next;
	}
	if (carry) cur->next = new ListNode(1);
	return res->next;
}

int Solution::lengthOfLongestSubstring(std::string s)
{
	int n = s.length();
	int ans = 0;
	int i = 0;
	int j = 0;
	std::set<char> ch;
	while (i < n && j < n)
	{
		if (ch.find(s[j]) == ch.end())
		{
			ch.insert(s[j]);
			j++;
			ans = std::max(ans, j - i);
		}
		else
		{
			ch.erase(s[i]);
			i++;
		}
	}
	return ans;
}
