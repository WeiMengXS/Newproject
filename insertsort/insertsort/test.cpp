#include<iostream>
#include<vector>
using namespace std;
void insertsort(vector<int>& v,int left,int row)
{
	for (int i = 1; i < row; i++)
	{
		int key = v[i];
		int j = i - 1;
		while (j >= 0 && v[j]>key)
		{
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = key;
	}
}
int main()
{
	vector<int> v;
	v.push_back(4);
	v.push_back(3);
	v.push_back(1);
	v.push_back(5);
	v.push_back(9);
	v.push_back(7);
	v.push_back(0);

	insertsort(v, 0, v.size());
	for (auto& e : v)
		cout << e << endl;
	system("pause");
	return 0;
}