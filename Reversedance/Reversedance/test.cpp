#include<iostream>
#include<string>
using namespace std;
void Reverse(string& s, int l, int r){
	while (l < r)
	{
		char tmp = s[l];
		s[l] = s[r];
		s[r] = tmp;

		l++;
		r--;
	}
}
int main()
{
	string s;
	getline(cin, s);
	int len = s.size();
	int i = 0;
	int j = i;
	while (i < len)
	{//i am student
		while (i < len&&!isspace(s[i]))i++;
		Reverse(s, j, i-1);
		while (i < len&&isspace(s[i]))i++;
		j = i;

	}
	Reverse(s, j, i - 1);
	Reverse(s, 0, i-1);
	cout << s << endl;
	system("pause");
}