#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


int main()
{
	vector<int> v;
	map<int, int> m;
	int n;
	int k;
	while (cin >> n)
	{
		v.resize(n);
		for (int i = 0; i<n; i++)
		{
			cin >> v[i];
		}
		for (auto& e : v)
		{
			m[e]++;
		}
		scanf_s("%d",&k);
		//cout<<m.at(k);
		/*vector<int> v2;
		for (auto x : m)
		{
			v2.push_back(x.first);
		}
*/
		cout << m.at(k-1) << endl;

	}
	
	return 0;
}