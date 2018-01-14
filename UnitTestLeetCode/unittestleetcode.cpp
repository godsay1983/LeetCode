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

		TEST_METHOD(twoSum2)
		{
			// TODO: 在此输入测试代码
			std::vector<int> nums = { 2, 7, 11, 15 };
			std::vector<int> result = Solution().twoSum2(nums, 9);
			std::vector<int> expected = { 0, 1 };
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

		TEST_METHOD(longestPalindrome)
		{
			// TODO: 在此输入测试代码
			std::string str = "abcda";
			std::string result = Solution().longestPalindrome(str);
			std::string expected = "a";
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(longestPalindrome2)
		{
			// TODO: 在此输入测试代码
			std::string str = "abbaab";
			std::string result = Solution().longestPalindrome2(str);
			std::string expected = "baab";
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(convert)
		{
			// TODO: 在此输入测试代码
			std::string str = "PAYPALISHIRING";
			std::string result = Solution().convert(str, 3);
			std::string expected = "PAHNAPLSIIGYIR";
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(reverse)
		{
			// TODO: 在此输入测试代码
			int result = Solution().reverse(123);
			int expected = 321;
			Assert::AreEqual(expected, result);
		}		
		
		TEST_METHOD(myAtoi)
		{
			// TODO: 在此输入测试代码
			int result = Solution().myAtoi("-234");
			int expected = -234;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(isPalindrome)
		{
			// TODO: 在此输入测试代码
			bool result = Solution().isPalindrome(2332);
			bool expected = true;
			Assert::AreEqual(expected, result);
		}
	};
}
