#pragma once
#include <vector>
#include <string>
#include "NestedInteger.h"
#include "Interval.h"

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
	void writeTree(string& s, TreeNode* root);
	TreeNode* deserialize(string& data);
	TreeNode* readTree(string data, int& pos);
	void rotateString(string& str, int offset);
	vector<string> fizzBuzz(int n);
	vector<int> searchRange(TreeNode* root, int k1, int k2);
	void getTreeNodeValue(vector<int>& values, TreeNode* root, int k1, int k2);
	int strStr(const char *source, const char *target);
	int binarySearch(vector<int> &nums, int target);
	vector<vector<int> > permute(vector<int> nums);
	void percore(vector<int> nums, int m, int n, vector<vector<int>>&v);
	vector<vector<int>> permuteUnique(vector<int> &nums);
	void perUniquecore(vector<int> nums, int m, int n, vector<vector<int>>&v);
	vector<vector<int>> subsets(vector<int>& nums);
	void getSubsets(vector<int>& nums, int start, vector<int>& sub, vector<vector<int>>& subs);
	vector<vector<int>> subsetsWithDup(vector<int> &nums);
	void getSubsetsWithDup(vector<int>& nums, int start, vector<int>& sub, vector<vector<int>>& subs);
	vector<pair<int, double>> dicesSum(int n);
	long long powOf6(int n);
	vector<int> flatten(vector<NestedInteger> &nestedList);
	void doFlat(vector<int> &intList, const vector<NestedInteger> &nestedList);
	bool searchMatrix(vector<vector<int>> &matrix, int target);
	bool isInterleave(string &s1, string &s2, string &s3);
	vector<Interval> insert(vector <Interval> &intervals, Interval newInterval);
};
