#include<set>
#include<iostream>
#include<vector>
#include<algorithm>
#include<xfunctional>
using namespace std;

	multiset<int, greater<int>> intSet;
	multiset<int, greater<int>>::iterator pSet;
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		if (input.empty())
			return input;
		vector<int> v;

		if (k>input.size())
			return v;
		intSet.clear();
		for (int i = 0; i<input.size(); i++){
			if (intSet.size()<k)
			{
				intSet.insert(input[i]);
			}
			else
			{
				pSet = intSet.begin();
				if (input[i]<(*pSet))
				{
					intSet.erase(pSet);
					intSet.insert(input[i]);
				}
			}

		}
		for (auto e : intSet)
		{
			v.push_back(e);
		}
		return v;
	}
	int main()
	{
		vector<int > vv;
		vv.push_back(4);
		vv.push_back(5);
		vv.push_back(1);
		vv.push_back(6);
		vv.push_back(2);
		vv.push_back(7);
		vv.push_back(3);

		GetLeastNumbers_Solution(vv, 8);

//		cout << endl;
	//	system("pause");
		return 0;
	}