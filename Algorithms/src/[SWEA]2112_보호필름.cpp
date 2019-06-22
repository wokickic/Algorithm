#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map;
int d, w, k;
int ans;

bool check() {
	for (int j = 0; j < w; j++) {
		int cnt = 1;
		for (int i = 0; i < d - 1 && cnt <= k - 1; i++) {
			if (map[i][j] == map[i + 1][j]) cnt++;
			else cnt = 1;
		}
		if (cnt < k) return false;
	}
	return true;
}

void InputYak(int row, int paint, int yag) {
	if (row >= d) return;
	if (paint >= ans) return;
	
	if (check()) {
		ans = paint;
		return;
	}
	
	vector<int> copyCell = map[row];
	for (int i = 0; i < w; i++) 
		map[row][i] = yag;
	
	for (int i = row + 1; i < d; i++) {
		InputYak(i, paint + 1, 0);
		InputYak(i, paint + 1, 1);
	}
	for (int i = 0; i < w; i++) map[row][i] = copyCell[i];
}

int main(void) {
	int T; cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> d >> w >> k;
		ans = 987654321;
		
		map = vector<vector<int>>(d, vector<int>(w));

		for (int i = 0; i < d; i++)
			for (int j = 0; j < w; j++)
				cin >> map[i][j];
		
		for (int i = 0; i < d; i++) {
			InputYak(i, 0, 0); // A변환
			InputYak(i, 0, 1); // B변환
		}
		
		if (ans == 987654321) printf("#%d 0\n", t);
		else printf("#%d %d\n", t, ans);
	}
}