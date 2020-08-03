#include<iostream>
#include<vector>
using namespace std;
void rogesort(vector<int>& v,int l,int r,vector<int>& t)
{
	if (l >= r)
		return;
	int mid = (l + r)/2;

	int start1 = l, end1 = mid;
	int start2 = mid + 1, end2 = r;
	rogesort(v, start1, end1, t);
	rogesort(v, start2, end2, t);

	int p = l;

	while (start1 <= end1&&start2 <= end2)
	{
		t[p++] = v[start1] < v[start2] ? v[start1++] : v[start2++];
	}
	while (start1 <= end1)
	{
		t[p++] = v[start1++];
	}
	while (start2 <= end2)
	{
		t[p++] = v[start2++];
	}
	p = l;
	start1= l;
	while (p <= r)
	{
		v[start1++] = t[p++];
	}

}
int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(0);
	v.push_back(2);
	v.push_back(4);
	v.push_back(7);
	v.push_back(3);
	v.push_back(6);
	vector<int> tmp;
	tmp.resize(v.size());
	rogesort(v,0,v.size()-1,tmp);
	for (auto& e : v)
	{
		cout << e << ' ';
	}
	cout << endl << endl;
	system("pause");
	return 0;
}
