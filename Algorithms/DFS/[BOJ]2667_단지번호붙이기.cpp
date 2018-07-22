#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

class findDanji{
	int n;
	
public:
	vector<vector<int>> map;
	findDanji(int n_) : n(n_){
		vector<vector<int>> tmp(n, vector<int>(n));
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				scanf("%1d", &tmp[i][j]);
			}
		}
		map = tmp;
	}

	int dfs(int y, int x, int cnt){
		map[y][x] += 1;
		for (int i = 0; i < 4; i++){
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < n && nx < n){
				if (map[ny][nx] == 1) {
					cnt = dfs(ny, nx, cnt + 1);
				}
			}
		}
		return cnt;
	}
};

int main(void){
	int n, cnt = 0;
	vector<int> ans;
	cin >> n;
	findDanji start(n);

	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (start.map[i][j] == 1) { 
				ans.push_back(start.dfs(i, j, 1));
				cnt++; 
			}
		}
	}
	sort(ans.begin(), ans.end());
	printf("%d\n", cnt);
	for (int i = 0; i < ans.size(); i++) printf("%d\n", ans[i]);
}