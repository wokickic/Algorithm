#include <iostream>
#include <vector>
#define MAX 987654321
#define WIRE -1
#define CORE 1

using namespace std;

typedef struct Core {
	int y, x;
	// 벽에 붙어있으면 true,
	// 벽에 떨어져있으면 false
	bool wall;
	Core() {}
	Core(int y_, int x_, bool wall_) : y(y_), x(x_), wall(wall_) {}
};

vector<vector<int>> map;
vector<Core> core;
int n, ansConnect, ansWire;
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

bool move(int y, int x ,int dir, int sum, int& ncnt, int remove) {
	int cnt = 0;
	while(1) {
		y = y + dy[dir];
		x = x + dx[dir];
		
		// 아... 조건... 조건을 잘 검토하자....
		// 범위를 넘어가면 가장자리까지 연결성공, 반복문 종료하고 true 리턴
		if (y < 0 || x < 0 || y > n - 1 || x > n - 1) break;

		// 전선깔기
		if (sum == -1) 
			//다음 좌표에 코어가 있거나 전선이 있으면 연결 실패
			if (map[y][x] == CORE || map[y][x] == WIRE) return false;
		
		// 전선복구
		if (sum == 1)
			// cnt와 remove가 같으면 이동한 만큼 전선복구 완료
			if (cnt == remove) return false;

		// suum이 -1 이면 전선 까는것, 1이면 이전상태로 복구
		map[y][x] += sum; ncnt = cnt = (cnt + 1);
	}
	return true;
}

void dfs(int idx, int connect, int cnt) {
	// idx는 코어의 번호
	if (idx == core.size()) {
		// 전선의 길이 구하기
		if (connect >= ansConnect) {
			if (connect == ansConnect) ansWire = (cnt < ansWire ? cnt : ansWire);
			else { ansConnect = connect; ansWire = cnt; }
		}
		return;
	}

	// 벽에 붙어있으면 4방향 검사안하고 다음 코어로 이동
	if (core[idx].wall) dfs(idx + 1, connect + 1, cnt);

	// 4방향 탐색하면서 전선 쭉죾 넘기기
	else {
		int check = 0;// 4방향 탐색
		for (int j = 0; j < 4; j++) {
			int ncnt = 0;
			// 전선연결 성공하면 다음 core로 이동
			if (move(core[idx].y, core[idx].x, j, -1, ncnt, 0))
				// ncnt + cnt = 이동한 전선의 길이 + 이동전 전선의 길이
				dfs(idx + 1, connect + 1, ncnt + cnt);
			
			// 전선연결 실패하면 check 1더해줌
			else check += 1;

			//전선 복구
			// ncnt는 이동한 전선의 길이, ncnt만큼 -1을 0으로 바꿔줌
			move(core[idx].y, core[idx].x, j, 1, ncnt, ncnt);
		}

		// check == 4 면 4방향 모두 막힌상태, 다음 코어로 넘어감
		if (check == 4) dfs(idx + 1, connect, cnt);
	}
}

int main(void) {
	int T; cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> n; core.clear();
		map = vector<vector<int>>(n, vector<int>(n));

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] == CORE) {
					// 벽에 붙어있으면 wall의 값을 true로 저장
					if (i == 0 || j == 0 || i == n - 1 || j == n - 1) core.push_back(Core(i, j, true));
					else core.push_back(Core(i, j, false));
				}
			}
		ansWire =  MAX;
		ansConnect = 0;

		dfs(0, 0, 0);
		printf("#%d %d\n", t, ansWire);
	}
}