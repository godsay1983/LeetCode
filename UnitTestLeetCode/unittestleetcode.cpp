#include "stdafx.h"
#include "CppUnitTest.h"
#include "../LeetCode/Solution.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLeetCode
{
	TEST_CLASS(UnitTestLeetCode)
	{
	public:
		TEST_METHOD(twoSum)
		{
			// TODO: 在此输入测试代码
			std::vector<int> nums = {2, 7, 11, 15};
			std::vector<int> result = Solution().twoSum(nums, 9);
			std::vector<int> expected = {0, 1};
			Assert::IsTrue(expected == result);
		}

		TEST_METHOD(addTwoNumbers)
		{
			// TODO: 在此输入测试代码
			ListNode* l1 = new ListNode(2);
			l1->next = new ListNode(4);
			l1->next->next = new ListNode(3);

			ListNode* l2 = new ListNode(5);
			l2->next = new ListNode(6);
			l2->next->next = new ListNode(4);

			ListNode* result = Solution().addTwoNumbers(l1, l2);

			ListNode* expected = new ListNode(7);
			expected->next = new ListNode(0);
			expected->next->next = new ListNode(8);
			Assert::AreEqual(expected->val, result->val);
			Assert::AreEqual(expected->next->val, result->next->val);
			Assert::AreEqual(expected->next->next->val, result->next->next->val);
		}

		TEST_METHOD(lengthOfLongestSubstring)
		{
			// TODO: 在此输入测试代码
			int result = Solution().lengthOfLongestSubstring("dvdf");
			int expected = 3;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(lengthOfLongestSubstring2)
		{
			// TODO: 在此输入测试代码
			int result = Solution().lengthOfLongestSubstring2("abcabcbb");
			int expected = 3;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(findMedianSortedArrays)
		{
			// TODO: 在此输入测试代码
			std::vector<int> nums1 = {1, 2};
			std::vector<int> nums2 = {3, 4};
			double result = Solution().findMedianSortedArrays(nums1, nums2);
			double expected = 2.5;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(findMedianSortedArrays2)
		{
			// TODO: 在此输入测试代码
			std::vector<int> nums1 = { 1, 2 };
			std::vector<int> nums2 = { 3, 4 };
			double result = Solution().findMedianSortedArrays2(nums1, nums2);
			double expected = 2.5;
			Assert::AreEqual(expected, result);
		}
	};
}
