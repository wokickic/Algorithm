#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#define min(a, b) ((a) > (b) ? (b) : (a))
#define MAX 987654321;
using namespace std;

vector<vector<int>> map;

int n;
int aSum, bSum, ans;

int getSum(string s) {
	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') continue;
		for (int j = 0; j < s.size(); j++) {
			if (i == j || s[j] == '0') continue;
			sum += map[i][j];
		}
	}
	return sum;
}

void dfs(string a, string b, int cntA, int cntB) {
	if (cntA + cntB == n) {
		// 최소값 구하기
		aSum = getSum(a);
		bSum = getSum(b);
		ans = min(ans, abs(aSum - bSum));
		return;
	}
	
	if (cntA < (n / 2)) dfs(a + "1", b + "0", cntA + 1, cntB);
	if (cntB < (n / 2)) dfs(a + "0", b + "1", cntA, cntB + 1);
}

int main(void) {
	int T; cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> n;
		map = vector<vector<int>>(n, vector<int>(n));

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> map[i][j];

		aSum = bSum = 0;
		ans = MAX;

		dfs("", "", 0, 0);
		printf("#%d %d\n", t, ans);
	}
} // 0.08397s







#include <iostream>
#include <vector>
#include <cmath>
#define MAX 987654321
#define min(a, b) ((a) > (b) ? (b) : (a))
using namespace std;

int ans;
vector<vector<int>> map;
vector<int> A, B;

using namespace std;
int n;
void dfs(int idx, int cnt_A, int cnt_B) {
	if (cnt_A != 0) {
		A.push_back(idx);
		dfs(idx + 1, cnt_A - 1, cnt_B);
		A.pop_back();
	}
	if (cnt_B != 0) {
		B.push_back(idx);
		dfs(idx + 1, cnt_A, cnt_B - 1);
		B.pop_back();
	}
	if (cnt_B == 0 && cnt_A == 0) {
		int sum_a, sum_b;
		sum_a = sum_b = 0;
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				sum_a += map[A[i]][A[j]];
				sum_b += map[B[i]][B[j]];
			}
		}
		ans = min(ans, abs(sum_a - sum_b));
	}
}

int main(void) {
	int T; cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> n;
		map = vector<vector<int>>(n, vector<int>(n));

		vector<int> A, B;
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) 
				cin >> map[i][j];
			
		
		ans = MAX; A.clear(); B.clear();
		dfs(0, n / 2, n / 2);
		printf("#%d %d\n", t, ans);
	}
} // 0.03175s