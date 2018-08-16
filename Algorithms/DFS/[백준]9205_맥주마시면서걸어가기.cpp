#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> map;
vector<bool> visit;

bool dfs(int here, int dist) {
	visit[here] = true;
	// ���� ��尡 �佺Ƽ�� ����� ��ǥ�� ���� �ֱ⶧���� return true
	if (here == dist) return true;

	for (int i = 0; i < map[here].size(); i++) {
		int next = map[here][i];
		if (!visit[next])
			if (dfs(next, dist)) return true;
	}

	// �ݺ����� ����Լ��� �����ϸ鼭 dist���� ������ 
	// �佺Ƽ���� ����
	return false;
}

int main(void) {
	int T; cin >> T;
	
	for (int t = 0; t < T; t++) {
		int n; cin >> n;
		vector<pair<int, int>> v;
		// n���� �������� ������� ���� ���佺Ƽ�� ��ǥ�� �����ؾ��ϱ� ������
		// n + 2��ŭ ���͸� ��������
		map = vector<vector<int>>(n + 2);
		visit = vector<bool>(n + 2, false);

		int in1, in2; cin >> in1 >> in2;
		// insert start -> �������
		v.push_back(make_pair(in1, in2));
		
		// ��������ǥ �Է�
		for (int i = 0; i < n; i++) {
			cin >> in1 >> in2;
			v.push_back(make_pair(in1, in2));
		}
		cin >> in1 >> in2;
		// ������ �������� �佺Ƽ�� ��ǥ
		v.push_back(make_pair(in1, in2));

		// create map
		// �Է¹��� ��ǥ�� 1���� ����� �ϰ���. 
		// 50���� ���� �Ѻ��� ���ð�, ���� �� �ڽ��� 20�� ����־
		// ���� �� �ڽ��� �ִ� 1000���� ��������
		// ���� �� ��ǥ���� �Ÿ��� 1000���� �̸� ���� �ֱ� ������ ���Ḯ��Ʈ�� �������ش�.
		for (int i = 0; i < v.size(); i++) 
			for (int j = i + 1; j < v.size(); j++) {
				// abs(x��ǥ����) + abs(y��ǥ����) �������
				// abs(x��ǥ���� + y��ǥ����) ���ָ� ���䳪��, x��ǥ���̿� y��ǥ ������ ��ȣ��
				// ������ ��������� �ٸ��� ���� �޶���
				if ((abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second)) <= 1000) {
					map[i].push_back(j);
					map[j].push_back(i);
				}
			}

		// 0���� ������(�������), �������� ���佺Ƽ�� ��ǥ
		printf("%s\n", (dfs(0, n + 1) ? "happy" : "sad"));
	}
}