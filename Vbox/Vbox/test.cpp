#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
	bool setmap[20001];
	int n;
	int a[31];
	int v;

	cin >> v >> n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	memset(setmap, 0, sizeof(setmap));
	setmap[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = v; j >= 0; j--) {
			if (setmap[j] == 1 && j + a[i] <= v) {
				setmap[j + a[i]] = 1;
			}
		}
	}
	int tmp = 0;
	for (int i = v; i >= 0; i--) {
		if (setmap[i] == 1) {
			tmp = i;
			break;
		}
	}
	cout << v - tmp << endl;
	return 0;
}

