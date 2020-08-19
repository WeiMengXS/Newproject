#include<iostream>
#include<vector>
using namespace std;
void easysort(vector<int>& v, int left, int righ)
{
	int min=9999999;
	int mindex;
	int tmp;
	for (int i = 0; i < righ; i++)
	{
		min =i;
		for (int j = i+1; j < righ+1; j++)
		{
			
			if (v[j] < v[min])
			{
				min=j;
			}
		}
		tmp = v[i];
		v[i] = v[min];
		v[min] = tmp;

	}
}
int main()
{
	vector<int> v;
	v.push_back(3);
	v.push_back(2);
	v.push_back(5);
	v.push_back(1);
	v.push_back(4);
	v.push_back(9);
	v.push_back(0);
	v.push_back(7);

	easysort(v,0,v.size()-1);
	for (auto& e : v)
		cout << e << endl;
	system("pause");
			return 0;
}