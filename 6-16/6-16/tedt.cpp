
#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main()
{

	string s;
	while (getline(cin, s))
	{
		//string ret = GetRet(s);

		vector<string> v;
		int i = 0;
		while (i < s.size())
		{
			int begin = i;
			if (s[i] == '\"')//сп"
			{
				i++;
				while (i < s.size() && s[i] != '\"')
				{
					i++;
				}
				//s[begin]=='\"'
				string tmp = s.substr(begin, i - begin + 1);
				v.push_back(tmp);
				i++;
			}

			begin = i;
			while (i < s.size() && s[i] != ' ')
			{
				i++;
			}
			//s[i]==' '
			if (i < s.size())
			{
				string tmp = s.substr(begin, i - begin);
				v.push_back(tmp);
				i++;
			}
			else
			{
				string tmp = s.substr(begin);
				v.push_back(tmp);
			}
		}


		cout << v.size() << endl;
		for (auto e : v)
		{
			cout << e << endl;
		}

	}


	return 0;

}