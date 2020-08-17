#include<iostream>
using namespace std;
#pragma pack(8)
struct A
{
	char a;
	int b;
	long long c;
	char d;

};
int main()
{
	A a1;
	cout << sizeof(a1) << endl;
	system("pause");
	return 0;
}