#include<iostream>
#include<typeinfo>
#include<map>
using namespace std;
//int main()
//{
//	map<int, int> m;
//	m.insert(make_pair(1,1));
//	
//	for (auto e : m)
//	{
//	cout << typeid(e).name() << endl;
//	}
//	system("pause");
//}


#if 0
void my_swap(node* p, node* q) {
	// 自写交换函数
	// 只交换值，不更改链表指针，减少执行时间
	// 这里如果想交换指针，就需要增加前驱，麻烦点而已
	int tmp = p->val;
	p->val = q->val;
	q->val = tmp;
}

void quick_sort_list(node* head, node* tail) {
	if (head == tail || head == NULL || head == tail->next)return; // 递归出口
	node* p, *q, *pre;
	p = q = pre = head;
	while (q != tail) {
		q = q->next; // 对于一个链表只遍历一遍
		if (q->val > head->val) {
			// 如果q的值大于base则放在p左边
			pre = p;
			p = p->next;
			my_swap(p, q);
		}
	}// 执行while完毕后的情况：
	// base在head,[head->next,p]小于base,[p->next,tail]大于base
	my_swap(head, p); // 将base放在最终位置
	quick_sort_list(head, pre);
	quick_sort_list(p->next, tail);
}
int main()
{
	node* List = new node;//带头结点的链表
	node* p = List;
	int n = 0;
	cout << "要输入几个数字？" << endl;
	cin >> n;
	for (short i = 0; i < n; i++) {
		node* q = new node;
		cin >> q->val;
		q->next = NULL;
		p->next = q; p = q;
	}
	quick_sort_list(List->next, p);
	p = List->next;
	while (p != NULL) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << "执行结束" << endl;
	system("pause");

	return 0;
}
#endif
typedef struct node{
	int val;
	node* next;
}node;
void my_swap(node* p, node* q) {
	// 自写交换函数
	// 只交换值，不更改链表指针，减少执行时间
	// 这里如果想交换指针，就需要增加前驱，麻烦点而已
	int tmp = p->val;
	p->val = q->val;
	q->val = tmp;
}
void quick_sortd_list(node* head, node* tail) {
	if (head == tail || head == NULL || head == tail->next)return; // 递归出口
	node* p, *q, *pre;
	p = q = pre = head;
	while (q != tail) {
		q = q->next; // 对于一个链表只遍历一遍
		if (q->val > head->val) {
			// 如果q的值大于base则放在p左边
			pre = p;
			p = p->next;
			my_swap(p, q);
		}
	}// 执行while完毕后的情况：
	// base在head,[head->next,p]小于base,[p->next,tail]大于base
	my_swap(head, p); // 将base放在最终位置
	quick_sortd_list(head, pre);
	quick_sortd_list(p->next, tail);
}
void quick_sortx_list(node* head, node* tail) {
	if (head == tail || head == NULL || head == tail->next)return; // 递归出口
	node* p, *q, *pre;
	p = q = pre = head;
	while (q != tail) {
		q = q->next; // 对于一个链表只遍历一遍
		if (q->val < head->val) {
			// 如果q的值大于base则放在p左边
			pre = p;
			p = p->next;
			my_swap(p, q);
		}
	}// 执行while完毕后的情况：
	// base在head,[head->next,p]小于base,[p->next,tail]大于base
	my_swap(head, p); // 将base放在最终位置
	quick_sortx_list(head, pre);
	quick_sortx_list(p->next, tail);
}
void list_mirror(node* root) {
	// write code here
	int n = 0;
	node* cur = root;
	node* List1 = new node;//带头结点的链表
	node* p1 = List1;
	while (cur)
	{
		node* q1 = new node;
		q1->val = cur->val;
		n++;
		cur = cur->next;
		q1->next = NULL;
		p1->next = q1; p1 = q1;
	}
	quick_sortx_list(List1->next, p1);

	cur = root;

	node* List2 = new node;//带头结点的链表
	node* p2 = List2;
	while (cur)
	{
		node* q2 = new node;
		q2->val = cur->val;
		n++;
		cur = cur->next;
		q2->next = NULL;
		p2->next = q2; p2 = q2;
	}
	quick_sortd_list(List2->next, p2);

	node* tmp = List1->next;
	while (tmp->next) tmp=tmp->next;
	tmp->next = List2->next;
	//tmp = List1->next;
	;

	node* p = List1->next->next;
	while (p->next!=NULL) {
		cout << p->val << " ";
		p = p->next;
	}
	cout << "执行结束" << endl;
	system("pause");

}
int main()
{
	node* l1 = new node;
	node *p = l1;
	//l1->val = 1;
	int n;
	cout << "要输入几个数字？" << endl;
	cin >> n;
	for (short i = 0; i < n; i++) {
		node* q = new node;
		cin >> q->val;
		q->next = NULL;
		p->next = q; p = q;
	}
	list_mirror(l1);

}