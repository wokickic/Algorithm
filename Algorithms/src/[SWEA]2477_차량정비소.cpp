#include <iostream>
#include <vector>
#include <queue>
#define DESTIME 1001
using namespace std;

int n, m, k, rec, rep;
int ans;
int desTime[DESTIME];

typedef struct CUSTOM {
	int rep, rec;
};

typedef struct DESK {
	int processTime;
	int	performaceTime = 0;
	int custom = 0;
	DESK(){}
	bool cmp() {
		if (processTime == performaceTime) return true;
		return false;
	}
};

vector<DESK> reception, repair;
queue<int> recWait, repWait;
vector<CUSTOM> custom;

void goRec() {
	for (int i = 0; i < reception.size(); i++) {
		// i��° â���� ���� ������ ����ð� ����������
		if (reception[i].custom != 0) reception[i].performaceTime++;
		// i��° â���� ���� ����, ���ť�� ����� ������
		// i��° â���� ���� ����, k��° ���� rec�� â����ȣ ����
		else {
			if (!recWait.empty()) {
				reception[i].custom = recWait.front();
				custom[recWait.front()].rec = i + 1;
				recWait.pop();
			}
		}
		// i��° â���� ó���ð�==����ð� �̸� i��° â���� �ִ� ����
		// repWaitť�� �����ϰ�, recWaitť�� ����ϴ� ����� ������ i��°
		// â���� �����ϰ�, ����ð� �ʱ�ȭ
		// �׷��� ������ i��° â���� ���� �����ϱ� 0���� �ʱ�ȭ
		if (reception[i].cmp()) {
			repWait.push(reception[i].custom);
			if (!recWait.empty()) {
				reception[i].custom = recWait.front();
				custom[recWait.front()].rec = i + 1;
				recWait.pop();
			}
			else reception[i].custom = 0;
			reception[i].performaceTime = 0;
		}
	}
}

void goRep(int& finish) {
	for (int i = 0; i < repair.size(); i++) {
		// i��° â���� ���� ������ ����ð� ����������
		if (repair[i].custom != 0) repair[i].performaceTime++;
		// i��° â���� ���� ����, ���ť�� ����� ������
		// i��° â���� ���� ����, k��° ���� rep�� â����ȣ ����
		else {
			if (!repWait.empty()) {
				repair[i].custom = repWait.front();
				custom[repWait.front()].rep = i + 1;
				repWait.pop();
			}
		}
		// i��° â���� ó���ð�==����ð� �̸� finish���� ����ȣ�� ����
		// repWaitť�� ����ϴ� ����� ������ i��°
		// â���� �����ϰ�, ����ð� �ʱ�ȭ
		// �׷��� ������ i��° â���� ���� �����ϱ� 0���� �ʱ�ȭ
		if (repair[i].cmp()) {
			finish -= repair[i].custom;
			if (!repWait.empty()) {
				repair[i].custom = repWait.front();
				custom[repWait.front()].rep = i + 1;
				repWait.pop();
			}
			else repair[i].custom = 0;
			repair[i].performaceTime = 0;
		}
	}
}

int main(void) {
	int T; cin >> T;
	
	for (int t = 1; t <= T; t++) {
		cin >> n >> m >> k >> rec >> rep;
		int finish = 0;
		reception = vector<DESK>(n);
		repair = vector<DESK>(m);
		custom = vector<CUSTOM>(k + 1);

		for (int i = 0; i < DESTIME; i++) desTime[i] = 0;
		ans = 0;
		
		for (int i = 0; i < n; i++) cin >> reception[i].processTime; 
		for (int i = 0; i < m; i++) cin >> repair[i].processTime; 
		for (int i = 0; i < k; i++) {
			int tmp; cin >> tmp;
			desTime[tmp]++;
			// finish�� ��������, ����ȣ�� ������
			finish += (i + 1);
		}
		
		for (int time = 0, cusNum = 0; finish != 0 ; time++) {
			// �湮�ϴ� �ð��뿡 ���� ������ recWaitť�� ����ȣ�� ����
			// time < DESTIME�� ����� ��Ÿ�ӿ��� �ȳ� -> time���� 1001�� �Ѿ for���� ��� ����� 
			while (time < DESTIME && ((desTime[time] -= 1) >= 0))
				recWait.push(++cusNum);

			goRec();
			goRep(finish);
		}

		for (int i = 1; i <= k; i++) {
			if (custom[i].rec == rec && custom[i].rep == rep) ans += i;
		}
		printf("#%d %d\n", t, (ans ? ans : -1));
	}
}