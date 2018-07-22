#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;

class Search{
	int n;
	vector<bool> check;
public:
	Search(int n_) : n(n_){
		check = vector<bool>(n + 1, false);
	}

	void c_clear(){ check.clear(); check = vector<bool>(n + 1, false); }

	void dfs(int here){
		check[here] = true;
		printf("%d ", here);
		for (int i = 0; i < adj[here].size(); i++){
			int next = adj[here][i];
			if (!check[next]) dfs(next);
		}
	}

	void bfs(int here){
		queue<int> q;
		q.push(here);
		check[here] = true;
		while (!q.empty()){
			here = q.front(); q.pop();
			printf("%d ", here);
			for (int i = 0; i < adj[here].size(); i++){
				int next = adj[here][i];
				if (!check[next]){ check[next] = true; q.push(next); }
			}
		}
	}

};

int main(void){
	int n, m, v; 
	cin >> n >> m >> v;

	// make adj list
	adj = vector<vector<int>>(n + 1, vector<int>());
	for (int i = 0; i < m; i++){
		int in1, in2; cin >> in1 >> in2;
		adj[in1].push_back(in2);
		adj[in2].push_back(in1);
	}
	for (int i = 0; i < n + 1; i++) sort(adj[i].begin(), adj[i].end());

	Search search(n);
	search.dfs(v); printf("\n");
	search.c_clear();
	search.bfs(v); printf("\n");
}