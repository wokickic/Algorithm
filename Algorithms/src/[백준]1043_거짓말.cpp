#include <iostream>
#include <vector>
using namespace std;
int n, m;

vector<int> person;
vector<vector<int>> party;
int main(void) {
	
	//cin >> n >> m;
	FILE* in = fopen("in.txt", "r");
	//FILE* out = fopen("out.txt", "w");

	if (in == NULL) printf("¾È¿­¸²\n");



	fscanf(in, "%d %d\n", &n, &m);
	printf("%d %d\n", n, m);

	/*person = vector<int>(n + 1, 0);
	party = vector<vector<int>>(m, vector<int>());*/
	
	/*int true_num; cin >> true_num;
	if (true_num == 0) { printf("%d\n", m); return 0; }

	for (int i = 0; i < true_num; i++) {
		int tmp; cin >> tmp;
		person[tmp] = 1;
	}

	for (int i = 0; i < m; i++) {
		int tmp; cin >> tmp;
		for (int j = 0; j < tmp; j++) {

		}
	}*/
}