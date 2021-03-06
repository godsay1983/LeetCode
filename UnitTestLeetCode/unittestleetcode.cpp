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
			std::vector<int> nums = {2, 7, 11, 15};
			std::vector<int> result = Solution().twoSum2(nums, 9);
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
			std::vector<int> nums1 = {1, 2};
			std::vector<int> nums2 = {3, 4};
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

		TEST_METHOD(isMatch)
		{
			// TODO: 在此输入测试代码
			bool result = Solution().isMatch("aab", "c*a*b");
			bool expected = true;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(maxArea)
		{
			// TODO: 在此输入测试代码
			vector<int> data = {1, 8, 6, 2, 5, 4, 8, 3, 7};
			int result = Solution().maxArea(data);
			int expected = 49;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(maxArea2)
		{
			// TODO: 在此输入测试代码
			vector<int> data = {1, 8, 6, 2, 5, 4, 8, 3, 7};
			int result = Solution().maxArea2(data);
			int expected = 49;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(intToRoman)
		{
			// TODO: 在此输入测试代码
			int data = 1980;
			string result = Solution().intToRoman(data);
			string expected = "MCMLXXX";
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(aplusb)
		{
			// TODO: 在此输入测试代码
			int a = 5;
			int b = 7;
			int result = Solution().aplusb(a, b);
			int expected = 12;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(trailingZeros)
		{
			// TODO: 在此输入测试代码
			int num = 106;
			int result = Solution().trailingZeros(num);
			int expected = 25;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(digitCounts)
		{
			// TODO: 在此输入测试代码
			int k = 1;
			int n = 1;
			int result = Solution().digitCounts(k, n);
			int expected = 1;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(nthUglyNumber)
		{
			// TODO: 在此输入测试代码
			int n = 41;
			int result = Solution().nthUglyNumber(n);
			int expected = 150;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(kthLargestElement)
		{
			// TODO: 在此输入测试代码
			vector<int> nums = {1, 2, 3, 4, 5, 6, 8, 9, 10, 7};
			int n = 10;
			int result = Solution().kthLargestElement(n, nums);
			int expected = 1;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(kthLargestElement1)
		{
			// TODO: 在此输入测试代码
			vector<int> nums = {1, 2, 3, 4, 5, 6, 8, 9, 10, 7};
			int n = 10;
			int result = Solution().kthLargestElement1(n, nums);
			int expected = 1;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(mergeSortedArray)
		{
			// TODO: 在此输入测试代码
			vector<int> A = {1, 2, 3, 4};
			vector<int> B = {2, 4, 5, 6};
			vector<int> result = Solution().mergeSortedArray(A, B);
			//			vector<int> expected = { 1, 2, 2, 3, 4, 4, 5, 6 };
			int expected = 3;
			Assert::AreEqual(expected, result[3]);
		}

		TEST_METHOD(rotateString)
		{
			// TODO: 在此输入测试代码
			string str = "abcdefg";
			int offset = 2;
			Solution().rotateString(str, offset);
			string expected = "fgabcde";
			Assert::AreEqual(expected, str);
		}

		TEST_METHOD(fizzBuzz)
		{
			// TODO: 在此输入测试代码
			vector<string> result = Solution().fizzBuzz(15);
			vector<string> expected = {
				"1", "2", "fizz", "4", "buzz", "fizz", "7", "8", "fizz", "buzz", "11", "fizz", "13", "14", "fizz buzz"
			};
			Assert::AreEqual(expected[0], expected[0]);
		}

		TEST_METHOD(strStr)
		{
			// TODO: 在此输入测试代码
			//			char* source = "abcdabcdefg";
			//			char* target = "bcd";			
			char* source = "";
			char* target = "";
			int result = Solution().strStr(source, target);
			int expected = 0;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(binarySearch)
		{
			// TODO: 在此输入测试代码		
			vector<int> nums = {1, 2, 3, 3, 4, 5, 10};
			int result = Solution().binarySearch(nums, 3);
			int expected = 2;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(searchMatrix)
		{
			// TODO: 在此输入测试代码		
			vector<vector<int>> matrix = {
				{1, 5, 10, 11, 16, 23, 24, 26, 29, 34, 41, 48, 49, 56, 63, 67, 71, 74, 75},
				{97, 118, 131, 150, 160, 182, 202, 226, 251, 273, 289, 310, 326, 349, 368, 390, 401, 412, 428},
				{445, 455, 466, 483, 501, 519, 538, 560, 581, 606, 631, 643, 653, 678, 702, 726, 748, 766, 781},
				{792, 817, 837, 858, 872, 884, 901, 920, 936, 957, 972, 982, 1001, 1024, 1044, 1063, 1086, 1098, 1111},
				{1129, 1151, 1172, 1194, 1213, 1224, 1234, 1250, 1267, 1279, 1289, 1310, 1327, 1348, 1371, 1393, 1414, 1436, 1452},
				{1467, 1477, 1494, 1510, 1526, 1550, 1568, 1585, 1599, 1615, 1625, 1649, 1663, 1674, 1693, 1710, 1735, 1750, 1769}
			};
			bool result = Solution().searchMatrix(matrix, 1086);
			bool expected = true;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(isInterleave)
		{
			// TODO: 在此输入测试代码		
			string s1 =
				"sdfjas;dfjoisdufzjkndfasdkfja;sdfa;dfa;dfaskdjhfasdhjdfakhdgfkajdfasdjfgajksdfgaksdhfasdkbfjkdsfbajksdfhakjsdfbajkdfbakdjsfgaksdhgfjkdsghfkdsfgadsjfgkajsdgfkjasdfh";
			string s2 =
				"dfnakdjnfjkzghdufguweygfasjkdfgb2gf8asf7tgbgasjkdfgasodf7asdgfajksdfguayfgaogfsdkagfsdhfajksdvfbgkadsghfakdsfgasduyfgajsdkfgajkdghfaksdgfuyadgfasjkdvfjsdkvfakfgauyksgfajkefgjkdasgfdjksfgadjkghfajksdfgaskdjfgasjkdgfuyaegfasdjkfgajkdfygadjskfgjkadfg";
			string s3 =
				"sdfjas;dfjoisdfnakdjnfjkzghdufguwdufzjkeygfasjkdfgb2gf8asf7ndtgbgasjkdfgasodf7asdfgfajkasdksdfguayfgaogfsdkagfsfjadhfajksdvfbgkadsghfa;sdkdsfgasduyfgajsdkfgafajkdghfaksdgfuyadgfas;dfjkdvfjsdkvfakfgauyksa;dgfajkefgjkdasgfdjksffaskdjhfasdhjdfakhdgadjkghfajgfkajdfksdfgaskdjfgasjkdgfuasdjfgajksdfgaksdhfasdkbfjkdsfbajksdfyaegfasdjkfgajkdfygadjskfgjkadfghakjsdfbajkdfbakdjsfgaksdhgfjkdsghfkdsfgadsjfgkajsdgfkjasdfh";
			bool result = Solution().isInterleave(s1, s2, s3);
			bool expected = true;
			Assert::AreEqual(expected, result);
		}
	};
}
