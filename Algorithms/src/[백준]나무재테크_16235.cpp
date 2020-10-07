#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };


typedef struct TREE {
	int y;
	int x;
	int age;
};

vector<vector<int>> init_map, map;
struct compare {
	bool operator()(TREE& a, TREE& b) {
		return a.age < b.age;
	}
};

int main(void) {
	int n, m, k;
	priority_queue<TREE, vector<TREE>, compare> pq[2];
	scanf("%d %d %d",&n, &m, &k);

	map = init_map = vector<vector<int>>(n, vector<int>(n));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int t;
			scanf("%d", &t);
			map[i][j] = init_map[i][j] = t;
		}
	}

	for (int i = 0; i < m; i++) {

	}
}