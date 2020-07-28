#include<iostream>
#include<vector>
#include<string>
using namespace std;
int f3()
{
	try{
		vector<int > v = { 1, 2, 3, 4, 5 };
		for (size_t i = 0; i <= v.size(); i++)
		{
			cout << v.at(i) << endl;
		}
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}
namespace cdr
{

	int div(int n, int m)
	{
		if (m == 0)
			throw string("chuyichang"); 
		return n / m;
	}
}
int main()
{
	try{
		int n, m;
		cin >> n >> m;
		cout << cdr::div(n, m) << endl;
	}
	catch (int err)
	{
		cout << err << endl;
	}
	catch (const string& s2)
	{
		cout << s2 << endl;
	}
	system("pause");
}