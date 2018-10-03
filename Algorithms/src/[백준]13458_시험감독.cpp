#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main(void) {
	int n, b, c;
	long long int ans = 0;
	cin >> n;
	v = vector<int>(n);
	for (int i = 0; i < v.size(); i++) cin >> v[i];
	cin >> b >> c; // b = 총감독, c = 부감독관

	for (int i = 0; i < v.size(); i++) {
		if (v[i] - b < 0) continue; // 감독관이 전체를 커버하는 경우
		if ((v[i] - b) % c == 0) ans = ans + ((v[i] - b) / c);
		else ans = ans + (((v[i] - b) / c) + 1);
	}
	// 정답은 감독관의 수를 더해준다.
	printf("%lld\n", ans + n);
}

// 내가 틀린경우
//
//1
//100
//1000 1