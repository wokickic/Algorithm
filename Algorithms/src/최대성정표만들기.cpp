#include <iostream>
#include <vector>
#include <algorithm>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

int n, k;
int ans;
vector<int> subScore;

void dfs(int node, int sum,int depth) {
	if (depth == k) {
		ans = max(ans, sum);
		return;
	}
	
	for (int i = node + 1; i < k; i++) dfs(i, sum + subScore[i], depth + 1);

}

int main(void) {
	int T; cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> n >> k; 
		ans = 0;
		subScore = vector<int>(n, 0);
		for (int i = 0; i < n; i++) cin >> subScore[i];
		sort(subScore.begin(), subScore.end());
		reverse(subScore.begin(), subScore.end());

		for (int i = 0; i < k; i++) ans += subScore[i];

		printf("#%d %d\n", t, ans);
	}
}

