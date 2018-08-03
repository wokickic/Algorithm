#include <iostream>
#include <vector>
#include <algorithm>
#define VOWEL(a) ((a) ? (1) : (0))
#define CONSONANT(a) ((a) ? (0) : (1))

using namespace std;;

vector<char> alpha, v;
char vowel[] = { 'a','e','i','o','u' };
int l, c;

// a�� �����̸� true, �ƴϸ� fals����
bool getVowel(char a) {
	for (int i = 0; i < 5; i++) if (a == vowel[i]) return true;
	return false;
}

void dfs(int idx, int vow, int con) { // ����, ���� ����
	if (v.size() == l) {
		// ������ ũ�Ⱑ l�� ������ ���
		if (vow >= 1 && con >= 2) {
			// ������ 1�� �̻�, ������ 2�� �̻��̸� ���
			for (int i = 0; i < l; i++)
				printf("%c", v[i]);
			printf("\n");
		}
		return;
	}

	for (int i = idx; i < c; i++) {
		v.push_back(alpha[i]); // i��° ���ĺ��� ���Ϳ� �ְ�
		bool vowelOrcons = getVowel(alpha[i]); // ����, �������� �Ǵ�
		// ���� ���ĺ����� �Ѿ�� ���� i + 1 ����
		// ���� ,������ + 1 or + 0���ش�
		dfs(i + 1, vow + VOWEL(vowelOrcons), con + CONSONANT(vowelOrcons));
		v.pop_back(); // dfs()�� ���������� �ǵ��� ���ĺ��� ���Ϳ��� ���ְ� ���� �ݺ�����
	}
}

int main(void) {
	cin >> l >> c;
	alpha = vector<char>(c);

	for (int i = 0; i < c; i++)
		cin >> alpha[i];
	
	// ���������� ����ϱ����� ��������
	sort(alpha.begin(), alpha.end());

	dfs(0, 0, 0);
}