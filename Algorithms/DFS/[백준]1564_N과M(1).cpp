#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<bool> visit;
vector<int> v;
void dfs() {
	if (v.size() == m) {
		for (int i = 0; i < m; i++)
			printf("%d ", v[i]);
		printf("\n");
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!visit[i]) {
			visit[i] = true; v.push_back(i);
			dfs();
			visit[i] = false; v.pop_back();
		}
	}
}

int main(void) {
	cin >> n >> m;
	visit = vector<bool>(n + 1, false);

	dfs();
}