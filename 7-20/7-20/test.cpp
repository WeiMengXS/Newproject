// write your code here cpp
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		int m = s1.size()+1;
		int n = s2.size()+1;
		vector<vector<int>> dp;
		dp = vector<vector<int> >(m + 1, vector<int>(n + 1, 0));
		for (int i = 1; i < m + 1; ++i){
			for (int j = 1; j < n + 1; ++j){
				if (s1[i - 1] == s2[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
		
		cout << dp[m - 1][n - 1] << endl;
	}
	return 0;
}