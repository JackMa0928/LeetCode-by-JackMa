#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution
{
public:
	int largestRectangleArea(vector<int>&height)
	{
		vector<int>s;
		height.push_back(0);
		int sum = 0;
		int i = 0;
		while (i < height.size())
		{
			if (s.empty() || height[i]>height[s.back()])
			{
				s.push_back(i);
				i++;
			}
			else
			{
				int t = s.back();
				s.pop_back();
				sum = max(sum, height[t] * (s.empty() ? i : i - s.back() - 1));
			}
		}
		return sum;
	}
};

int main()
{
	vector<int>height = { 2,1,5,6,2,3 };
	solution sol;
	int sum = sol.largestRectangleArea(height);
	cout << "sum=" << sum << endl;
}