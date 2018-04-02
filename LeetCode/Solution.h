﻿#pragma once
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

//Definition of TreeNode:
class TreeNode
{
public:
	int val;
	TreeNode *left, *right;

	TreeNode(int val)
	{
		this->val = val;
		this->left = this->right = NULL;
	}
};

class Solution
{
	static const int FRONT = -1;
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
	bool isPalindrome(int x);
	bool isMatch(string s, string p);
	bool myMatch(string s, int i, string p, int j);
	int maxArea(vector<int>& height);
	int maxArea2(vector<int>& height);
	string intToRoman(int num);
	int aplusb(int a, int b);
	long long trailingZeros(long long n);
	int digitCounts(int k, int n);
	int nthUglyNumber(int n);
	int kthLargestElement(int n, vector<int>& nums);
	int kthLargestElement1(int n, vector<int>& nums);
	void quickSort(int i, int j, vector<int>& nums);
	vector<int> divisorCounts(int l, int r);
	int getFirstNum(int n);
	vector<int> mergeSortedArray(vector<int>& A, vector<int>& B);
	string serialize(TreeNode* root);
	void writeTree(string &s, TreeNode* root);
	TreeNode* deserialize(string &data);
	TreeNode* readTree(string data, int& pos);
};
