#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
	{
		vector<int>vec;
		int i = 0;
		int j = 0;
		while (i < m&&j < n)
		{
			if (nums1[i] <= nums2[j])
			{
				vec.push_back(nums1[i]);
				i++;
			}
			else
			{
				vec.push_back(nums2[j]);
				j++;
			}
		}
		while (i < m)
		{
			vec.push_back(nums1[i]);
			i++;
		}
		while (j < n)
		{
			vec.push_back(nums2[j]);
			j++;
		}
		nums1 = vec;
	}
};

int main()
{
	vector<int>nums1 = { 3,5,6,8,9,11,15,17,18,20 };
	vector<int>nums2 = { 1,4,7,12,16,18,22,25 };
	Solution sol;
	sol.merge(nums1, 10, nums2, 8);
	for (auto i : nums1)
	{
		cout << i << " ";
	}
}
