#include <iostream>
using namespace std;

class solution
{
public:
	int removeDuplicates(int *a, int n)
	{
		if (n == 0)
		{
			return 0;
		}
		int j = 0;
		int num = 0;
		for (int i = 1; i < n; i++)
		{
			if (a[j] == a[i])
			{
				num++;
				if (num < 2)
				{
					a[++j] = a[i];
				}
			}
			else
			{
				a[++j] = a[i];
				num = 0;
			}
		}
		return j + 1;
	}
};


int main()
{
	int a[20] = { 1,2,2,3,3,3,4,4,4,4,5,5,5,5,5,6,6,6,6,6 };
	solution num;
	int result = num.removeDuplicates(a, 20);
	cout << result << endl;
	for (int i = 0; i < result; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}