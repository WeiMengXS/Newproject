#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string s;
	while (n--)
	{
		cin >> s;
		int j = 0;
		for (int i = 0; i<s.size(); i++)
		{
			s[j++] = s[i];   //j��û��
			if (j >= 3 && s[j - 1] == s[j - 2] && s[j - 2] == s[j - 3])
				j--;
			if (j >= 4 && s[j - 1] == s[j - 2] && s[j - 3] == s[j - 4])
				j--;
		}
		s.erase(s.begin() + j, s.end());
		cout << s << endl;
	}
}