#include<iostream>
#include<List>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
	if (pHead1 == NULL || pHead2 == NULL)
		return nullptr;
	int k1, k2;
	while (pHead1)
	{
		k1++;
		pHead1 = pHead1->next;
	}
	while (pHead2)
	{
		k2++;
		pHead2 = pHead2->next;
	}
	int n = k1 - k2;
	ListNode* _short = pHead2;
	ListNode* _long = pHead1;
	if (k2>k1){
		n = k2 - k1;
		_long = pHead2;
		_short = pHead1;
	}
	while (_long&&n){
		_long = _long->next;
		n--;
	}
	while (_long&&_short&&
		_long != _short)
	{
		_long = _long->next;
		_short = _short->next;
	}
	return _long;
}

int main()
{
	//


	return 0;
}



	