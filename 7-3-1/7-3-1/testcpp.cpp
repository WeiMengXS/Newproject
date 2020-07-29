#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

bool ret(long a, long b, long c)
{
	if (a + b>c)    return 1;
	return 0;


}
int main()
{
	vector<int> v;
	string s1, s2, s3;

	double a, b, c;
	while (cin >> s1 >> s2 >> s3)
	{
		long d1 = 0;
		for (auto e : s1)
		{
			d1 *= 10;
			d1 += e - '0';
		}
		long d2 = 0;
		for (auto r : s2)
		{
			d2 *= 10;
			d2 += r - '0';
		}  long d3 = 0;
		for (auto t : s3)
		{
			d3 *= 10;
			d3 += t - '0';
		}

		v.resize(3);
		v[0] = d1;
		v[1] = d2;
		v[2] = d3;
		sort(v.begin(), v.end());
		if (ret(v[0], v[1], v[2])) cout << "Yes" << endl;
		else cout << "No" << endl;

	}
	return 0;
}
