#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> map;
vector<bool> visit;

bool dfs(int here, int dist) {
	visit[here] = true;
	// 현재 노드가 페스티벌 노드의 좌표면 갈수 있기때문에 return true
	if (here == dist) return true;

	for (int i = 0; i < map[here].size(); i++) {
		int next = map[here][i];
		if (!visit[next])
			if (dfs(next, dist)) return true;
	}

	// 반복문과 재귀함수를 수행하면서 dist까지 못가면 
	// 페스티벌에 못감
	return false;
}

int main(void) {
	int T; cin >> T;
	
	for (int t = 0; t < T; t++) {
		int n; cin >> n;
		vector<pair<int, int>> v;
		// n개의 편의점에 상근이의 집과 락페스티벌 좌표를 저장해야하기 때문에
		// n + 2만큼 벡터를 생성해줌
		map = vector<vector<int>>(n + 2);
		visit = vector<bool>(n + 2, false);

		int in1, in2; cin >> in1 >> in2;
		// insert start -> 상근이집
		v.push_back(make_pair(in1, in2));
		
		// 편의점좌표 입력
		for (int i = 0; i < n; i++) {
			cin >> in1 >> in2;
			v.push_back(make_pair(in1, in2));
		}
		cin >> in1 >> in2;
		// 벡터의 마지막은 페스티벌 좌표
		v.push_back(make_pair(in1, in2));

		// create map
		// 입력받은 좌표를 1개의 노드라고 하겠음. 
		// 50미터 마다 한병씩 마시고, 맥주 한 박스에 20개 들어있어서
		// 맥주 한 박스로 최대 1000미터 갈수있음
		// 따라서 각 좌표마다 거리가 1000이하 이면 갈수 있기 때문에 연결리스트로 연결해준다.
		for (int i = 0; i < v.size(); i++) 
			for (int j = i + 1; j < v.size(); j++) {
				// abs(x좌표차이) + abs(y좌표차이) 해줘야함
				// abs(x좌표차이 + y좌표차이) 해주면 오답나옴, x좌표차이와 y좌표 차이의 부호가
				// 같으면 상관없지만 다르면 값이 달라짐
				if ((abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second)) <= 1000) {
					map[i].push_back(j);
					map[j].push_back(i);
				}
			}

		// 0번이 시작점(상근이집), 종착지는 락페스티벌 좌표
		printf("%s\n", (dfs(0, n + 1) ? "happy" : "sad"));
	}
}