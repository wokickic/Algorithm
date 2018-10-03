#include <iostream>
#include <vector>
using namespace std;

int n, w, h;
vector<vector<int>> map;


void init() {
	cin >> n >> w >> h;
	map = vector<vector<int>>(h, vector<int>(w));

	for (int i = 0; i < h; h++)
		for (int j = 0; j < w; w++)
			cin >> map[i][j];
}

int main(void) {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		init();

		printf("  \n");
	}
}