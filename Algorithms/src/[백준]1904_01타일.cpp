#include <iostream>
#define MAX 1000001
using namespace std;

int cache[MAX];

long long tile(int n) {
	if (n <= 2) return n;
	else {
		if (!cache[n]) return cache[n] = (tile(n - 1) + tile(n - 2)) % 15746;
		else return cache[n];
	}
	return 0;
}

int main(void) {
	int n; cin >> n;
	// 피보나치 함수 tile[n] = tile[n-1] + tile[n-2]
	printf("%d\n", tile(n));
}