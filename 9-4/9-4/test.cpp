#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
#if 0
//void Swap(vector<char > arrs, int left, int right)
//{
//	char tmp = arrs[left];
//	arrs[left] = arrs[right];
//	arrs[right] = tmp;
//}
//void pailie(multiset<string>& set,vector<char>& arrs, int index, int len)
//{
//	if (index == len)
//	{
//		string str;
//		set.insert(str);
//		return;
//	}
//	for (int i = index; i < len; i++)
//	{
//		Swap(arrs, i, index);
//		pailie(set, arrs, index + 1, len);
//		Swap(arrs, i, index);
//	}
//}

int test()
{
	int N, a, b, c, d;
	cin >> N >> a >> b >> c >> d;
	vector<char> arr;
	for (int i = 0; i<a; i++)
	{
		arr[i] = 'a';
	}
	for (int i = a; i<a + b; i++)
	{
		arr[i] = 'b';
	}
	for (int i = a + b; i<a + b + c; i++)
	{
		arr[i] = 'c';
	}
	for (int i = a + b + c; i<a + b + c + d; i++)
	{

		arr[i] = 'd';
	}
	multiset<string> s;
	pailie(s, arr, 0, arr.size());
	set<int > s;
	cout << s.size() << endl;
}

vector<vector<int> > subsets(vector<int> &S) {
	vector<vector<int> > res(1);
	//sort(S.begin(), S.end());
	for (size_t i = 0; i < S.size(); ++i) {
		int size = res.size();
		for (int j = 0; j < size; ++j) {
			res.push_back(res[j]);
			res.back().push_back(S[i]);
		}
	}
	return res;
}
int main()
{
	int n;
	cin >> n;
	//set<int> s;
	vector<int> v;
	for (int i = 0; i<n; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	
	vector<vector<int>> vv;

	vv=subsets(v);
	int MAX = 0;
	for (size_t i = 0; i < vv.size(); i++){
		
		int min = INT_MAX;
		int sum = 0;
		for (size_t j = 0; j < vv[i].size(); j++)
		{
			if (vv[i][j] != 0 && vv[i][j] < min)
			{
				min = vv[i][j];
			}
			//cout << vv[i][j] <<' ';
			sum += vv[i][j];
		}
		//cout << min << "---" << sum << "-----" << sum*min << endl;
		int max = sum*min;
		if (max>MAX)
		{
			MAX = max;
		}
	}
	
	cout << MAX << endl;
	system("pause");
	return 0;
}

#endif
#include <iostream>
#include <algorithm>
using namespace std;

	vector<int> printMatrix(vector<vector<int>>& matrix)
	{
		int row = matrix.size();
		int col = matrix[0].size();
		vector<int> res;
		if (row == 0 || col == 0) return res;
		int left = 0, top = 0, right = col - 1, bottom = row - 1;
		while (left <= right && top <= bottom)
		{
			for (int i = left; i <= right; ++i) res.push_back(matrix[top][i]);
			for (int i = top + 1; i <= bottom; ++i) res.push_back(matrix[i][right]);
			if (top != bottom) for (int i = right - 1; i >= left; --i) res.push_back(matrix[bottom][i]);
			if (left != right) for (int i = bottom - 1; i > top; --i) res.push_back(matrix[i][left]);
			left++, top++, right--, bottom--;
		}
		return res;
	}
	//class Solution {
	//private:
	//	static constexpr int directions[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
	//public:
	//	vector<int> spiralOrder(vector<vector<int>>& matrix) {
	//		if (matrix.size() == 0 || matrix[0].size() == 0) {
	//			return{};
	//		}

	//		int rows = matrix.size(), columns = matrix[0].size();
	//		vector<vector<bool>> visited(rows, vector<bool>(columns));
	//		int total = rows * columns;
	//		vector<int> order(total);

	//		int row = 0, column = 0;
	//		int directionIndex = 0;
	//		for (int i = 0; i < total; i++) {
	//			order[i] = matrix[row][column];
	//			visited[row][column] = true;
	//			int nextRow = row + directions[directionIndex][0], nextColumn = column + directions[directionIndex][1];
	//			if (nextRow < 0 || nextRow >= rows || nextColumn < 0 || nextColumn >= columns || visited[nextRow][nextColumn]) {
	//				directionIndex = (directionIndex + 1) % 4;
	//			}
	//			row += directions[directionIndex][0];
	//			column += directions[directionIndex][1];
	//		}
	//		return order;
	//	}
	//};

int main()
{
	vector<vector<int>> v;
	v.resize(5);
	for (int i = 0; i < 5; i++)
	{
		v.resize(5);
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> v[i][j];
		}
	}
	vector<int> tmp = printMatrix(v);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout<< v[i][j]<<' ';
		}
		cout << endl;
	}
	system("pause");
	return 0;
}