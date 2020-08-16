#include<iostream>
#include<vector>
using namespace std;
int quick(vector<int >& v, int row, int righ)
{
	int tmp = v[row];
	while (row < righ){
		while (v[righ]>=tmp&&row<righ){
			righ--;
		}
		v[row] = v[righ];
		while (v[row] <=tmp&&row<righ){
			row++;
		}
		v[righ] = v[row];
	}
	v[row] = tmp;
	return row;
}
void Quicksort(vector<int>& v,int row, int righ){
	if (row < righ)
	{


		int index = quick(v, row, righ);
		Quicksort(v, row, index);
		Quicksort(v, index + 1, righ);
	}
}

int main()
{
	vector<int> v;

	v.push_back(4);
	v.push_back(1);
	v.push_back(2);
	v.push_back(0);
	v.push_back(5);
	v.push_back(7);
	v.push_back(3);
	
	Quicksort(v, 0, v.size() - 1);
	for (auto& e : v)
	{
		cout << e << ' ';
	}
	cout << endl;
	system("pause");
}