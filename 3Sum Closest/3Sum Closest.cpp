#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

class solution
{
public:
	int threeSumClosest(vector<int>&nums, int target)
	{
		if (nums.size() <= 2)
		{
			return -1;
		}
		int ret = 0;
		int distance = INT_MAX;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 2; ++i)
		{
			int j = i + 1;
			int k = nums.size() - 1;
			while (j < k)
			{
				int tmp_val = nums[i] + nums[j] + nums[k];
				int tmp_distance;
				if (tmp_val < target)
				{
					tmp_distance = target - tmp_val;
					if (tmp_distance < distance)
					{
						distance = tmp_distance;
						ret = nums[i] + nums[j] + nums[k];
					}
					++j;
				}
				else if (tmp_val>target)
				{
					tmp_distance = tmp_val - target;
					if (tmp_distance < distance)
					{
						distance = tmp_distance;
						ret = nums[i] + nums[j] + nums[k];
					}
					--k;
				}
				else
				{
					ret = nums[i] + nums[j] + nums[k];
					return ret;
				}
			}
		}
		return ret;
	}
};

int main()
{
	vector<int>nums = { -1,2,1,-4 };
	solution sol;
	int result = sol.threeSumClosest(nums, 1);
	cout << result << endl;
	return 0;
}