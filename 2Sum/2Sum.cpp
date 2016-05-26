#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class solution
{
public:
	vector<int>twoSum(vector<int>&numbers, int target)
	{
		vector<int>ret;
		if (numbers.size() <= 1)
		{
			return ret;
		}
		unordered_map<int, int>myMap;
		for (int i = 0; i < numbers.size(); ++i)
		{
			myMap[numbers[i]] = i;
		}
		for (int i = 0; i < numbers.size(); ++i)
		{
			int rest_val = target - numbers[i];
			if (myMap.find(rest_val) != myMap.end())
			{
				int index = myMap[rest_val];
				if (index == i)
				{
					continue;
				}
				if (index < i)
				{
					ret.push_back(index + 1);
					ret.push_back(i + 1);
					return ret;
				}
				else
				{
					ret.push_back(i + 1);
					ret.push_back(index + 1);
					return ret;
				}
			}
		}
		return ret;
	}
};

int main()
{
	vector<int>nums = { 2,7,11,15,18 };
	int target;
	cin >> target;
	solution sol;
	vector<int>twoSum = sol.twoSum(nums, target);
	for (auto i : twoSum)
	{
		cout << i << endl;
	}
	return 0;
}