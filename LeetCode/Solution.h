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
	std::vector<int> twoSum2(std::vector<int>& nums, int target);
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
	int lengthOfLongestSubstring(std::string s);
	int lengthOfLongestSubstring2(std::string s);
	double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2);
	double findKthNumber(std::vector<int> nums1, std::vector<int> nums2, int k);
	double findMedianSortedArrays2(std::vector<int>& nums1, std::vector<int>& nums2);
};
