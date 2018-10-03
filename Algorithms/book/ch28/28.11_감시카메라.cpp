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

// 지금까지 설치한 카메라의 총 수
int installed;

// here로부터 깊이 우선탐색을 하고, here의 정보를 반환한다.
int dfs(int here) {
	visited[here] = true;
	int children[3] = { 0,0,0 };

	for (int i = 0; i < adj[here].size(); i++) {
		int there = adj[here][i];
		if (!visited[there]) {
			++children[dfs(there)];
		}
	}
	// 자손 노드 중 감시되지 않는 노드가 있을 경우 카메라를 설치
	if (children[UNWATCHED]) {
		installed++;
		return INSTALLED;
	}
	// 자손 노드 중 카메라가 설치된 노드가 있을 경우 설치할 필요가 없다.  
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