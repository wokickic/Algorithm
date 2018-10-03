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
	left = 1; // 0�϶� �ȵ�
	
	int ans = 0;
	while (left <= right) {
		int cnt = 0;
		mid = (right + left) / 2;

		for (int i = 0; i < k; i++) 
			cnt = cnt + (v[i] / mid);
		
		if (cnt >= n) {
			// �亸�� ���� ������ ���
			//�ִ� ���� ���� 
			ans = max(ans, mid);
			// ���ݴ� ��� �߶󺸱� 
			left = mid + 1;
		}
		// �� �۰� �ڸ���
		else right = mid - 1;
	}
	printf("%lld\n", ans);
}