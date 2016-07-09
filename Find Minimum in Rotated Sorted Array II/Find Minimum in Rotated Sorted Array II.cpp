#include <iostream>
#include <vector>
#include <algorithm>
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
		int end = size - 1;
		while (start < end - 1)
		{
			if (nums[start] < nums[end])
			{
				return nums[start];
			}
			int mid = (start + end) / 2;
			if (nums[start] < nums[mid])
			{
				start = mid;
			}
			else if (nums[start]>nums[mid])
			{
				end = mid;
			}
			else
			{
				start++;
			}
		}
		return min(nums[start], nums[end]);
	}
};

int main()
{
	vector<int>nums = { 3,3,3,0,1,2,2 };
	solution sol;
	int ret = sol.findMin(nums);
	cout << ret << endl;
}