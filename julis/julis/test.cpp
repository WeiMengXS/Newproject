#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;
void set(string& s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] <= 'z'&&s[i] >= 'a')
		{
			s[i] -= 32;
		}
	}
}
int main()
{
	string str, des;
	getline(cin, str);
	getline(cin, des);
	set(str);
	set(des);
	unordered_set<char> set;
	for (int i = 0; i < str.size(); i++)
	{
		set.insert(str[i]);
	}
	
	for (int j = 0; j < des.size(); j++)
	{
		set.erase(des[j]);
	}
	for (auto e : set)
	{
		cout << e << endl;
	}
	system("pause");
	
		return 0;
}