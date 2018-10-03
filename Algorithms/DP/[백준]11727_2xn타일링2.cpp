#include <iostream>
#include <vector>
using namespace std;

vector<int> cache;

int solve(int n) {
	if (n < 3) return cache[n];
	if (cache[n]) return cache[n];

	return cache[n] = (solve(n - 1) + (2 * solve(n - 2))) % 10007;
}

int main(void) {
	int n; cin >> n;
	cache = vector<int>(n + 1, 0);
	cache[1] = 1;
	cache[2] = 3;
	printf("%d\n", solve(n));
}