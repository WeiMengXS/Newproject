#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
int main()
{
	string s;
	int n;

	while (cin >> s){


		cin >> n;
		unordered_multimap<char, char> m;
		char a1;
		char a2;

		for (int i = 0; i < n;i++){
			cin >> a1 >> a2;
			m.insert(make_pair(a1, a2));
			//n--;
		}
		for (size_t i = 0; i < s.size(); i++)
		{
			unordered_multimap<char, char>::iterator it = m.begin();

			//
			while (it != m.end())
			{
				if (s[i] == it->first)
				{
					s[i] = it->second;
				}
				it++;
			}
		}
		cout << s << endl;
	}
	system("pause");
}
