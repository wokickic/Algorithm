#include <iostream>
#include <vector>
#include <queue>
#define MAX 200002
using namespace std;

int move(int n, int k) {
	queue<int> q;
	vector<int> map(MAX, -1);
	map[n] = 0;
	q.push(n);

	while (map[k] == -1) {
		n = q.front(); q.pop();
		// n - 1, n + 1, n * 2 각각의 경우에 대해서 판단을 하고 큐에 넣어준다.
		// 최대범위 만큼 해줘야 런타임에러 안남
		if (n - 1 >= 0 && map[n - 1] == -1) { map[n - 1] = map[n] + 1; q.push(n - 1); }
		if ((n + 1 < MAX) && map[n + 1] == -1) { map[n + 1] = map[n] + 1; q.push(n + 1); }
		if ((n * 2 < MAX) && map[n * 2] == -1) { map[n * 2] = map[n] + 1; q.push(n * 2); }
	}
	return map[k];
}

int main(void) {
	int n, k; cin >> n >> k;
	printf("%d\n", move(n, k));
}