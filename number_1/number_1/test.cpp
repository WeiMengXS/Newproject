#include<iostream>
using namespace std;

int NumberOf1Between1AndN_Solution(int n)
{
	if (n == 0)
		return 0;
	int count = 0;
	for (int i = 0; i<=n; i++)
	{
		int tmp = i;

		while (tmp){
			if (tmp % 10 == 1)
			{
				count++;
			}
			tmp /= 10;
		}
	}

	return count;
}int main()
{
	cout << NumberOf1Between1AndN_Solution(13) << endl;
	system("pause");
	return 0;
}