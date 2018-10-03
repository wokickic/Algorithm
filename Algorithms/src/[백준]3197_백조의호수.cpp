#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int r, c;
int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

vector<vector<char>> map;
pair<int, int> backjo;

bool find() {
	int y = backjo.first;
	int x = backjo.second;
}

int main(void) {
	cin >> r >> c;
	map = vector<vector<char>>(r, vector<char>(c));

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'L') { backjo.first = i, backjo.second = j; }
		}
	}

	for (int t = 0 ; !find() ; t++) {

	}
}