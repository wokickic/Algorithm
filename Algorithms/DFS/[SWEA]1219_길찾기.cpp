#include <iostream>
#include <vector>
#define MAX 100
#define DEST 99
using namespace std;

vector<vector<int>> adjList; // 2���� �迭 ��������Ʈ
vector<int> visit; // �湮ó�� 1���� �迭, 
				   // -1 : �̹湮, 0 : ���ܳ����� �������� DEST�ƴ�
				   // 1 : ���ܳ�� ���� �������� DEST --> ��ã��

int dfs(int here) {
	// ���� ��尡 DEST�� ��ã�Ƽ� 1����
	if (here == DEST) return 1;

	// ���� ��忡�� ��������Ʈ ���� 
	for (int i = 0; i < adjList[here].size(); i++) {
		int next = adjList[here][i];
		
		// next����� ���� -1�ƴϸ� �湮�� ���, next����� ���� �����忡 �����ϰ� ���� 
		if (visit[next] != -1) return visit[here] = visit[next];

		// ���� ���� dfs(), ���ϰ��� visit�� �����ϰ� �� ���� 1�̸� ���� ã�����̱� ������
		// 1�� �����ϰ� ����
		if ((visit[here] = dfs(next)) == 1) return visit[here];
	}
	return visit[here] = 0;
}


int main(void) {
	for (int i = 1; i <= 10; i++) {
		int testccase, edge;
		cin >> testccase >> edge;
		adjList = vector<vector<int>>(MAX, vector<int>());
		visit = vector<int>(MAX, -1);

		// ��������Ʈ ����
		for (int j = 0; j < edge; j++) {
			int in1, in2;
			cin >> in1 >> in2;
			adjList[in1].push_back(in2);
		}
		printf("#%d %d\n",testccase,dfs(0));
	}
	
}