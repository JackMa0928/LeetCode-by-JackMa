#include <iostream>
using namespace std;

int solution(int *a, int n, int elem)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] == elem)
		{
			continue;
		}
		a[j] = a[i];
		j++;
	}
	return j;
}

int main()
{
	int a[10] = { 1,2,2,3,5,3,2,7,9,2 };
	int s = solution(a, 10, 2);
	for (int i = 0; i < s; i++)
	{
		cout << a[i] << endl;
	}
	cout << s << endl;
}