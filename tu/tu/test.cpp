#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<sstream>

using namespace std;

bool fun(const vector<vector<bool>>& vv){
	int l = vv.size();
	vector<int> in(l, 0);
	queue<int> q;
	for (int i = 0; i < l; i++){
		for (int j = 0; j < l; j++){
			if (vv[j][i] == 1){
				in[i]++;
			}
		}
	}
	for (int i = 0; i < l; i++){
		if (in[i] == 0){
			q.push(i);
		}
	}
	int num = 0;
	while (!q.empty()){
		int p = q.front();
		q.pop();
		num++;
		for (int i = 0; i < l; i++){
			if (vv[p][i] == 1){
				in[i]--;
				if (in[i] == 0){
					q.push(i);
				}
			}
		}
	}
	return num != l;
}

int main(){
	int N;
	cin >> N;


	vector<vector<bool>> vv;
	vv.resize(N);
	
	for (int i = 0; i<N; i++)
	{
		vv[i].resize(N);
	}
	for (int i = 0; i<N; i++)
	{
		for (int j = 0; j<N; j++)
		{
			bool tmp;
			cin >> tmp;
			vv[i][j] = tmp;
		}
	}

	if (fun(vv)){
		printf("Loop\n");
	}
	else{
		printf("No Loop\n");
	}
	return 0;
}

