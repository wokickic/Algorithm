#include <vector>
#include <iostream>
#define MAX 100001
using namespace std;

vector<vector<int>> map;
int n, m;

vector<vector<int>> bfs() {
	//vector<vector<int>>mapCopy(n, vector<int>(m, 0));
	vector<vector<int>> mapCopy = map; // 값 복사

	mapCopy[0][0] = 5;
	printf("address int bfs(): %d\n",mapCopy);
	return mapCopy; // 주소를 리턴함
}

void dfs() {
	/*vector<vector<int>> mapCopy = map;
	mapCopy[0][0] = 9999;*/
	
	vector<vector<int>> mapCopy = bfs();
	printf("address int dfs(): %d\n", mapCopy);
	printf("%d %d\n", map[0][0], mapCopy[0][0]);

}
int main(void) {
	cin >> n >> m;

	map = vector<vector<int>>(n, vector<int>(m, 0));
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	//dfs();
	//vector<int> v(100001); // ok 
	//vector<vector<int>> v(MAX, vector<int>(MAX, 0)); // ok 오래걸림
	vector<vector<int>> v(MAX); //ok

	printf("%d\n", map[0][0]);
}