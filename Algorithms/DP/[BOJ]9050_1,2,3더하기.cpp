#include <iostream>
using namespace std;

int main(void){
	int n; cin >> n;
	int ans[12];

	ans[1] = 1;
	ans[2] = 2;
	ans[3] = 4;

	// 미리값 구하기
	for (int i = 4; i < 12; i++) ans[i] = ans[i - 1] + ans[i - 2] + ans[i - 3];

	// 출력
	for (int i = 0; i < n; i++){
		int in; cin >> in;
		printf("%d\n", ans[in]);
	}
}