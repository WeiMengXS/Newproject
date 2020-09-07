#include <iostream>
#include<vector>
using namespace  std;

struct Listnode{
	int val;
	Listnode* next;
};

void push_back(Listnode* pHead,int key)
{
	Listnode* cur = new Listnode;
	cur->next = nullptr;
	if (pHead == nullptr)
	{
		pHead = cur;
	}
	else{
		Listnode* p = pHead;
		Listnode* index = p;

		while (p != nullptr) {
			index = p;
			p=p->next;
		}
		p = index;
		p->next = cur;
		cur->val=key;
	}

}
void show(Listnode* pHead)
{
	if (pHead == nullptr)
	{
		cout << "List is null" << endl;
	}
	else
	{
		Listnode* p = pHead;
		p = p->next;
		while (p != nullptr)
		{
			cout << p->val << endl;
			p=p->next;

		}
	}
}
void push_front(Listnode* pHead,int key)
{

	Listnode* cur = pHead;
	Listnode* newnode = new Listnode;
	newnode->val = key;
	newnode->next = nullptr;
	if (pHead == nullptr)
	{
		pHead = newnode;
	}
	newnode->next = cur->next;
	cur->next = newnode;

}
template<class T>
void Swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}
int Quick_sort(vector<int>& v, int start, int end)
{
	int left = start;
	int right = v.size() - 1;
	int index = v[start];
	while (left < right)
	{
		while (v[right] >= index&&left<right)right--;
		if (left < right)
		{
			v[left] = v[right];
			left++;
		}


		while (v[left] < index&&left<right)left++;
		if (left < right)
		{
			v[right] = v[left];
			right--;
		}


	}
	v[left] = index;

	return right;

}
void quick_sort(vector<int>& v, int start,int end)
{
	if (start < end){
		int i = Quick_sort(v, start, end);

		quick_sort(v, start, i - 1);
		quick_sort(v, i + 1, end);
	}
	
}

int main() {

	//Listnode* pHead = new Listnode;
	//pHead->next = nullptr;
	//for (int i = 0; i<8; i++)
	//{
	//	int n;
	//	cin >> n;
	//	push_back(pHead,n);
	//}
	//pHead = pHead->next;
	/*for (int i = 0; i<8; i++)
	{
		int n;
		cin >> n;
		push_front(pHead,n);
	}*/
	//Listnode* cur = pHead;
	//Listnode* newList = new Listnode;
	//newList = nullptr;
	//while (cur!=nullptr)
	//push_front(newList,cur->val);

	//show(pHead);
	//show(newList);

	vector<int> v;
	v.push_back(4);
	v.push_back(3);
	v.push_back(6);

	v.push_back(5);

	v.push_back(2);
	v.push_back(1);
	quick_sort(v, 0, v.size() - 1);
	for (auto e : v)
		cout << e << endl;

	system("pause");
	return 0;
}
