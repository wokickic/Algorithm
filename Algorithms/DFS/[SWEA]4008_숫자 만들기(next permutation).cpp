#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 987654321
#define MIN -987654321
#define R_MAX(a,b) ((a) > (b) ? (a) : (b))
#define R_MIN(a,b) ((a) < (b) ? (a) : (b))
using namespace std;

int getCalc(int n1, int n2, char op) {
	if (op == '+') return n1 + n2;
	if (op == '-') return n1 - n2;
	if (op == '*') return n1 * n2;
	if (op == '/') return n1 / n2;
	return 0;
}
int main(void) {
	int T; cin >> T;

	for (int t = 1; t <= T; t++) {
		int n; cin >> n;

		vector<char> op;
		vector<int> num(n);
		for (int i = 0; i < 4; i++) {
			int in;  cin >> in;
			for (int j = 0; j < in; j++) {
				if (i == 0) op.push_back('+');
				else if (i == 1) op.push_back('-');
				else if (i == 2) op.push_back('*');
				else op.push_back('/');
			}
		}

		for (int i = 0; i < n; i++) cin >> num[i];
		int size = op.size();
		
		// next_permutation을 사용하기위해서는 정렬상태여야함
		sort(op.begin(), op.end());

		int max = MIN;
		int min = MAX;

		// next_permutation은 do-while()문에서 사용
		// 순열을 만들어서 반환해줌
		do {
			int total = num[0];
			for (int k = 0; k < size; k++) {
				total = getCalc(total, num[k + 1], op[k]);
			}

			max = R_MAX(max, total);
			min = R_MIN(min, total);
		} while (next_permutation(op.begin(), op.end()));

		printf("#%d %d\n", t, max - min);
	}
}