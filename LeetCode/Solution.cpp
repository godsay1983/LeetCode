#include "Solution.h"
#include <set>
#include <algorithm>
#include <map>
#include <sstream>

vector<int> Solution::twoSum(vector<int>& nums, int target)
{
	vector<int> result;
	for (int i = 0; i < nums.size() - 1; ++i)
	{
		for (int j = i + 1; j < nums.size(); ++j)
		{
			if (nums[i] + nums[j] == target)
			{
				result.push_back(i);
				result.push_back(j);
				return result;
			}
		}
	}
	return result;
}

vector<int> Solution::twoSum2(vector<int>& nums, int target)
{
	map<int, int> m;
	for (int i = 0; i < nums.size(); ++i)
	{
		int complement = target - nums[i];
		if (m.find(complement) != m.end())
		{
			return {m[complement], i};
		}
		m[nums[i]] = i;
	}
	return {};
}

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode* res = new ListNode(-1);
	ListNode* cur = res;
	int carry = 0;
	while (l1 || l2)
	{
		int n1 = l1 ? l1->val : 0;
		int n2 = l2 ? l2->val : 0;
		int sum = n1 + n2 + carry;
		carry = sum / 10;
		cur->next = new ListNode(sum % 10);
		cur = cur->next;
		if (l1) l1 = l1->next;
		if (l2) l2 = l2->next;
	}
	if (carry) cur->next = new ListNode(1);
	return res->next;
}

int Solution::lengthOfLongestSubstring(string s)
{
	int n = s.length();
	int ans = 0;
	int i = 0;
	int j = 0;
	set<char> ch;
	while (i < n && j < n)
	{
		if (ch.find(s[j]) == ch.end())
		{
			ch.insert(s[j]);
			j++;
			ans = max(ans, j - i);
		}
		else
		{
			ch.erase(s[i]);
			i++;
		}
	}
	return ans;
}

int Solution::lengthOfLongestSubstring2(string s)
{
	int n = s.length();
	int ans = 0;
	map<char, int> m;
	for (int i = 0, j = 0; j < n; ++j)
	{
		if (m.find(s[j]) != m.end())
		{
			i = max(m.at(s[j]), i);
		}
		ans = max(ans, j - i + 1);
		m[s[j]] = j + 1;
	}
	return ans;
}

double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	vector<int> nums;
	nums.reserve(int(nums1.size() + nums2.size()));
	nums.insert(nums.end(), nums1.begin(), nums1.end());
	nums.insert(nums.end(), nums2.begin(), nums2.end());
	sort(nums.begin(), nums.end());
	int n = nums.size();
	if (n % 2 == 0)
	{
		return (nums[n / 2 - 1] + nums[n / 2]) / 2.0;
	}
	else
	{
		return nums[n / 2];
	}
}

double Solution::findKthNumber(vector<int> nums1, vector<int> nums2, int k)
{
	if (nums1.size() > nums2.size())
	{
		return findKthNumber(nums2, nums1, k);
	}
	if (nums1.size() == 0)
	{
		return nums2[k - 1];
	}
	if (k == 1)
	{
		return min(nums1[0], nums2[0]);
	}
	int p1 = min(k / 2, int(nums1.size()));
	int p2 = k - p1;

	if (nums1[p1 - 1] < nums2[p2 - 1])
	{
		nums1.assign(nums1.begin() + p1, nums1.end());
		return findKthNumber(nums1, nums2, k - p1);
	}
	else if (nums1[p1 - 1] > nums2[p2 - 1])
	{
		nums2.assign(nums2.begin() + p2, nums2.end());
		return findKthNumber(nums1, nums2, k - p2);
	}
	else
	{
		return nums1[p1 - 1];
	}
}

double Solution::findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2)
{
	int total = nums1.size() + nums2.size();
	if (total % 2 != 0)
	{
		return findKthNumber(nums1, nums2, total / 2 + 1);
	}
	else
	{
		return (findKthNumber(nums1, nums2, total / 2) + findKthNumber(nums1, nums2, total / 2 + 1)) / 2.0;
	}
}

string Solution::longestPalindrome(string s)
{
	if (s.length() <= 1)
	{
		return s;
	}
	int length = 0;
	string result;
	for (int i = 0; i < s.length() - 1; ++i)
	{
		for (int j = i; j < s.length(); ++j)
		{
			string subs = s.substr(i, j - i + 1);
			string reverseSubs = subs;
			std::reverse(reverseSubs.begin(), reverseSubs.end());
			if (subs == reverseSubs && subs.length() > length)
			{
				length = subs.length();
				result = subs;
			}
		}
	}
	return result;
}

int Solution::expandAroundCenter(string s, int left, int right)
{
	int L = left;
	int R = right;
	while (L >= 0 && R < s.length() && s[L] == s[R])
	{
		L--;
		R++;
	}
	return R - L - 1;
}

string Solution::longestPalindrome2(string s)
{
	int start = 0;
	int end = 0;
	for (int i = 0; i < s.length(); ++i)
	{
		int len1 = expandAroundCenter(s, i, i);
		int len2 = expandAroundCenter(s, i, i + 1);
		int len = max(len1, len2);
		if (len > end - start)
		{
			start = i - (len - 1) / 2;
			end = i + len / 2;
		}
	}
	return s.substr(start, end - start + 1);
}

string Solution::convert(string s, int numRows)
{
	if (numRows <= 1 || s.length() == 0)
	{
		return s;
	}

	string res = "";
	int len = s.length();
	for (int i = 0; i < len && i < numRows; ++i)
	{
		int indx = i;
		res += s[indx];

		for (int k = 1; indx < len; ++k)
		{
			if (i == 0 || i == numRows - 1)
			{
				indx += 2 * numRows - 2;
			}
			else
			{
				if (k & 0x01)
				{
					indx += 2 * (numRows - 1 - i);
				}
				else
				{
					indx += 2 * i;
				}
			}

			if (indx < len)
			{
				res += s[indx];
			}
		}
	}
	return res;
}

int Solution::reverse(int x)
{
	int result = 0;
	while (x != 0)
	{
		int tail = x % 10;
		int newResult = result * 10 + tail;
		if ((newResult - tail) / 10 != result)
		{
			return 0;
		}
		result = newResult;
		x = x / 10;
	}
	return result;
}

int Solution::myAtoi(string str)
{
	if (str.empty())
	{
		return 0;
	}
	int sign = 1;
	int base = 0;
	int i = 0;
	int n = str.length();
	while (i < n && str[i] == ' ')
	{
		++i;
	}
	if (str[i] == '+' || str[i] == '-')
	{
		sign = (str[i++] == '+') ? 1 : -1;
	}
	while (i < n && str[i] >= '0' && str[i] <= '9')
	{
		if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7))
		{
			return (sign == 1) ? INT_MAX : INT_MIN;
		}
		base = 10 * base + (str[i++] - '0');
	}
	return base * sign;
}

bool Solution::isPalindrome(int x)
{
	if (x < 0)
	{
		return false;
	}

	int len = 1;
	while (x / len >= 10)
	{
		len *= 10;
	}

	while (x > 0)
	{
		int left = x / len;
		int right = x % 10;

		if (left != right)
		{
			return false;
		}
		else
		{
			x = (x % len) / 10;
			len /= 100;
		}
	}

	return true;
}

bool Solution::isMatch(string s, string p)
{
	return myMatch(s, s.length() - 1, p, p.length() - 1);
}

bool Solution::myMatch(string s, int i, string p, int j)
{
	if (j == FRONT)
	{
		if (i == FRONT)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	if (p[j] == '*')
	{
		if (i > FRONT && (p[j - 1] == '.' || p[j - 1] == s[i]))
		{
			if (myMatch(s, i - 1, p, j))
			{
				return true;
			}
		}
		return myMatch(s, i, p, j - 2);
	}
	if (p[j] == '.' || p[j] == s[i])
	{
		return myMatch(s, i - 1, p, j - 1);
	}
	return false;
}

int Solution::maxArea(vector<int>& height)
{
	int maxArea = 0;
	for (int i = 0; i < height.size(); ++i)
	{
		for (int j = i + 1; j < height.size(); ++j)
		{
			maxArea = max(maxArea, min(height[i], height[j]) * (j - i));
		}
	}
	return maxArea;
}

int Solution::maxArea2(vector<int>& height)
{
	int left = 0;
	int right = height.size() - 1;

	int maxArea = 0;
	while (left < right)
	{
		maxArea = max(maxArea, min(height[left], height[right]) * (right - left));
		if (height[left] < height[right])
		{
			left++;
		}
		else
		{
			right--;
		}
	}
	return maxArea;
}

string Solution::intToRoman(int num)
{
	vector<string> M = {"", "M", "MM", "MMM"};
	vector<string> C = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
	vector<string> X = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
	vector<string> I = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
	return M[num / 1000] + C[(num % 1000) / 100] + X[(num % 100) / 10] + I[num % 10];
}

int Solution::aplusb(int a, int b)
{
	if (a == 0)
	{
		return b;
	}
	if (b == 0)
	{
		return a;
	}
	int tmpa = a ^ b;
	int tmpb = (a & b) << 1;
	return aplusb(tmpa, tmpb);
}

long long Solution::trailingZeros(long long n)
{
	long long count = 0;
	while (n > 0)
	{
		count += n / 5;
		n /= 5;
	}
	return count;
}

int Solution::digitCounts(int k, int n)
{
	int count = 0;
	if (k == 0)
	{
		count++;
	}
	for (int i = 0; i <= n; ++i)
	{
		int num = i;
		while (num > 0)
		{
			if (num % 10 == k)
			{
				count++;
			}
			num /= 10;
		}
	}
	return count;
}

int Solution::nthUglyNumber(int n)
{
	int* ugly = new int[n];
	ugly[0] = 1;
	int ugly_2 = 0;
	int ugly_3 = 0;
	int ugly_5 = 0;
	for (int i = 1; i < n; ++i)
	{
		int val = min(min(ugly[ugly_2] * 2, ugly[ugly_3] * 3), ugly[ugly_5] * 5);
		if (val == ugly[ugly_2] * 2)
		{
			ugly_2++;
		}
		if (val == ugly[ugly_3] * 3)
		{
			ugly_3++;
		}
		if (val == ugly[ugly_5] * 5)
		{
			ugly_5++;
		}
		ugly[i] = val;
	}
	int result = ugly[n - 1];
	delete[] ugly;
	return result;
}

int Solution::kthLargestElement(int n, vector<int>& nums)
{
	for (int i = 0; i < nums.size() - 1; ++i)
	{
		for (int j = i + 1; j < nums.size(); ++j)
		{
			if (nums[i] < nums[j])
			{
				int temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
			}
		}
	}
	return nums[n - 1];
}
