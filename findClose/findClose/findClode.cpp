
#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;


/*������������������ʵ����ĿҪ��Ĺ���
��Ȼ����Ҳ���Բ������������ģ����������ȫ�����Լ����뷨�� ^-^
******************************��ʼд����******************************/
vector < int > findNumber(int num) {
	int a = 0, b = 0, i = 0;
	vector<int> res({ -1, -1 });
	int ret = num;
	while (!(ret & 1)){
		++a, ++i;
		ret = ret >> 1;
	}
	int m = 0;
	while (ret & 1 && ret & 2){
		m += (1 << i);
		ret = ret >> 1;
		++i;
	}//��λ1�ļ��ϵĺͣ�
	if (i < 30) res[0] = num + (1 << i);

	if (a) res[0] -= ((1 << a) - 1)*m / (1 << a);

	ret = num, i = 0, m = 0;
	while ((ret & 1)){
		m += (1 << i);
		ret = ret >> 1;
		if (++i >= 31) return res;
	}
	while (!(ret & 1) && !(ret & 2)){
		++b;
		ret = ret >> 1;
		if (++i >= 31) return res;
	}
	res[1] = num - (1 << i);
	if (b) res[1] += m*((1 << b) - 1);
	return res;
}


/******************************����д����******************************/


int main() {
	vector < int > v;

	int _num;
	cin >> _num;
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');



	v = findNumber(_num);
	for (size_t v_i = 0; v_i < v.size(); v_i++) {
		cout << v[v_i] << endl;;
	}

	return 0;

}
