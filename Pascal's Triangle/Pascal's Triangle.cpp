#include <iostream>
#include <vector>
using namespace std;


class solution
{
public:
	vector<vector<int>>generate(int numRows)
	{
		vector<vector<int>>vals;
		vals.resize(numRows);

		for (int i = 0; i < numRows; i++)
		{
			vals[i].resize(i + 1);
			vals[i][0] = 1;
			vals[i][vals[i].size() - 1] = 1;
			for (int j = 1; j < vals[i].size() - 1; j++)
			{
				vals[i][j] = vals[i - 1][j - 1] + vals[i - 1][j];
			}
		}
		return vals;
	}
};

int main()
{
	solution sol;
	int i = 0;
	cin >> i;
	vector<vector<int>>val = sol.generate(i);
	for (int a = 0; a < val.size(); a++)
	{
		for (int b = 0; b < val[a].size(); b++)
		{
			cout << val[a][b] << ends;
		}
		cout << endl;
	}
	return 0;
}