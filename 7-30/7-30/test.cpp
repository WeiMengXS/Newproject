
#include<iostream>
#include<vector>
using namespace std;


	bool Find(int target, vector<vector<int> > array) {
		int l = array[0].size() - 1;
		size_t h = 0;
		while (h<array.size() && l>0)
		{
			if (array[h][l]<target)
			{
				h++;
			}
			else if (array[h][l]>target)
			{
				l--;
			}
			else if (array[h][l] == target)
			{
				return true;
			}
		}
		return false;
	}

int main()
{
	vector<vector<int>> vv{ { 1, 2, 3, 4 }, { 2, 3, 4, 5 }, { 6, 7, 8, 9 }, { 10, 11, 12, 13 } };
	
		Find(7,vv);
	cout  << endl;
	
	return 0;
}