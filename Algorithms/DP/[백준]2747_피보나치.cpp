#include <iostream>
#include <vector>
using namespace std;

vector<int> memo;
int fibo(int n) {
	if (n <= 1) return n;
	else {
		if (memo[n] > 0) return memo[n];
		else return memo[n] = fibo(n - 1) + fibo(n - 2);
	}
}

int main(void) {
	int n; cin >> n;
	memo = vector<int>(n + 1, 0);
	
	printf("%d\n", fibo(n));
}