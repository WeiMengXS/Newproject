// write your cod
#include<iostream>
using namespace std;
int feci(int n)
{
	if (n<2)
		return 1;
	else return feci(n - 1) + feci(n - 2);
}
int main()
{
	int n;
	while (cin >> n)
	{
		int d1 = 1; int d2 = 1; int d3 = 2;

		int sum = 0;
		int num = 0;
		if (n == 1)
		{
			cout << 1 << endl;
			continue;
		}
		for (int i = 2; i <= n; i++)
		{
			num = d1 + d2;
			d1 = d2;
			d2 = num;
			sum = num;
		}
		cout << sum << endl;

	}
	system("pause");

	return 0;
}