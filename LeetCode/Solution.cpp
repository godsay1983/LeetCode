﻿#include "Solution.h"
#include <set>
#include <algorithm>
#include <map>

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

int Solution::lengthOfLongestSubstring2(std::string s)
{
	int n = s.length();
	int ans = 0;
	std::map<char, int> m;
	for (int i = 0, j = 0; j < n; ++j)
	{
		if (m.find(s[j]) != m.end())
		{
			i = std::max(m.at(s[j]), i);
		}
		ans = std::max(ans, j - i + 1);
		m[s[j]] = j + 1;
	}
	return ans;
}

double Solution::findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
{
	std::vector<int> nums;
	nums.reserve(int(nums1.size() + nums2.size()));
	nums.insert(nums.end(), nums1.begin(), nums1.end());
	nums.insert(nums.end(), nums2.begin(), nums2.end());
	sort(nums.begin(), nums.end());
	int n = nums.size();
	if (n % 2 == 0)
	{
		return (nums[n / 2 - 1] + nums[n / 2]) / 2.0;
	}
	else
	{
		return nums[n / 2];
	}
}

double Solution::findKthNumber(std::vector<int> nums1, std::vector<int> nums2, int k)
{
	if (nums1.size() > nums2.size())
	{
		return findKthNumber(nums2, nums1, k);
	}
	if (nums1.size() == 0)
	{
		return nums2[k - 1];
	}
	if (k == 1)
	{
		return std::min(nums1[0], nums2[0]);
	}
	int p1 = std::min(k / 2, int(nums1.size()));
	int p2 = k - p1;

	if (nums1[p1 - 1] < nums2[p2 - 1])
	{
		nums1.assign(nums1.begin() + p1, nums1.end());
		return findKthNumber(nums1, nums2, k - p1);
	}
	else if (nums1[p1 - 1] > nums2[p2 - 1])
	{
		nums2.assign(nums2.begin() + p2, nums2.end());
		return findKthNumber(nums1, nums2, k - p2);
	}
	else
	{
		return nums1[p1 - 1];
	}
}

double Solution::findMedianSortedArrays2(std::vector<int>& nums1, std::vector<int>& nums2)
{
	int total = nums1.size() + nums2.size();
	if (total % 2 != 0)
	{
		return findKthNumber(nums1, nums2, total / 2 + 1);
	}
	else
	{
		return (findKthNumber(nums1, nums2, total / 2) + findKthNumber(nums1, nums2, total / 2 + 1)) / 2.0;
	}
}
