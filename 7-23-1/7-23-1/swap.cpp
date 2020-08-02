#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
void Reverse(string& s, int left, int right)
{
	while (left<right)
	{
		swap(s[left], s[right]);
		left++;
		right--;
	}
}
bool bl(char a)
{
	if ((a>'a'&&a<'z') || (a>'A'&&a < 'Z')) return true;
	return false;
}
int main()
{
	string s;
	while (getline(cin, s))
	{
		if (s.size() == 0) cout << 0 << endl;

		for (int i = 0; i < s.size(); i++)
			// 先对分割符进行处理. 如果发现分割符, 就统一处理成空格. if (!isalnum(str[i]))
		if (!isalnum(s[i]))
			s[i] = ' ';
		reverse(s.begin(), s.end());
		int left = 0;
		int right = 0;
		while (right<s.size())
		{
			if (bl(s[right]))
			{
				Reverse(s, left, right - 1);
				left = right + 1;
			}
			else if (right == s.size() - 1)
			{
				Reverse(s, left, right);
			}
			right++;
			//left++;
		}


		cout << s << endl;
	}
	return 0;
}