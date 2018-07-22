#include <iostream>
#include <vector>
using namespace std;

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

class Bingsan{
	int n, m;
	vector<vector<int>> map;
	vector<vector<int>> minusHeight;

public:

	Bingsan(int n_, int m_) : n(n_), m(m_){
		map = minusHeight = vector<vector<int>>(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> map[i][j];
	}

	void meltingSan(){
		for (int y = 0; y < n; y++){
			for (int x = 0; x < m; x++){
				if (map[y][x] <= 0) continue;
				for (int i = 0; i < 4; i++){
					int ny = y + dy[i];
					int nx = x + dx[i];
					if (map[ny][nx] <= 0) minusHeight[y][x]++;
				}
			}
		}
		for (int y = 0; y < n; y++) for (int x = 0; x < m; x++) {
			map[y][x] -= minusHeight[y][x];
			minusHeight[y][x] = 0; //초기화를 잘해줍시다
		}
	}

	void dfs(int y, int x, vector<vector<int>>& check){
		check[y][x] = 1;
		for (int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < n && nx < m){
				if (map[ny][nx] > 0 && !check[ny][nx]) dfs(ny, nx, check);
			}
		}
	}

	int start(){
		for (int year = 1;;year++){
			int sanCnt = 0;
			vector<vector<int>> check(n, vector<int>(m, 0));
			meltingSan();
			for (int y = 0; y < n; y++){
				for (int x = 0; x < m; x++){
					if (map[y][x] > 0 && !check[y][x]) { dfs(y, x, check); sanCnt++; }
					if (sanCnt == 2) return year;
				}
			}
			if (sanCnt == 0) return sanCnt;
		}
		return -1;
	}
};


// 1. 각칸마다 돌면서 몇깍을지 minus에 저장
// 2. minus만큼 깍는다
// 3. dfs돌면서 덩어리 찾는다.

int main(void){
	int n, m; cin >> n >> m;
	Bingsan san(n, m);
	printf("%d\n", san.start());
}
