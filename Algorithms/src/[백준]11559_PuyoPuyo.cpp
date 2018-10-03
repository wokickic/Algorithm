#include <iostream>
#include <queue>
#define ROW 12
#define COL 6
#define DOT '.'
using namespace std;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };
char map[ROW][COL];

queue<pair<int, int>> bfs(int y, int x, char puyo, bool (*visit)[COL]) {
	queue<pair<int, int>> q, ret;
	q.push(make_pair(y, x)); // bfs 탐색용
	ret.push(make_pair(y, x));// return 용
	visit[y][x] = true;

	while (!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < ROW && nx < COL) {
				if (map[ny][nx] == puyo && !visit[ny][nx]) {
					q.push(make_pair(ny, nx));
					ret.push(make_pair(ny, nx));
					visit[ny][nx] = true;
				}
			}
		}
	}
	// 제거가능한 뿌요가 저장되어있는 큐를 리턴
	return ret;
}

int go(int cnt) {
	while (1) {
		// 반복마다 방문처리해주는 배열을 만든다.
		bool visit[ROW][COL] = { 0, };

		// 큐를 저장하는 큐 -> 제거 가능한 뿌요를 저장하는 큐
		queue<queue<pair<int, int>>> qq;
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				// 아직 방문안하고 문자이면 bfs탐
				if (map[i][j] == DOT || visit[i][j]) continue;
				// 제거 가능한 큐를 리턴 받음
				queue<pair<int, int>> ret = bfs(i, j, map[i][j], visit);
				// 리턴받은 큐의 크기가 4이상이면 제거 가능, 큐를 큐에 저장
				if (ret.size() >= 4) qq.push(ret);
			}
		}
		// 큐가 비어있으면 더이상 제거할수 있는 뿌요가 없기때문에 cnt리턴
		if (qq.empty()) return cnt;
		// 그렇지 않으면, 제거가능한 뿌요가 존재하기 때문에 cnt증가시켜줌
		cnt++;
		while (!qq.empty()) {
			// 삭제하는 작업
			// 큐에서 큐를 뽑아온다.
			queue<pair<int, int>> q = qq.front();
			qq.pop();
			while (!q.empty()) {
				//뿌요를 '.'으로 바꿔줌
				int y = q.front().first; 
				int x = q.front().second;
				map[y][x] = DOT; q.pop();
			}
		}
		// 아래로 땡기기
		//(11, 5) ~ (11,0), (10,5) ~ (10,0) ... 순서로 돌면서 빈공간 채우기
		for (int i = COL - 1; i >= 0; i--) {
			queue<pair<int, int>> q;
			for (int j = ROW - 1; j >= 0; j--) {
				// 빈칸 발견하면 큐에넣고
				if (map[j][i] == DOT) q.push(make_pair(j, i));
				// 빈칸이 아니고, 큐가 안비어있으면(큐가 비어있으면, 아직 빈칸 없음)
				else if (map[j][i] != DOT && !q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					// 뿌요를 빈칸에 이동시키고, 이동시킨 곳은 빈칸으로 채우고, 큐에넣음
					map[y][x] = map[j][i];
					map[j][i] = DOT;
					q.push(make_pair(j, i));
				}
			}
		}
	}
	return cnt;
}

int main(void) {
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COL; j++)
			cin >> map[i][j];

	printf("%d\n", go(0));
}