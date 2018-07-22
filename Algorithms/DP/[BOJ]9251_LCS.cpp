#include <iostream>
#include <string>
#include <vector>
#define SIZE_MAX 1001
#define max(a,b) ((a) >= (b) ? (a) : (b))
using namespace std;

int main(void) {
	string s1, s2; cin >> s1 >> s2;
	vector<vector<int>> LCS(SIZE_MAX, vector<int>(SIZE_MAX, 0));

	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			if (s1[i - 1] == s2[j - 1]) LCS[i][j] = LCS[i - 1][j - 1] + 1;
			else LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
		}
	}

	printf("%d\n", LCS[s1.size()][s2.size()]);
}

/* Âü°í : http://mygumi.tistory.com/126 */