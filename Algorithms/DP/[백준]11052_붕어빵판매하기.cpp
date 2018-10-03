#include <iostream>
#include <vector>
#define max(a, b) ((a > b) ? (a) : (b))
using namespace std;

vector<int> price, cache;
int n;

int solve(int ea) {
	if (ea == 0) return price[1];
	if (cache[ea] > 0) return cache[ea];

	for (int i = 1; i <= n; i++) {
		if(ea - i > 0)
			cache[ea] = max(cache[ea], solve(ea - i) + price[ea]);
	}
	return cache[ea];
}

int main(void) {
	cin >> n;
	
	cache = price = vector<int>(n + 1, 0);
	
	for (int i = 1; i <= n; i++) cin >> price[i];

	printf("%d\n", solve(n));
}