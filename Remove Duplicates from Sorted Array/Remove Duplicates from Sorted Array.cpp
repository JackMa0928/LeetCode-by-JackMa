#include <iostream>
using namespace std;

class Solution
{
public:
	int removeDuplicates(int *a, int n)
	{
		if (n == 0)
		{
			return 0;
		}
		int j = 0;
		for (int i = 1; i < n; i++)
		{
			if (a[j] != a[i])
			{
				a[++j] = a[i];
			}
		}
		return j + 1;
	}
};

int main()
{
	int a[8] = { 1,2,2,3,3,3,4,5 };
	Solution sol;
	int result = sol.removeDuplicates(a, 8);
	for (int i = 0; i < result; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	cout << result << endl;
	return 0;
}