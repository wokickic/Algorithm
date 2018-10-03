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
		// i번째 창구에 고객이 있으면 수행시간 증가시켜줌
		if (reception[i].custom != 0) reception[i].performaceTime++;
		// i번째 창구에 고객이 없고, 대기큐에 사람이 있으면
		// i번째 창구에 고객을 저장, k번째 고객의 rec에 창구번호 저장
		else {
			if (!recWait.empty()) {
				reception[i].custom = recWait.front();
				custom[recWait.front()].rec = i + 1;
				recWait.pop();
			}
		}
		// i번째 창구의 처리시간==수행시간 이면 i번째 창구에 있는 고객을
		// repWait큐에 저장하고, recWait큐에 대기하는 사람이 있으면 i번째
		// 창구에 저장하고, 수행시간 초기화
		// 그렇지 않으면 i번째 창구에 고객이 없으니까 0으로 초기화
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
		// i번째 창구에 고객이 있으면 수행시간 증가시켜줌
		if (repair[i].custom != 0) repair[i].performaceTime++;
		// i번째 창구에 고객이 없고, 대기큐에 사람이 있으면
		// i번째 창구에 고객을 저장, k번째 고객의 rep에 창구번호 저장
		else {
			if (!repWait.empty()) {
				repair[i].custom = repWait.front();
				custom[repWait.front()].rep = i + 1;
				repWait.pop();
			}
		}
		// i번째 창구의 처리시간==수행시간 이면 finish에서 고객번호를 빼줌
		// repWait큐에 대기하는 사람이 있으면 i번째
		// 창구에 저장하고, 수행시간 초기화
		// 그렇지 않으면 i번째 창구에 고객이 없으니까 0으로 초기화
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
			// finish는 종료조건, 고객번호를 더해줌
			finish += (i + 1);
		}
		
		for (int time = 0, cusNum = 0; finish != 0 ; time++) {
			// 방문하는 시간대에 고객이 있으면 recWait큐에 고객번호를 삽입
			// time < DESTIME를 해줘야 런타임에러 안남 -> time값이 1001을 넘어도 for문은 계속 수행됨 
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