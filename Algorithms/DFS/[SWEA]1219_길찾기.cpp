#include <iostream>
#include <vector>
#define MAX 100
#define DEST 99
using namespace std;

vector<vector<int>> adjList; // 2차원 배열 인접리스트
vector<int> visit; // 방문처리 1차원 배열, 
				   // -1 : 미방문, 0 : 종단노드까지 따라갔지만 DEST아님
				   // 1 : 종단노드 까지 따라갔을때 DEST --> 길찾음

int dfs(int here) {
	// 현재 노드가 DEST면 길찾아서 1리턴
	if (here == DEST) return 1;

	// 현재 노드에서 인접리스트 따라감 
	for (int i = 0; i < adjList[here].size(); i++) {
		int next = adjList[here][i];
		
		// next노드의 값이 -1아니면 방문한 노드, next노드의 값을 현재노드에 저장하고 리턴 
		if (visit[next] != -1) return visit[here] = visit[next];

		// 다음 노드로 dfs(), 리턴값을 visit에 저장하고 그 값이 1이면 길을 찾은것이기 때문에
		// 1을 리턴하고 종료
		if ((visit[here] = dfs(next)) == 1) return visit[here];
	}
	return visit[here] = 0;
}


int main(void) {
	for (int i = 1; i <= 10; i++) {
		int testccase, edge;
		cin >> testccase >> edge;
		adjList = vector<vector<int>>(MAX, vector<int>());
		visit = vector<int>(MAX, -1);

		// 인접리스트 생성
		for (int j = 0; j < edge; j++) {
			int in1, in2;
			cin >> in1 >> in2;
			adjList[in1].push_back(in2);
		}
		printf("#%d %d\n",testccase,dfs(0));
	}
	
}