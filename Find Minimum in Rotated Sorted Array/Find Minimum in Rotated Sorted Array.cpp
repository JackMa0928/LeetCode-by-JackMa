#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class solution
{
public:
	int findMin(vector<int>&nums)
	{
		int size = nums.size();
		if (size == 0)
		{
			return 0;
		}
		else if (size == 1)
		{
			return nums[0];
		}
		else if (size == 2)
		{
			return min(nums[0], nums[1]);
		}
		int start = 0;
		int end = nums.size() - 1;
		while (start < end - 1)
		{
			if (nums[start] < nums[end])
			{
				return nums[start];
			}
			int mid = (start + end) / 2;
			if (nums[mid] > nums[start])
			{
				start = mid;
			}
			else if (nums[mid] < nums[start])
			{
				end = mid;
			}
		}
		return min(nums[start], nums[end]);
	}
};

int main()
{
	vector<int> nums = { 4,5,6,7,0,1,2 };
	solution sol;
	int ret = sol.findMin(nums);
	cout << ret << endl;
}