// LeetCode.cpp: 定义控制台应用程序的入口点。
//
#include "Solution.h"
#include <iostream>

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
	return 0;
}
