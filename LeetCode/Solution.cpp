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

int Solution::kthLargestElement1(int n, vector<int>& nums)
{
	quickSort(0, nums.size() - 1, nums);
	return nums[nums.size() - n];
}

void Solution::quickSort(int left, int right, vector<int>& nums)
{
	int i;
	int j;
	int t;
	int temp;

	if (left > right)
	{
		return;
	}

	temp = nums[left];
	i = left;
	j = right;
	while (i != j)
	{
		while (nums[j] >= temp && i < j)
		{
			j--;
		}
		while (nums[i] <= temp && i < j)
		{
			i++;
		}
		if (i < j)
		{
			t = nums[i];
			nums[i] = nums[j];
			nums[j] = t;
		}
	}

	nums[left] = nums[i];
	nums[i] = temp;

	quickSort(left, i - 1, nums);
	quickSort(i + 1, right, nums);
}

vector<int> Solution::divisorCounts(int l, int r)
{
	int num = l;
	vector<int> divisorCounts;
	divisorCounts.assign(9, 0);
	while (num <= r)
	{
		for (int i = 1; i * i <= num; ++i)
		{
			if (num % i == 0)
			{
				divisorCounts[getFirstNum(i) - 1]++;
				if (num != i * i)
				{
					divisorCounts[getFirstNum((num / i)) - 1]++;
				}
			}
		}
		num++;
	}
	return divisorCounts;
}

int Solution::getFirstNum(int n)
{
	int num = n;
	while (num >= 10)
	{
		num /= 10;
	}
	return num;
}

vector<int> Solution::mergeSortedArray(vector<int>& A, vector<int>& B)
{
	int m = A.size();
	int n = B.size();
	vector<int> C;
	int i = 0;
	int j = 0;

	while (i < m && j < n)
	{
		if (A[i] < B[j])
		{
			C.push_back(A[i++]);
		}
		else
		{
			C.push_back(B[j++]);
		}
	}

	while (i < m)
	{
		C.push_back(A[i++]);
	}

	while (j < n)
	{
		C.push_back(B[j++]);
	}

	return C;
}

string Solution::serialize(TreeNode* root)
{
	string s = "";
	writeTree(s, root);
	return s;
}

void Solution::writeTree(string& s, TreeNode* root)
{
	if (root == NULL)
	{
		s += "# ";
		return;
	}

	s += to_string(root->val) + ' ';
	writeTree(s, root->left);
	writeTree(s, root->right);
}

TreeNode* Solution::deserialize(string& data)
{
	int pos = 0;
	return readTree(data, pos);
}

TreeNode* Solution::readTree(string data, int& pos)
{
	if (data[pos] == '#')
	{
		pos += 2;
		return NULL;
	}

	int nownum = 0;

	while (data[pos] != ' ')
	{
		nownum = nownum * 10 + (data[pos] - '0');
		pos++;
	}

	pos++;
	TreeNode* nowNode = new TreeNode(nownum);

	nowNode->left = readTree(data, pos);
	nowNode->right = readTree(data, pos);

	return nowNode;
}

void Solution::rotateString(string& str, int offset)
{
	if (str != "")
	{
		int length = str.length();
		int time = offset % length;
		for (int i = 0; i < time; ++i)
		{
			char c = str.back();
			str.pop_back();
			str.insert(0, 1, c);
		}
	}
}

vector<string> Solution::fizzBuzz(int n)
{
	vector<string> strs;
	for (int i = 1; i <= n; ++i)
	{
		if (i % 3 == 0 && i % 5 == 0)
		{
			strs.push_back("fizz buzz");
		}
		else if (i % 3 == 0)
		{
			strs.push_back("fizz");
		}
		else if (i % 5 == 0)
		{
			strs.push_back("buzz");
		}
		else
		{
			strs.push_back(to_string(i));
		}
	}
	return strs;
}

vector<int> Solution::searchRange(TreeNode* root, int k1, int k2)
{
	vector<int> values;
	getTreeNodeValue(values, root, k1, k2);
	std::sort(values.begin(), values.end());
	return values;
}

void Solution::getTreeNodeValue(vector<int>& values, TreeNode* root, int k1, int k2)
{
	if (root == NULL)
	{
		return;
	}
	if (k1 <= root->val && k2 >= root->val)
	{
		values.push_back(root->val);
	}
	getTreeNodeValue(values, root->left, k1, k2);
	getTreeNodeValue(values, root->right, k1, k2);
}

int Solution::strStr(const char* source, const char* target)
{
	if (source == NULL || target == NULL)
	{
		return -1;
	}
	int sourceSize = strlen(source);
	int targetSize = strlen(target);
	if (targetSize == 0)
	{
		return 0;
	}
	if (sourceSize < targetSize)
	{
		return -1;
	}
	int i, j;
	for (i = 0; i <= sourceSize - targetSize; ++i)
	{
		for (j = 0; j <= targetSize; ++j)
		{
			if (source[i + j] != target[j])
			{
				break;
			}
			if (j == targetSize - 1)
			{
				return i;
			}
		}
	}
	return -1;
}

int Solution::binarySearch(vector<int>& nums, int target)
{
	int left = 0;
	int right = nums.size() - 1;
	int center = -1;
	int mid = -1;
	while (left <= right)
	{
		center = left + (right - left) / 2;
		if (nums[center] == target)
		{
			mid = center;
		}

		if (nums[center] < target)
		{
			left = center + 1;
		}
		else
		{
			right = center - 1;
		}
	}
	return mid;
}

vector<vector<int>> Solution::permute(vector<int> nums)
{
	vector<vector<int>> v;
	int j = nums.size() - 1;
	if (j == -1)
	{
		v.push_back(nums);
	}
	else
	{
		percore(nums, 0, j, v);
	}
	return v;
}

void Solution::percore(vector<int> nums, int m, int n, vector<vector<int>>& v)
{
	if (m == n)
	{
		v.push_back(nums);
	}
	else
	{
		for (int i = m; i <= n; ++i)
		{
			swap(nums[i], nums[m]);
			percore(nums, m + 1, n, v);
			swap(nums[i], nums[m]);
		}
	}
}

vector<vector<int>> Solution::permuteUnique(vector<int>& nums)
{
	vector<vector<int>> v;
	int j = nums.size() - 1;
	if (j == -1)
	{
		v.push_back(nums);
	}
	else
	{
		perUniquecore(nums, 0, j, v);
	}
	return v;
}

void Solution::perUniquecore(vector<int> nums, int m, int n, vector<vector<int>>& v)
{
	if (m == n)
	{
		auto pos = find(v.begin(), v.end(), nums);
		if (pos == v.end())
		{
			v.push_back(nums);
		}
	}
	else
	{
		for (int i = m; i <= n; ++i)
		{
			swap(nums[i], nums[m]);
			perUniquecore(nums, m + 1, n, v);
			swap(nums[i], nums[m]);
		}
	}
}

vector<vector<int>> Solution::subsets(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	vector<vector<int>> subs;
	vector<int> sub;
	getSubsets(nums, 0, sub, subs);
	return subs;
}

void Solution::getSubsets(vector<int>& nums, int start, vector<int>& sub, vector<vector<int>>& subs)
{
	subs.push_back(sub);
	for (int i = start; i < nums.size(); ++i)
	{
		sub.push_back(nums[i]);
		getSubsets(nums, i + 1, sub, subs);
		sub.pop_back();
	}
}

vector<vector<int>> Solution::subsetsWithDup(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	vector<vector<int>> subs;
	vector<int> sub;
	getSubsetsWithDup(nums, 0, sub, subs);
	return subs;
}

void Solution::getSubsetsWithDup(vector<int>& nums, int start, vector<int>& sub, vector<vector<int>>& subs)
{
	auto pos = find(subs.begin(), subs.end(), sub);
	if (pos == subs.end())
	{
		subs.push_back(sub);
	}
	for (int i = start; i < nums.size(); ++i)
	{
		sub.push_back(nums[i]);
		getSubsetsWithDup(nums, i + 1, sub, subs);
		sub.pop_back();
	}
}

    vector<pair<int, double>> Solution::dicesSum(int n) {
        // Write your code here
        if (n <= 0) {
            return vector<pair<int, double> >();
        }

        long long total = Solution::powOf6(n);
        vector<vector<long long>> dp(n + 1, vector<long long>(6 * n + 1, 0));
        dp[1][1] = 1;
        dp[1][2] = 1;
        dp[1][3] = 1;
        dp[1][4] = 1;
        dp[1][5] = 1;
        dp[1][6] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = i; j <= i * 6; j++) {
                long x1 = 0, x2 = 0, x3 = 0, x4 = 0, x5 = 0, x6 = 0;
                if (j - 1 > 0) {
                    x1 = dp[i - 1][j - 1];
                }
                if (j - 2 > 0) {
                    x2 = dp[i - 1][j - 2];
                }
                if (j - 3 > 0) {
                    x3 = dp[i - 1][j - 3];
                }
                if (j - 4 > 0) {
                    x4 = dp[i - 1][j - 4];
                }
                if (j - 5 > 0) {
                    x5 = dp[i - 1][j - 5];
                }
                if (j - 6 > 0) {
                    x6 = dp[i - 1][j - 6];
                }
                dp[i][j] = x1 + x2 + x3 + x4 + x5 + x6;
            }
        }
        vector<pair<int, double> > result;
        for (int i = n; i <= 6 * n; i++) {
            pair<int, double> p(i, double(dp[n][i]) / total);
            result.push_back(p);
        }
        return result;
    }

    long long Solution::powOf6(int n) {
        long long sum = 1;
        for (int i = 0; i<n; i++) {
            sum *= 6;
        }
        return sum;
    }