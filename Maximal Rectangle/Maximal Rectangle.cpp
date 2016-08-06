#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class solution
{
public:
	int maximalRectangle(vector<vector<char>>&matrix)
	{
		if (matrix.empty() || matrix[0].empty())
		{
			return 0;
		}
		int m = matrix.size();
		int n = matrix[0].size();
		vector<vector<int>>height(m, vector<int>(n, 0));
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (matrix[i][j] == '0')
				{
					height[i][j] = 0;
				}
				else
				{
					height[i][j] = (i == 0) ? 1 : height[i - 1][j] + 1;
				}
			}
		}
		int maxArea = 0;
		for (int i = 0; i < m; i++)
		{
			maxArea = max(maxArea, largestRectangleArea(height[i]));
		}
		return maxArea;
	}

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
	vector<char>v1 = { '0','0','0','0' };
	vector<char>v2 = { '1','1','1','1' };
	vector<char>v3 = { '1','1','1','0' };
	vector<char>v4 = { '0','1','0','0' };
	vector<vector<char>>matrix;
	matrix.push_back(v1);
	matrix.push_back(v2);
	matrix.push_back(v3);
	matrix.push_back(v4);
	solution sol;
	int result = sol.maximalRectangle(matrix);
	cout << "max=" << result << endl;
	return 0;
}