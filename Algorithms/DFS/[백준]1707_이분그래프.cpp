#include <iostream>
#include <vector>
#include <string>
#define RED 1
#define BLUE 2
using namespace std;

vector<vector<int>> adjList;
vector<int> Biparti;

bool findAns(int v) {
	for (int i = 0; i < v; i++)
		for (int j = 0; j < adjList[i].size(); j++) {
			int next = adjList[i][j];
			// ���� ���� ������ ����� ������ �޶����
			// ���� ���� ������ �̺б׷����� �ƴ�
			if (Biparti[i] == Biparti[next]) return false;
		}
	return true;
}

void dfs(int here, int color) {
	// 0�� �ƴϸ� RED or BLUE�� ���� ���������� �׷��� ������
	if (Biparti[here]) return;

	// visit
	Biparti[here] = color;
	for (int i = 0; i < adjList[here].size(); i++) {
		int next = adjList[here][i];
		// ���� ���� ���� ���� �ٸ� ���� �ο���
		// ���� ��尡 RED�� BLUE�� ������
		// ���� ��尡 BLUE�� RED�� ����
		dfs(next, (color == RED ? BLUE : RED));
	}
}

int main(void) {
	int T; cin >> T;

	for (int t = 0; t < T; t++) {
		int v, e;
		cin >> v >> e;

		//���� �ʱ�ȭ
		adjList = vector<vector<int>>(v + 1);
		Biparti = vector<int>(v + 1, 0);

		// ��������Ʈ ����
		for (int i = 0; i < e; i++) {
			int in1, in2; cin >> in1 >> in2;
			adjList[in1].push_back(in2);
			adjList[in2].push_back(in1);
		}

		// 1���� �׷����� �شٰ� ����, �湮 ���� �׷��� ��� �湮�ϱ� ���ؼ� for�� ���
		for (int i = 1; i <= v; i++)
			// ������ RED��, 0�̸� �湮 ���׻����̱� ������ dfs() ����
			if (!Biparti[i]) dfs(i, RED);

		// ��ã��, 
		printf("%s\n", (findAns(v) ? "YES" : "NO"));
	}
}