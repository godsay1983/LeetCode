// LeetCode.cpp: 定义控制台应用程序的入口点。
//


#include "Solution.h"

int main()
{
	Solution solution;
	std::vector<int> nums;
	nums.push_back(2);
	nums.push_back(7);
	nums.push_back(11);
	nums.push_back(15);
	std::vector<int> result = solution.twoSum(nums, 9);

	ListNode *l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);

	ListNode *l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);

	ListNode *l3 = solution.addTwoNumbers(l1, l2);

    return 0;
}

