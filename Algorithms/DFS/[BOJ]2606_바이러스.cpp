#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> adjList;
vector<bool> visit;

int dfs(int here, int cnt) {
	visit[here] = true;

	// ���� ��忡 ����Ǿ� �ִ� ��带 ���ʷ� Ž��
	// Ž���Ҷ� cnt + 1������
	for (int i = 0; i < adjList[here].size(); i++) {
		int next = adjList[here][i];
		if (!visit[next]) cnt = dfs(next, cnt + 1);
	}
	return cnt;
}

int main(void) {
	cin >> n >> m;
	
	// ���� �ʱ�ȭ
	adjList = vector<vector<int>>(n + 1);
	visit = vector<bool>(n + 1, 0);

	// ��������Ʈ ����
	for (int i = 0; i < m; i++) {
		int in1, in2; cin >> in1 >> in2;
		adjList[in1].push_back(in2);
		adjList[in2].push_back(in1);
	}

	// dfs() ���ϰ��� ��
	printf("%d\n", dfs(1, 0));
}