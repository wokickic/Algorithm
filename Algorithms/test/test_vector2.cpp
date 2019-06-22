#include <iostream>
#include <vector>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };

int n, ans;
vector<vector<int> > map;

vector<vector<int> > dfs(int dir, int cnt, vector<vector<int> >& mmap) {
	//if (cnt == 5) {
	//	// �ִ� �� ���ϱ�
	//	return ;
	//}
	/*for (int i = 0; i < 4; i++) {
		move(i);
		dfs(i, cnt + 1);
	}*/

	vector<vector<int> > copymap = mmap;
	mmap[0][0] = 5;
	//printf("copymap address : %d\n", copymap);
	cout << "copymap address : " <<  &copymap << "\n";
	return copymap;
}

int main(int arg, char** argc) {
	cin >> n;
	map = vector<vector<int> >(n, vector<int>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	printf("map address : %d\n", map);

	vector<vector<int> > retmap = dfs(0, 0, map);
	printf("retmap address : %d\n", retmap);
}