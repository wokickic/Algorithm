#include <iostream>
#include <vector>	
#define max(a, b) ((a > b) ? (a) : (b))
#define min(a, b) ((a > b) ? (b) : (a))
#define MAX 100000001
#define MIN -100000001
using namespace std;

int n, max_, min_;
vector<int> op;
vector<int> num;

int calc(int num1, int num2, int oop) {
		if (oop == 0) return num1 + num2;
		else if (oop == 1) return num1 - num2;
		else if (oop == 2) return num1 * num2;
		else if (oop == 3) return num1 / num2;
}

void dfs(int sum, int depth) {
	if (depth == (n - 1)) {
		// max, min ���ϱ�
		min_ = min(min_, sum);
		max_ = max(max_, sum);
		printf("%d\n", sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			op[i] -= 1;
			dfs(calc(sum, num[depth + 1], i), depth + 1);
			op[i] += 1;
		}
	}
}

int main(void) {
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n;
		
		num = vector<int>(n, 0);
		op = vector<int>(4, 0);
		min_ = MAX;
		max_ = MIN;

		for (int i = 0; i < 4; i++)
			cin >> op[i];
		for (int i = 0; i < n; i++)
			cin >> num[i];
		
		dfs(num[0], 0);
		printf("#%d %d\n", t, max_ - min_);
	}
}












//#include <iostream>
//#include <vector>	
//#define max(a, b) ((a > b) ? (a) : (b))
//#define min(a, b) ((a > b) ? (b) : (a))
//#define MAX 100000001
//#define MIN -100000001
//using namespace std;
//
//int n, max_, min_;
//vector<int> op;
//vector<int> num;
//
//int calc(int num1, int num2, int oop) {
//	if (oop == 0) return num1 + num2;
//	else if (oop == 1) return num1 - num2;
//	else if (oop == 2) return num1 * num2;
//	else if (oop == 3) return num1 / num2;
//}
//
//void dfs(int sum, int depth) {
//	// �������� ���� ��ŭ dfs�����ϸ� �ִ�, �ּ� ����
//	if (depth == (n - 1)) {
//		// max, min ���ϱ�
//		min_ = min(min_, sum);
//		max_ = max(max_, sum);
//		return; // for������ �ȵ��� ������ ��������
//	}
//
//	for (int i = 0; i < 4; i++) {
//		//i = 0 , 1 , 2, 3
//		//op = +, -, *, /
//		if (op[i] > 0) {
//			// ������ dfs�� �������̱� ������ -1 ������
//			op[i] -= 1; 
//			dfs(calc(sum, num[depth + 1], i), depth + 1);
//			op[i] += 1; //�ٽ� ���� 
//		}
//	}
//}
//
//int main(void) {
//	int T; cin >> T;
//	for (int t = 1; t <= T; t++) {
//		cin >> n;
//
//		// ����, ���� �ʱ�ȭ
//		num = vector<int>(n, 0);
//		op = vector<int>(4, 0);
//		min_ = MAX;
//		max_ = MIN;
//
//		// ������ ������ ���� ����
//		for (int i = 0; i < 4; i++)
//			cin >> op[i];
//		// ���� ����
//		for (int i = 0; i < n; i++)
//			cin >> num[i];
//
//		// ������, ����
//		dfs(num[0], 0);
//		printf("#%d %d\n", t, max_ - min_);
//	}
//}