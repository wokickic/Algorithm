#include <cstdio>
#include <vector>
using namespace std;

vector<vector<vector<int>>> tmp(int (*arr)[10][10]) {
	printf("%d \n", arr[0][0][0]);
	printf("%d \n", arr[3][2][4]);
	arr[3][2][4] = 5;
	const vector<vector<vector<int>>> cam1({ { { 1, 0 } },
										{ { 0,1 } },
										{ { -1,0 } },
										{ { 0,-1 } } });
	return cam1;
}

vector<vector<vector<int>>> getCCTV() {
	vector<vector<vector<int>>> cam1({ { { 1, 0 } },
		{ { 0,1 } },
		{ { -1,0 } },
		{ { 0,-1 } } });
	printf("in function address : %d\n", cam1);
	return cam1;
}

int main(void) {
	int arr[10][10][10] = { 0, };
	arr[3][2][4] = 1;
	tmp(arr);
	printf("%d\n", arr[3][2][4]);
	printf("*********************\n");

	vector<vector<vector<int>>> cam1 = getCCTV();
	printf("out function address : %d\n", cam1);
	printf("%d %d\n", cam1[0][0][1], cam1[2][0][1]);
}