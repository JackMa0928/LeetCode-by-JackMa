#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class solution
{
public:
	vector<vector<int>> threeSum(vector<int>&num)
	{
		vector<vector<int>> ret;
		if (num.size() < 2)
		{
			return ret;
		}
		sort(num.begin(), num.end());
		for (auto i = 0; i < num.size() - 2; ++i)
		{
			int j = i + 1;
			int k = num.size() - 1;
			while (j < k)
			{
				vector<int>curr;
				if (num[i] + num[j] + num[k] == 0)
				{
					curr.push_back(num[i]);
					curr.push_back(num[j]);
					curr.push_back(num[k]);
					ret.push_back(curr);
					++j;
					--k;
					while (j < k&&num[j - 1] == num[j])
					{
						++j;
					}
					while (j < k&&num[k] == num[k + 1])
					{
						--k;
					}
				}
				else if (num[i] + num[j] + num[k] < 0)
				{
					++j;
				}
				else
				{
					--k;
				}
			}
			while (i < num.size() - 1 && num[i] == num[i + 1])
			{
				++i;
			}
		}
		return ret;
	}
};

int main()
{
	vector<int>vec = { -2,0,1,1,2 };
	solution sol;
	vector<vector<int>>result;
	result = sol.threeSum(vec);
	for (auto i : result)
	{
		for (auto j : i)
		{
			cout << j << ends;
		}
		cout << endl;
	}
}