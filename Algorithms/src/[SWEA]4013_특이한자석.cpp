#include <iostream>
#include <deque>
#include <vector>
using namespace std;
vector<deque<int>> topni;
int visit[4];

void find(int here, int rotate) {
	int right = here + 1;
	int left = here - 1;
	visit[here] = rotate;

	if (right < 4 && !visit[right]) 
		if(topni[here][2] != topni[right][6])
			find(right, rotate * (-1));
	
	if (left >= 0 && !visit[left]) 
		if(topni[here][6] != topni[left][2])
			find(left, rotate * (-1));
}

void move() {
	for (int i = 0; i < 4; i++) {
		int rotate = visit[i];
		if (rotate == 1) {
			int tmp = topni[i][7]; 
			topni[i].pop_back();
			topni[i].push_front(tmp);
		}
		else if(rotate == -1){
			int tmp = topni[i][0];
			topni[i].pop_front();
			topni[i].push_back(tmp);
		}
	}
}

int main(void) {
	int T; cin >> T;
	topni = vector<deque<int>>(4, deque<int>(8));

	for (int t = 1; t <= T; t++) {
		int k; cin >> k;

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 8; j++) 
				cin >> topni[i][j];

		for (int i = 0; i < k; i++) {
			int topNum, rotate; cin >> topNum >> rotate;
			// visit은 i번째 톱니바퀴의 회전정보를 저장
			for (int i = 0; i < 4; i++) visit[i] = 0;
			find(topNum - 1, rotate);
			move();
		}
		int ans = 0;

		for (int i = 0; i < 4; i++) 
			if (topni[i][0] == 1) 
				ans += (1 << i);
		printf("#%d %d\n", t, ans);
	}
}