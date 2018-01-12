#pragma once
#include <vector>
#include <string>

using namespace std;

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
	vector<int> twoSum(vector<int>& nums, int target);
	vector<int> twoSum2(vector<int>& nums, int target);
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
	int lengthOfLongestSubstring(string s);
	int lengthOfLongestSubstring2(string s);
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
	double findKthNumber(vector<int> nums1, vector<int> nums2, int k);
	double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2);
	string longestPalindrome(string s);
	int expandAroundCenter(string s, int left, int right);
	string longestPalindrome2(string s);
	string convert(string s, int numRows);
	int reverse(int x);
	int myAtoi(string str);
};
