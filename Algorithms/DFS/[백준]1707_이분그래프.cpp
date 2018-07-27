#include <iostream>
#include <vector>
#include <string>
#define RED 1
#define BLUE 2
using namespace std;

vector<vector<int>> adjList;
vector<int> Biparti;

bool findAns(int v) {
	for (int i = 0; i < v; i++)
		for (int j = 0; j < adjList[i].size(); j++) {
			int next = adjList[i][j];
			// 현재 노드와 인접한 노드의 색깔은 달라야함
			// 따라서 색이 같으면 이분그래프가 아님
			if (Biparti[i] == Biparti[next]) return false;
		}
	return true;
}

void dfs(int here, int color) {
	// 0이 아니면 RED or BLUE로 값이 나누어진것 그래서 리턴함
	if (Biparti[here]) return;

	// visit
	Biparti[here] = color;
	for (int i = 0; i < adjList[here].size(); i++) {
		int next = adjList[here][i];
		// 인접 노드는 현재 노드와 다른 색을 부여함
		// 현재 노드가 RED면 BLUE를 보내고
		// 현재 노드가 BLUE면 RED를 보냄
		dfs(next, (color == RED ? BLUE : RED));
	}
}

int main(void) {
	int T; cin >> T;

	for (int t = 0; t < T; t++) {
		int v, e;
		cin >> v >> e;

		//벡터 초기화
		adjList = vector<vector<int>>(v + 1);
		Biparti = vector<int>(v + 1, 0);

		// 인접리스트 생성
		for (int i = 0; i < e; i++) {
			int in1, in2; cin >> in1 >> in2;
			adjList[in1].push_back(in2);
			adjList[in2].push_back(in1);
		}

		// 1개의 그래프만 준다고 안함, 방문 안한 그래프 모두 방문하기 위해서 for문 사용
		for (int i = 1; i <= v; i++)
			// 시작은 RED로, 0이면 방문 안항상태이기 때문에 dfs() ㄱㄱ
			if (!Biparti[i]) dfs(i, RED);

		// 답찾기, 
		printf("%s\n", (findAns(v) ? "YES" : "NO"));
	}
}