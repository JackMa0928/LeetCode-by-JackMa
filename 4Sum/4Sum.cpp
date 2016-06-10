#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution
{
public:
	vector<vector<int>>fourSum(vector<int> &nums, int target)
	{
		vector<vector<int>>ret;
		if (nums.size() <= 3)
		{
			return ret;
		}
		sort(nums.begin(), nums.end());
		for (auto i = 0; i < nums.size() - 3; i++)
		{
			if (i > 0 && nums[i] == nums[i - 1])
			{
				continue;
			}
			for (auto j = i + 1; j < nums.size() - 2; j++)
			{
				if (j > i + 1 && nums[j] == nums[j - 1])
				{
					continue;
				}
				auto k = j + 1;
				auto l = nums.size() - 1;
				while (k < l)
				{
					int sum = nums[i] + nums[j] + nums[k] + nums[l];
					if (sum == target)
					{
						vector<int>curr;
						curr.push_back(nums[i]);
						curr.push_back(nums[j]);
						curr.push_back(nums[k]);
						curr.push_back(nums[l]);
						ret.push_back(curr);
						do
						{
							++k;
						} while (k < l&&nums[k] == nums[k - 1]);
						do
						{
							--l;
						} while (k < l&&nums[l] == nums[l + 1]);
					}
					else if (sum < target)
					{
						++k;
					}
					else
					{
						--l;
					}
				}
			}
		}
		return ret;
	}
};

int main()
{
	vector<int>nums = { 1,0,-1,0,-2,2 };
	solution sol;
	vector<vector<int>>ret = sol.fourSum(nums, 0);
	for (auto i : ret)
	{
		for (auto j : i)
		{
			cout << j << ends;
		}
		cout << endl;
	}
	return 0;
}