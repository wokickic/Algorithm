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
		// max, min 구하기
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
//	// 연산자의 개수 만큼 dfs실행하면 최대, 최소 구함
//	if (depth == (n - 1)) {
//		// max, min 구하기
//		min_ = min(min_, sum);
//		max_ = max(max_, sum);
//		return; // for문으로 안들어가게 리턴을 잘해주자
//	}
//
//	for (int i = 0; i < 4; i++) {
//		//i = 0 , 1 , 2, 3
//		//op = +, -, *, /
//		if (op[i] > 0) {
//			// 연산후 dfs로 보낼것이기 때문에 -1 해주자
//			op[i] -= 1; 
//			dfs(calc(sum, num[depth + 1], i), depth + 1);
//			op[i] += 1; //다시 복구 
//		}
//	}
//}
//
//int main(void) {
//	int T; cin >> T;
//	for (int t = 1; t <= T; t++) {
//		cin >> n;
//
//		// 벡터, 변수 초기화
//		num = vector<int>(n, 0);
//		op = vector<int>(4, 0);
//		min_ = MAX;
//		max_ = MIN;
//
//		// 각각의 연산자 개수 저장
//		for (int i = 0; i < 4; i++)
//			cin >> op[i];
//		// 숫자 저장
//		for (int i = 0; i < n; i++)
//			cin >> num[i];
//
//		// 연산결과, 깊이
//		dfs(num[0], 0);
//		printf("#%d %d\n", t, max_ - min_);
//	}
//}