#include <iostream>
#include <vector>
#define MAX 987654321
using namespace std;

const int row = 5;
const int col = 9;
int ansPin;
int ansMove;

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
vector<vector<char>> map;

void dfs(int y, int x, int pinNum, int depth) {
	if (pinNum <= ansPin) {
		if (pinNum == ansPin) ansMove = (ansMove > depth ? depth : ansMove);
		else { ansPin = pinNum; ansMove = depth; }
	}

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && ny < row && nx >= 0 && nx < col) {
			// 'o'가 아니면 다음반복
			if (map[ny][nx] != 'o') continue;
			// 'o'면 그다음칸 빈칸인지 체크하고 이동
			int nny = ny + dy[i];
			int nnx = nx + dx[i];
			if (nny >= 0 && nny < row && nnx >= 0 && nnx < col) {
				if (map[nny][nnx] == '.') {
					//이동
					map[y][x] = map[ny][nx] = '.';
					map[nny][nnx] = 'o';

					for (int i = 0; i < row; i++)
						for (int j = 0; j < col; j++)
							if (map[i][j] == 'o')
								dfs(i, j, pinNum - 1, depth + 1);
					// 복구
					map[y][x] = map[ny][nx] = 'o';
					map[nny][nnx] = '.';
				}
			}
		}
	}
}

int main(void) {
	int T; cin >> T;

	for (int t = 0; t < T; t++) {
		map = vector<vector<char>>(row, vector<char>(col));
		int pinNum = 0;
		ansPin = ansMove = MAX;

		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++) {
				cin >> map[i][j];
				if (map[i][j] == 'o') pinNum++;
			}

		for(int i = 0; i < row; i++)
			for (int j = 0; j < col; j++) 
				if (map[i][j] == 'o') 
					dfs(i, j, pinNum, 0);

		printf("%d %d\n", ansPin, ansMove);
	}
} 