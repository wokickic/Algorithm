#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k, m;
vector<vector<int>> station, tube;
vector<int> s_visit, t_visit;

int bfs(int here) {
	// 현재 역을 큐에 넣고 방문역의 개수 1로 초기화
	queue<int> q;
	q.push(here);
	s_visit[here] = 1;

	while (!q.empty()) {
		here = q.front();
		q.pop();
		// 현재 역이 n번째 역이면 
		// s_visit[here]에 저장된 n번째 까지의 방문역 개수 리턴
		if (here == n) return s_visit[here];

		for (int i = 0; i < station[here].size(); i++) {
			// 현재 역이 포함된 튜브번호를 ttube에 저장
			int ttube = station[here][i];
			if (!t_visit[ttube]) { 
				// 아직 방문 안한 튜브
				t_visit[ttube] = true;
				
				// 튜브에포함된 역들의 방문횟수 구하고 큐에 삽입
				for (int j = 0; j < tube[ttube].size(); j++) {
					int nextStation = tube[ttube][j];
					if (!s_visit[nextStation]) { 
						// 다음역 방문 안했으면 visit 1증가시키고 큐에 넣음
						s_visit[nextStation] = s_visit[here] + 1;
						q.push(nextStation);
					}
				}
			}
		}
	}
	// while문 끝날때까지 리턴 못하면 
	// 이동할수 없는경우, -1 리턴
	return -1;
}

int main(void) {
	cin >> n >> k >> m;

	// 벡터 초기화
	station = vector<vector<int>>(n + 1);
	tube = vector<vector<int>>(m + 1);
	s_visit = vector<int>(n + 1, 0);
	t_visit = vector<int>(m + 1, false);

	for (int i = 1; i <= m; i++) { // i = tube 번호
		for (int j = 0; j < k; j++) {
			int in; cin >> in;
			station[in].push_back(i); // in번 노드에 연결된 튜브 저장
			tube[i].push_back(in);  // tube에 in번 노드 저장
		}
	}
	// 1번 역부터 bfs() 시작
	printf("%d\n", bfs(1));
}

