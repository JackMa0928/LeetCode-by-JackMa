#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
	vector<int>getRow(int rowIndex)
	{
		vector<int> vals;
		vals.resize(rowIndex + 1, 1);
		for (int i = 0; i < rowIndex+1; ++i)
		{
			for (int j = i - 1; j >= 1; --j)
			{
				vals[j] = vals[j] + vals[j - 1];
			}
		}
		return vals;
	}
};

int main()
{
	solution sol;
	vector<int>result;
	auto num = 0;
	cin >> num;
	result = sol.getRow(num);
	for (auto v : result)
	{
		cout << v << " ";
	}
	cout << endl;
	return 0;
}