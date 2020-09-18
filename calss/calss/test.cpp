#include<vector>
#include<iostream>
using namespace std;
class A
{
public:
	A()
	{
		cout << "A" << endl;
	}
	~A()
	{
		cout << "~A" << endl;
	}
};
class B : public A
{
public:
	B(A & a) :_a(a)
	{
		cout << "B" << endl;
	}
	~B()
	{
		cout << "~B" << endl;
	}

private:
	A _a;
};
int main()
{
	A a;
	B b(a);
	system("pause");
	return 0;
}