#include <iostream>
#include <vector>
//#define MAX_V = 1000;
using namespace std;

const int MAX_V = 1000;

int V;
vector<int> adj[MAX_V];
vector<bool> visited;

const int UNWATCHED = 0;
const int WATHCED = 1;
const int INSTALLED = 2;

// ���ݱ��� ��ġ�� ī�޶��� �� ��
int installed;

// here�κ��� ���� �켱Ž���� �ϰ�, here�� ������ ��ȯ�Ѵ�.
int dfs(int here) {
	visited[here] = true;
	int children[3] = { 0,0,0 };

	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		if (!visited[there]) {
			++children[dfs(there)];
		}
	}
	// �ڼ� ��� �� ���õ��� �ʴ� ��尡 ���� ��� ī�޶� ��ġ
	if (children[UNWATCHED]) {
		installed++;
		return INSTALLED;
	}
	// �ڼ� ��� �� ī�޶� ��ġ�� ��尡 ���� ��� ��ġ�� �ʿ䰡 ����.  
	if (children[INSTALLED]) return WATHCED;

	return UNWATCHED;
}

int installCamera() {
	installed = 0;
	visited = vector<bool>(V, false);

	for (int u = 0; u < V; u++) {
		if (!visited[u] && dfs(u) == UNWATCHED) installed++;
	}
	return installed;
}