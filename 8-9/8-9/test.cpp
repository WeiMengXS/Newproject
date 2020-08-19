
#include<iostream>
using namespace std;
int PrimaryCal(int num)
{
	int count = 0;
	for (int i = 2; i<= num; i++)
	{
		while (num%i == 0)
		{
			//cout << i << " ";
			if (num == 0)
			{
				return count;
			}
			count+=(num/=i);
			//num -= i;
		}
	}
	//if (num != 1)
	//{
		//cout << num;
	//}
	return count;
}

int main()
{
	int i=PrimaryCal(9);
	cout << i << endl;
	system("pause");
	return 0;
}