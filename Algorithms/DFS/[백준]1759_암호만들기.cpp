#include <iostream>
#include <vector>
#include <algorithm>
#define VOWEL(a) ((a) ? (1) : (0))
#define CONSONANT(a) ((a) ? (0) : (1))

using namespace std;;

vector<char> alpha, v;
char vowel[] = { 'a','e','i','o','u' };
int l, c;

// a가 모음이면 true, 아니면 fals리턴
bool getVowel(char a) {
	for (int i = 0; i < 5; i++) if (a == vowel[i]) return true;
	return false;
}

void dfs(int idx, int vow, int con) { // 모음, 자음 개수
	if (v.size() == l) {
		// 벡터의 크기가 l과 같으면 출력
		if (vow >= 1 && con >= 2) {
			// 모음이 1개 이상, 자음이 2개 이상이면 출력
			for (int i = 0; i < l; i++)
				printf("%c", v[i]);
			printf("\n");
		}
		return;
	}

	for (int i = idx; i < c; i++) {
		v.push_back(alpha[i]); // i번째 알파벳을 벡터에 넣고
		bool vowelOrcons = getVowel(alpha[i]); // 자음, 모음인지 판단
		// 다음 알파벳으로 넘어가기 위해 i + 1 해줌
		// 자음 ,모음에 + 1 or + 0해준다
		dfs(i + 1, vow + VOWEL(vowelOrcons), con + CONSONANT(vowelOrcons));
		v.pop_back(); // dfs()를 빠져나오면 맨뒤의 알파벳을 벡터에서 빼주고 다음 반복수행
	}
}

int main(void) {
	cin >> l >> c;
	alpha = vector<char>(c);

	for (int i = 0; i < c; i++)
		cin >> alpha[i];
	
	// 사전식으로 출력하기위해 정렬해줌
	sort(alpha.begin(), alpha.end());

	dfs(0, 0, 0);
}