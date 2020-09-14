#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <limits>
#include<stack>
using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/
int max(int a, int b)
{
	return a > b ? a : b;
}
int longestValidParenthe(string s) {

	int Max = 0, start = 0;
	if (s.empty())
		return 0;
	stack<char> ret;
	for (int i = 0; i < s.length(); i++)
	{
		if ('(' == s[i])
		{
			ret.push(i);
			continue;
		}
		else{
			if (ret.empty()){
				start = i + 1;
				continue;
			}
			else{
				ret.pop();

				if (ret.empty()){
					Max = max(Max, i - start + 1);
				}
				else{
					Max = max(Max, i - ret.top());
				}
			}
		}

	}
	return Max;
}
/******************************结束写代码******************************/


int main() {
	int res;

	string _s;
	getline(cin, _s);

	res = longestValidParenthe(_s);
	cout << res << endl;

	return 0;

}
