#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<int>> adjList;
vector<bool> visit;

int dfs(int here, int cnt) {
	visit[here] = true;

	// 현재 노드에 연결되어 있는 노드를 차례로 탐색
	// 탐색할때 cnt + 1씩해줌
	for (int i = 0; i < adjList[here].size(); i++) {
		int next = adjList[here][i];
		if (!visit[next]) cnt = dfs(next, cnt + 1);
	}
	return cnt;
}

int main(void) {
	cin >> n >> m;
	
	// 벡터 초기화
	adjList = vector<vector<int>>(n + 1);
	visit = vector<bool>(n + 1, 0);

	// 인접리스트 생성
	for (int i = 0; i < m; i++) {
		int in1, in2; cin >> in1 >> in2;
		adjList[in1].push_back(in2);
		adjList[in2].push_back(in1);
	}

	// dfs() 리턴값이 답
	printf("%d\n", dfs(1, 0));
}