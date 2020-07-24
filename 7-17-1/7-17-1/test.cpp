// write your code here cpp
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		int n = 0;
		int max = 0;
		if (s1.size()<s2.size())
			swap(s1, s2);

		const char* cur = s1.c_str();
		const char* ptr = s2.c_str();
		const char *index = cur;

		if (cur == nullptr || ptr == nullptr) return 0;
		while (*cur&&*ptr)
		{
			while (*cur++!= *ptr)
			if (*cur == *ptr)
			{
				n = 0;
				index = cur;
				while (*cur == *ptr&&*cur&&*ptr)
				{
					++n;
					cur++;
					ptr++;
				}
				cur = index;
				ptr = s2.c_str();
				if (n > max)
				{
					max = n;
				}
			}
		
				cur++;
			
		}

		cout << max << endl;
	}
	return 0;
}