//#include <iostream>
//using namespace std;
//
//int main(void){
//	int n; cin >> n;
//	int ans[12];
//
//	ans[1] = 1;
//	ans[2] = 2;
//	ans[3] = 4;
//
//	// 미리값 구하기
//	for (int i = 4; i < 12; i++) ans[i] = ans[i - 1] + ans[i - 2] + ans[i - 3];
//
//	// 출력
//	for (int i = 0; i < n; i++){
//		int in; cin >> in;
//		printf("%d\n", ans[in]);
//	}
//}


// 재귀함수 사용
#include <iostream>
#include <vector>
using namespace std;

vector<int> cache;
int solve(int n) {
	if (cache[n]) return cache[n];
	return cache[n] = solve(n - 1) + solve(n - 2) + solve(n - 3);
}

int main(void) {
	int T; cin >> T;
	
	for (int i = 0; i < T; i++) {
		int n; cin >> n;
		cache = vector<int>(n + 1, 0);
		cache[1] = 1;
		cache[2] = 2;
		cache[3] = 4;

		printf("%d\n", solve(n));
	}
}