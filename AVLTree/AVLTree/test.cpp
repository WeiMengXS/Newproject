

#include<iostream>
#include<string>
#include<queue>
using namespace std;
#if 0
int strToint(string& str, int n)
{
	int temp;
	if (!isdigit(str[n]))
	{
		return strToint(str, n - 1);
	}
	if (1 == n)
		return temp = str[0] - '0';

	return temp = strToint(str, n - 1) * 10 + str[n - 1] - 48;

}

int main()
{
	string s;
	cin >> s;

	int temp = 0;
	int  n = s.size();
	cout << (temp = strToint(s, n)) << endl;
	return 0;
}
#endif

template<class T, class V>
struct AVLTreeNode{
	AVLTreeNode<T, V> *_parent;
	AVLTreeNode<T, V> *_left;
	AVLTreeNode<T, V> *_right;

	int _bf;
	pair<T, V>* _kv;
};

template<class T, class V>
class AVLTRee{
public:
	typedef AVLTreeNode<T, V> Node;
	bool insert(const pair<T, V>& kv)
	{

		if (_root == nullptr)
		{
			_root = new Node;

			_root->_kv->first = kv.first;
			_root->_kv->second = kv.second;
			return true;
		}
		Node* cur = _root;

		Node* parent;
		while (cur)
		{
			if (cur->_kv->first>kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv->first<kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
			cur = new Node;
			cur->_kv->first = kv.first;
			cur->_kv->second = kv.second;

			if (cur->_kv->first<parent->_kv->first)
			{
			 parent->_left = cur;
			 cur->_parent = parent;
				return true;
			}
			else
			{
				parent->_right=cur;
				cur->_parent = parent;

				return true;
			}

			return false;
		}

	}
	void show()
	{
		//Node* cur=p;
		if (_root == nullptr)
			return;
		queue<Node*> q;
		q.push(_root);

		while (!q.empty())
		{
			Node* cur = q.front();
			q.pop();
			cout << cur->_kv->first << ':' << cur->_kv->second << endl;
			if (cur->_left)
			{
				q.push(cur->_left);
				// cur=cur->_left;
			}
			if (cur->_right)
			{
				q.push(cur->_right);
			}

		}

	}
private:
	Node *_root = nullptr;

};
int main()
{
	AVLTRee<int, int> s;
	s.insert(make_pair(1,2));
	s.insert(make_pair(2,4));
	s.show();
	system("pause");
		return 0;
}