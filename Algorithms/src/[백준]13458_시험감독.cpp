#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main(void) {
	int n, b, c;
	long long int ans = 0;
	cin >> n;
	v = vector<int>(n);
	for (int i = 0; i < v.size(); i++) cin >> v[i];
	cin >> b >> c; // b = �Ѱ���, c = �ΰ�����

	for (int i = 0; i < v.size(); i++) {
		if (v[i] - b < 0) continue; // �������� ��ü�� Ŀ���ϴ� ���
		if ((v[i] - b) % c == 0) ans = ans + ((v[i] - b) / c);
		else ans = ans + (((v[i] - b) / c) + 1);
	}
	// ������ �������� ���� �����ش�.
	printf("%lld\n", ans + n);
}

// ���� Ʋ�����
//
//1
//100
//1000 1