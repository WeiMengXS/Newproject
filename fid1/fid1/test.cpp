#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<vector<int>> vv;
	int m = 2 * n -1;

	vv.resize(m);
	for (size_t i = 0; i < m; i++)
	{
		vv[i].resize(n);
	}
	for (int i = 0; i<m; i++)
	{
		for (int j = 0; j<n; j++)
		{
			cin >> vv[i][j];
		}
	}
	int index = 0;
	int j = n-1;
	while (index<n&&j<2*n)
	{
		if (vv[0][index] != vv[j][index])
			break;
		index++;

	}
	for (int k = j; k<m; k++)
	{
		cout << vv[k][index] << ' ';
	}
	system("pause");
}