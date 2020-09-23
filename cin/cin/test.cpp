#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> fun(vector<int>& v) {
	if (v.empty() || v.size() < 3)
		return{};
	vector<vector<int>> res;
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size() - 2; ++i) {
		if (i == 0 || (i > 0 && v[i] != v[i - 1])){
			int left = i + 1, right = v.size() - 1, sum = 0 - v[i];
			while (left < right){
				if (v[left] + v[right] == sum){
					res.push_back({ v[i], v[left], v[right] });
					while (left < right && v[left] == v[left + 1]) left++;
					while (left < right && v[right] == v[right - 1]) right--;
					left++;
					right--;
				}
				else if (v[left] + v[right] < sum)
					left++;
				else
					right--;
			}
		}
	}
	return res;
}

int main()
{
	vector<int> v;
	int a = 0;
	while (cin >> a)
	{
		v.push_back(a);
		char c = cin.get();
		if (c == '\n')
		{
			break;
		}
	}
	vector<vector<int>> ret = fun(v);
	for (size_t i = 0; i < ret.size(); i++)
	{
		for (size_t j = 0; j < ret[i].size(); j++)
		{
			cout << ret[i][j] << ' ';
		}
		cout << endl;
	}
}






