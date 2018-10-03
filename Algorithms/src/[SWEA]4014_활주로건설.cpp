#include <iostream>
#include <vector>
using namespace std;

int n, x, ans;
vector<vector<int>> map, visitRow, visitCol;


void checkRow() {
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (map[i][j] == map[i][j - 1]) continue; // �����̶� ������ �Ѿ
			
			int diff = map[i][j] - map[i][j - 1];
			if (diff > 1 || diff < -1) { ans--; break; } // ���̰� 2�̻� ���� ���� ��ġ �Ұ���
			
			// Ȱ�ַ� �Ǽ��� �������� �Ұ������� �����ϴ� ����
			bool flag = false;
			// ������ ��ū���
			if (diff == -1) {
				int comp = map[i][j]; // �� ����

				for (int k = j, l = 0; l < x; l++, k++) {
					if (k >= 0 && k < n) { // ����üũ
						// map[i][k]�� ���̰� �Ȱ���, ���� Ȱ�ַ� �Ǽ� ���Ѱ��
						// Ȱ�ַ� �Ǽ����ְ� ���� �ݺ�
						if (map[i][k] == comp && !visitRow[i][k]) { visitRow[i][k] = 1; continue; }
						else { flag = true; break; }// ���̰� �ٸ��ų�, �̹� Ȱ�ַΰ� �Ǽ��Ǿ��ִ°��
					}
					else { flag = true; break; }// ���� ����� Ȱ�ַ� �Ǽ� ����
				}
				if (flag) { ans--; break; }// flag�� true�� Ȱ�ַ� �Ǽ� �����ؼ� �����ٷ� ����
				// Ȱ�ַΰ� �ϼ��Ǹ� ���� ���� x��ŭ j�� �̵������ش�.
				else j = j + x - 1;
			}
			
			// �������� ��ū���
			else {
				int comp = map[i][j - 1]; // �� ����
				for (int k = j - 1, l = 0; l < x; l++, k--) {
					if (k >= 0 && k < n) { //����üũ
						if (map[i][k] == comp && !visitRow[i][k]) { visitRow[i][k] = 1; continue; }
						else { flag = true; break; } // ���̰� �ٸ��ų�, �̹� Ȱ�ַΰ� �Ǽ��Ǿ��ִ� ���
					}
					else { flag = true; break; } // ���� ����� Ȱ�ַ� �Ǽ� ����
				}
				if (flag) { ans--; break; } // flag�� true�� Ȱ�ַ� �Ǽ� �����ؼ� ���� �ٷ� ����
			}
		}
	}
}

void checkCol() {
	for (int j = 0; j < n; j++) {
		for (int i = 1; i < n; i++) {
			if (map[i][j] == map[i - 1][j]) continue; // �����̶� ������ �Ѿ

			int diff = map[i][j] - map[i - 1][j];
			if (diff > 1 || diff < -1) { ans--; break; } // ���̰� 2�̻� ���� ���� ��ġ �Ұ���

			bool flag = false;
			// ������ ��ū���
			if (diff == -1) {
				int comp = map[i][j]; // �� ����

				for (int k = i, l = 0; l < x; l++, k++) {
					if (k >= 0 && k < n) { // ����üũ
										   // map[k][j]�� ���̰� �Ȱ���, ���� Ȱ�ַ� �Ǽ� ���Ѱ��
										   // Ȱ�ַ� �Ǽ����ְ� ���� �ݺ�
						if (map[k][j] == comp && !visitCol[k][j]) { visitCol[k][j] = 1; continue; }
						else { flag = true; break; }// ���̰� �ٸ��ų�, �̹� Ȱ�ַΰ� �Ǽ��Ǿ��ִ°��
					}
					else { flag = true; break; }// ���� ����� Ȱ�ַ� �Ǽ� ����
				}
				if (flag) { ans--; break; }// flag�� true�� Ȱ�ַ� �Ǽ� �����ؼ� �����ٷ� ����
				else i = i + x - 1;
			}

			// �Ʒ����� ��ū���
			else {
				int comp = map[i - 1][j]; // �� ����
				for (int k = i - 1, l = 0; l < x; l++, k--) {
					if (k >= 0 && k < n) { //����üũ
						if (map[k][j] == comp && !visitCol[k][j]) { visitCol[k][j] = 1; continue; }
						else { flag = true; break; } // ���̰� �ٸ��ų�, �̹� Ȱ�ַΰ� �Ǽ��Ǿ��ִ� ���
					}
					else { flag = true; break; } // ���� ����� Ȱ�ַ� �Ǽ� ����
				}
				if (flag) { ans--; break; } // flag�� true�� Ȱ�ַ� �Ǽ� �����ؼ� ���� �ٷ� ����
			}
		}
	}
}

int main(void) {
	int T; cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> n >> x;
		//  ����, ���� �湮üũ�ϴ� �迭����
		visitRow = visitCol = map = vector<vector<int>>(n, vector<int>(n, 0));

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> map[i][j];

		// Ȱ�ַθ� �Ǽ��� �� �ִ� �ִ��� ���
		ans = n * 2;
		checkRow();
		checkCol();
		printf("#%d %d\n", t, ans);
	}
}