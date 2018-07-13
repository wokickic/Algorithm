#include <iostream>
#include <vector>
#include <queue>
#define max(a, b) ((a) > (b) ? (a) : (b))
using namespace std;


const int dy[] = { 0, 1, 0, -1 };
const int dx[] = { 1, 0, -1, 0 };
const int NSIZE = 101;

int n;
vector<vector<int>> map, visit;

void dfs(int y, int x, int h) {
	visit[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny >= 0 && nx >= 0 && ny < n && nx < n) {
			if (map[ny][nx] > h && visit[ny][nx] == 0) dfs(ny, nx, h);
		}
	}
}

int main(void) {
	cin >> n;
	map = vector<vector<int>>(n, vector<int>(n, 0));
	vector<bool> heightCheck(NSIZE, false);
	queue<int> height;

	// create map
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			// �Է°��� ���� �ε����� true�� �ٲ���
			if (!heightCheck[map[i][j]]) heightCheck[map[i][j]] = true;
		}
	}

	// 0 ~ 101���� ���鼭 true�̸� heightť�� �߰�
	for (int i = 0; i < NSIZE; i++) if (heightCheck[i]) height.push(i);

	int ans = 1; 
	
	// height�迭�� ������������� �ݺ�
	while(!height.empty()){
		int h = height.front(); height.pop(); 
		visit = vector<vector<int>>(n, vector<int>(n, 0));
		int areaCnt = 0;
		for (int y = 0; y < n; y++) {
			for (int x = 0; x < n; x++) {
				// map[y][x]�� h���� ������ ���κ��̱⶧���� dfs�� �ȵ�
				if (map[y][x] > h && !visit[y][x]) { dfs(y, x, h); areaCnt++; }
			}
		}
		ans = max(ans, areaCnt); 
	}
	printf("%d\n", ans);
}



/* ���������, �ٽ� �����ϰ� �ݺ�, ��ȿ���� */
//#include <iostream>
//#include <vector>
//#define max(a, b) ((a > b) ? (a) : (b))
//using namespace std;
//
//int dy[] = { 0, 1, 0, -1 };
//int dx[] = { 1, 0, -1, 0 };
//vector<vector<int>> map;
//vector<vector<int>> check;
//vector<bool> height;
//
//class safeArea{
//	int n;
//public:
//	
//	safeArea(int n_) : n(n_){
//		map = vector<vector<int>>(n, vector<int>(n, 0));
//		check = vector<vector<int>>(n, vector<int>(n, 0));
//		height = vector<bool> (101, 0);
//
//		for (int i = 0; i < n; i++){
//			for (int j = 0; j < n; j++){
//				cin >> map[i][j];
//				if (!height[map[i][j]]) height[map[i][j]] = true;
//			}
//		}
//	}
//	
//	void makeMap(int remove){
//		for (int i = 0; i < n; i++){
//			for (int j = 0; j < n; j++){
//				if (check[i][j]) check[i][j] = 0;
//				map[i][j] -= remove;
//				map[i][j] = map[i][j] - (remove);
//			}
//		}
//	}
//
//	void dfs(int y, int x){
//		check[y][x] = 1;
//		for (int i = 0; i < 4; i++){
//			int ny = y + dy[i];
//			int nx = x + dx[i];
//			if (ny >= 0 && nx >= 0 && ny < n && nx < n){
//				if (map[ny][nx] >0 && check[ny][nx] == 0) dfs(ny, nx);
//			}
//		}
//	}
//};
//
//int main(void){
//	int n; cin >> n;
//	int ans = 0;
//	safeArea safe(n);
//
//	for (int i = 0; i < height.size(); i++){
//		if (!height[i]) continue;
//		int area = 0;
//		safe.makeMap(i); // ���̱��� ����
//		for (int y = 0; y < n; y++){
//			for (int x = 0; x < n; x++){
//				if (map[y][x] > 0 && check[y][x] == 0) { safe.dfs(y, x); area++; }
//			}
//		}
//		safe.makeMap(-i);// ���� ����
//		ans = max(ans, area);
//	}
//	printf("%d\n", ans);
//}

