// LeetCode.cpp: 定义控制台应用程序的入口点。
//
#include "Solution.h"
#include <iostream>
#include "LFUCache.h"

int main()
{
	Solution solution;
	vector<int> nums;
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(11);
	nums.push_back(15);
	vector<int> result = solution.twoSum(nums, 9);

	ListNode* l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);

	ListNode* l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);

	ListNode* l3 = solution.addTwoNumbers(l1, l2);

	vector<int> divisorCounts = solution.divisorCounts(64, 8306);
	for (int i = 0; i < divisorCounts.size(); ++i)
	{
		std::cout << divisorCounts[i] << std::endl;
	}

	TreeNode* node = new TreeNode(3);
	node->left = new TreeNode(9);
	node->right = new TreeNode(20);
	node->right->left = new TreeNode(15);
	node->right->right = new TreeNode(7);

	string serial = solution.serialize(node);
	std::cout << serial << endl;
	TreeNode* node1 = solution.deserialize(serial);

	vector<int> values = solution.searchRange(node, 10, 22);

	vector<int> nums1 = {1, 2, 3, 3, 4, 5, 10};
	int target = solution.binarySearch(nums1, 3);

	vector<int> nums2 = {1, 2, 3};
	vector<vector<int>> v = solution.permute(nums2);

	auto resultDicesSum = solution.dicesSum(3);

	LFUCache lfuCache(3);
	lfuCache.set(1, 10);
	lfuCache.set(2, 20);
	lfuCache.set(3, 30);
	cout << lfuCache.get(1) << std::endl;
	lfuCache.set(4, 40);
	cout << lfuCache.get(4) << std::endl;
	cout << lfuCache.get(3) << std::endl;
	cout << lfuCache.get(2) << std::endl;
	cout << lfuCache.get(1) << std::endl;
	lfuCache.set(5, 50);
	cout << lfuCache.get(1) << std::endl;
	cout << lfuCache.get(2) << std::endl;
	cout << lfuCache.get(3) << std::endl;
	cout << lfuCache.get(4) << std::endl;
	cout << lfuCache.get(5) << std::endl;
	return 0;
}
