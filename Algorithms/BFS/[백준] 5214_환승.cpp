#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k, m;
vector<vector<int>> station, tube;
vector<int> s_visit, t_visit;

int bfs(int here) {
	// ���� ���� ť�� �ְ� �湮���� ���� 1�� �ʱ�ȭ
	queue<int> q;
	q.push(here);
	s_visit[here] = 1;

	while (!q.empty()) {
		here = q.front();
		q.pop();
		// ���� ���� n��° ���̸� 
		// s_visit[here]�� ����� n��° ������ �湮�� ���� ����
		if (here == n) return s_visit[here];

		for (int i = 0; i < station[here].size(); i++) {
			// ���� ���� ���Ե� Ʃ���ȣ�� ttube�� ����
			int ttube = station[here][i];
			if (!t_visit[ttube]) { 
				// ���� �湮 ���� Ʃ��
				t_visit[ttube] = true;
				
				// Ʃ�꿡���Ե� ������ �湮Ƚ�� ���ϰ� ť�� ����
				for (int j = 0; j < tube[ttube].size(); j++) {
					int nextStation = tube[ttube][j];
					if (!s_visit[nextStation]) { 
						// ������ �湮 �������� visit 1������Ű�� ť�� ����
						s_visit[nextStation] = s_visit[here] + 1;
						q.push(nextStation);
					}
				}
			}
		}
	}
	// while�� ���������� ���� ���ϸ� 
	// �̵��Ҽ� ���°��, -1 ����
	return -1;
}

int main(void) {
	cin >> n >> k >> m;

	// ���� �ʱ�ȭ
	station = vector<vector<int>>(n + 1);
	tube = vector<vector<int>>(m + 1);
	s_visit = vector<int>(n + 1, 0);
	t_visit = vector<int>(m + 1, false);

	for (int i = 1; i <= m; i++) { // i = tube ��ȣ
		for (int j = 0; j < k; j++) {
			int in; cin >> in;
			station[in].push_back(i); // in�� ��忡 ����� Ʃ�� ����
			tube[i].push_back(in);  // tube�� in�� ��� ����
		}
	}
	// 1�� ������ bfs() ����
	printf("%d\n", bfs(1));
}

