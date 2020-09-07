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
	// ��д��������
	// ֻ����ֵ������������ָ�룬����ִ��ʱ��
	// ��������뽻��ָ�룬����Ҫ����ǰ�����鷳�����
	int tmp = p->val;
	p->val = q->val;
	q->val = tmp;
}

void quick_sort_list(node* head, node* tail) {
	if (head == tail || head == NULL || head == tail->next)return; // �ݹ����
	node* p, *q, *pre;
	p = q = pre = head;
	while (q != tail) {
		q = q->next; // ����һ������ֻ����һ��
		if (q->val > head->val) {
			// ���q��ֵ����base�����p���
			pre = p;
			p = p->next;
			my_swap(p, q);
		}
	}// ִ��while��Ϻ�������
	// base��head,[head->next,p]С��base,[p->next,tail]����base
	my_swap(head, p); // ��base��������λ��
	quick_sort_list(head, pre);
	quick_sort_list(p->next, tail);
}
int main()
{
	node* List = new node;//��ͷ��������
	node* p = List;
	int n = 0;
	cout << "Ҫ���뼸�����֣�" << endl;
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
	cout << "ִ�н���" << endl;
	system("pause");

	return 0;
}
#endif
typedef struct node{
	int val;
	node* next;
}node;
void my_swap(node* p, node* q) {
	// ��д��������
	// ֻ����ֵ������������ָ�룬����ִ��ʱ��
	// ��������뽻��ָ�룬����Ҫ����ǰ�����鷳�����
	int tmp = p->val;
	p->val = q->val;
	q->val = tmp;
}
void quick_sortd_list(node* head, node* tail) {
	if (head == tail || head == NULL || head == tail->next)return; // �ݹ����
	node* p, *q, *pre;
	p = q = pre = head;
	while (q != tail) {
		q = q->next; // ����һ������ֻ����һ��
		if (q->val > head->val) {
			// ���q��ֵ����base�����p���
			pre = p;
			p = p->next;
			my_swap(p, q);
		}
	}// ִ��while��Ϻ�������
	// base��head,[head->next,p]С��base,[p->next,tail]����base
	my_swap(head, p); // ��base��������λ��
	quick_sortd_list(head, pre);
	quick_sortd_list(p->next, tail);
}
void quick_sortx_list(node* head, node* tail) {
	if (head == tail || head == NULL || head == tail->next)return; // �ݹ����
	node* p, *q, *pre;
	p = q = pre = head;
	while (q != tail) {
		q = q->next; // ����һ������ֻ����һ��
		if (q->val < head->val) {
			// ���q��ֵ����base�����p���
			pre = p;
			p = p->next;
			my_swap(p, q);
		}
	}// ִ��while��Ϻ�������
	// base��head,[head->next,p]С��base,[p->next,tail]����base
	my_swap(head, p); // ��base��������λ��
	quick_sortx_list(head, pre);
	quick_sortx_list(p->next, tail);
}
void list_mirror(node* root) {
	// write code here
	int n = 0;
	node* cur = root;
	node* List1 = new node;//��ͷ��������
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

	node* List2 = new node;//��ͷ��������
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
	cout << "ִ�н���" << endl;
	system("pause");

}
int main()
{
	node* l1 = new node;
	node *p = l1;
	//l1->val = 1;
	int n;
	cout << "Ҫ���뼸�����֣�" << endl;
	cin >> n;
	for (short i = 0; i < n; i++) {
		node* q = new node;
		cin >> q->val;
		q->next = NULL;
		p->next = q; p = q;
	}
	list_mirror(l1);

}