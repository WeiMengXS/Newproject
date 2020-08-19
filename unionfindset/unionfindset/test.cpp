#include<iostream>
#include<vector>
using namespace std;
class UnionFindset
{
	UnionFindset(int n)	
	{
		_v.resize(n, -1);
	}
	int Findroot(int n)
	{
		while (_v[n] >= 0)
		{
			n = _v[n];
		}
		return _v[n];
	}
	bool Union(int x1,int x2)
	{
		int root1=Findroot(x1);
		int root2 = Findroot(x2);
		if (root1 == root2){
			return false;
		}
		_v[root1] += _v[root2];
		_v[root2] = root1;
		return true;
	}
	size_t GetCount()
	{
		size_t count=0;
		for (auto& e : _v)
		{
			if (e < 0)
			{
				count++;
			}
		}
		return count;
	}
private:
	vector<int> _v;
};
int main()
{
	return 0;
}