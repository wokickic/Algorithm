#include <iostream>
#include <vector>
using namespace std;

vector<int> cache;

int solve(int n) {
	if (n < 3)  return n;
	if (cache[n]) return cache[n];

	// 계산 결과가 int범위를 넘어가서 1007로 나눠줘야함
	else return cache[n] = (solve(n - 1) + solve(n - 2)) % 10007;
	
	return cache[n];
}

int main(void) {
	int n; cin >> n;
	cache = vector<int>(n + 1, 0);
	printf("%d\n", solve(n));
}