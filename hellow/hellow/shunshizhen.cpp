#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int M,N;
	cin >>M>>N ;
	vector<char> v;
	v.resize(N*M);
	int count = 0;
	for (int i = 0; i<N*M; i++)
	{
		v[i] = 'A' + count;
		count++;
		if (count > 25)
			count = 0;
	}
	vector<vector<char>> vv;
	vv.resize(M);
	for (int i = 0; i < M; i++)
	{
		vv[i].resize(N);
	}
	int up = 0;
	int down = M - 1;
	int left = 0;
	int right = N - 1;
	int index = 0;

	while (true)
	{
		for (int col = left; col <= right; col++)
			vv[up][col] = v[index++];
		if (++up > down)
			break;

		for (int row = up; row <= down; row++)
			vv[row][right] = v[index++];
		if (--right < left)
			break;

		// 下面行，从右往左打印（行不变，改变列的下标）
		for (int col = right; col >= left; col--)
			vv[down][col] = v[index++];
		if (--down < up)
			break;

		// 左边列，从下往上打印（列不变，改变行的下标）
		for (int row = down; row >= up; row--)
			vv[row][left] = v[index++];
		if (++left > right)
			break;
	}

	for (auto& e : vv)
	{
		for (auto x : e)
		{
			cout << x << ' ';
		}
		cout << endl;
	}
	//system("pause");
	return 0;
}