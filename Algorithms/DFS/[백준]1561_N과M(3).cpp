#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> v;

void dfs() {
	if (v.size() == m) {
		for (int i = 0; i < v.size(); i++)
			printf("%d ", v[i]);
		printf("\n");
		return;
	}
	for (int i = 1; i <= n; i++) {
		v.push_back(i);
		dfs();
		v.pop_back();
	}
}

int main(void) {
	cin >> n >> m;
	dfs();
}