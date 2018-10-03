#include <iostream>
#include <vector>
#include <algorithm>
#define max(a, b) ((a > b) ? (a) : (b))
using namespace std;

long long int k, n;

int main(void) {
	cin >> k >> n;
	long long int left, right, mid;
	vector<long long int> v(k);

	for (int i = 0; i < k; i++) cin >> v[i];
	sort(v.begin(), v.end());
	right = v[k - 1];
	left = 1; // 0일때 안됨
	
	int ans = 0;
	while (left <= right) {
		int cnt = 0;
		mid = (right + left) / 2;

		for (int i = 0; i < k; i++) 
			cnt = cnt + (v[i] / mid);
		
		if (cnt >= n) {
			// 답보다 많이 나오는 경우
			//최대 길이 저장 
			ans = max(ans, mid);
			// 조금더 길게 잘라보기 
			left = mid + 1;
		}
		// 더 작게 자르기
		else right = mid - 1;
	}
	printf("%lld\n", ans);
}