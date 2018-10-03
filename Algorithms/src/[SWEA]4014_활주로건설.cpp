#include <iostream>
#include <vector>
using namespace std;

int n, x, ans;
vector<vector<int>> map, visitRow, visitCol;


void checkRow() {
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (map[i][j] == map[i][j - 1]) continue; // 다음이랑 같으면 넘어감
			
			int diff = map[i][j] - map[i][j - 1];
			if (diff > 1 || diff < -1) { ans--; break; } // 차이가 2이상 나면 경사로 설치 불가능
			
			// 활주로 건설이 가능한지 불가능한지 저장하는 변수
			bool flag = false;
			// 왼쪽이 더큰경우
			if (diff == -1) {
				int comp = map[i][j]; // 비교 기준

				for (int k = j, l = 0; l < x; l++, k++) {
					if (k >= 0 && k < n) { // 범위체크
						// map[i][k]가 높이가 똑같고, 아직 활주로 건설 안한경우
						// 활주로 건설해주고 다음 반복
						if (map[i][k] == comp && !visitRow[i][k]) { visitRow[i][k] = 1; continue; }
						else { flag = true; break; }// 높이가 다르거나, 이미 활주로가 건설되어있는경우
					}
					else { flag = true; break; }// 범위 벗어나면 활주로 건설 실패
				}
				if (flag) { ans--; break; }// flag가 true면 활주로 건설 실패해서 다음줄로 ㄱㄱ
				// 활주로가 완성되면 경사로 길이 x만큼 j를 이동시켜준다.
				else j = j + x - 1;
			}
			
			// 오른쪽이 더큰경우
			else {
				int comp = map[i][j - 1]; // 비교 기준
				for (int k = j - 1, l = 0; l < x; l++, k--) {
					if (k >= 0 && k < n) { //범위체크
						if (map[i][k] == comp && !visitRow[i][k]) { visitRow[i][k] = 1; continue; }
						else { flag = true; break; } // 높이가 다르거나, 이미 활주로가 건설되어있는 경우
					}
					else { flag = true; break; } // 범위 벗어나면 활주로 건설 실패
				}
				if (flag) { ans--; break; } // flag가 true면 활주로 건설 실패해서 다음 줄로 ㄱㄱ
			}
		}
	}
}

void checkCol() {
	for (int j = 0; j < n; j++) {
		for (int i = 1; i < n; i++) {
			if (map[i][j] == map[i - 1][j]) continue; // 다음이랑 같으면 넘어감

			int diff = map[i][j] - map[i - 1][j];
			if (diff > 1 || diff < -1) { ans--; break; } // 차이가 2이상 나면 경사로 설치 불가능

			bool flag = false;
			// 위쪽이 더큰경우
			if (diff == -1) {
				int comp = map[i][j]; // 비교 기준

				for (int k = i, l = 0; l < x; l++, k++) {
					if (k >= 0 && k < n) { // 범위체크
										   // map[k][j]가 높이가 똑같고, 아직 활주로 건설 안한경우
										   // 활주로 건설해주고 다음 반복
						if (map[k][j] == comp && !visitCol[k][j]) { visitCol[k][j] = 1; continue; }
						else { flag = true; break; }// 높이가 다르거나, 이미 활주로가 건설되어있는경우
					}
					else { flag = true; break; }// 범위 벗어나면 활주로 건설 실패
				}
				if (flag) { ans--; break; }// flag가 true면 활주로 건설 실패해서 다음줄로 ㄱㄱ
				else i = i + x - 1;
			}

			// 아래쪽이 더큰경우
			else {
				int comp = map[i - 1][j]; // 비교 기준
				for (int k = i - 1, l = 0; l < x; l++, k--) {
					if (k >= 0 && k < n) { //범위체크
						if (map[k][j] == comp && !visitCol[k][j]) { visitCol[k][j] = 1; continue; }
						else { flag = true; break; } // 높이가 다르거나, 이미 활주로가 건설되어있는 경우
					}
					else { flag = true; break; } // 범위 벗어나면 활주로 건설 실패
				}
				if (flag) { ans--; break; } // flag가 true면 활주로 건설 실패해서 다음 줄로 ㄱㄱ
			}
		}
	}
}

int main(void) {
	int T; cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> n >> x;
		//  가로, 세로 방문체크하는 배열만듬
		visitRow = visitCol = map = vector<vector<int>>(n, vector<int>(n, 0));

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> map[i][j];

		// 활주로를 건설할 수 있는 최대의 경우
		ans = n * 2;
		checkRow();
		checkCol();
		printf("#%d %d\n", t, ans);
	}
}