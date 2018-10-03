#include <iostream>
#include <vector>
using namespace std;

int n, q, x;
typedef struct checkPoint {
	int y, x;
	checkPoint() {}
	checkPoint(int y_, int x_) : y(y_), x(x_) {}
};

vector<checkPoint> cp;

int main(void) {
	cin >> n >> q;
	
	for (int i = 0; i < n; i++) {
		int in1, in2; cin >> in1 >> in2;
		cp.push_back(checkPoint(in1, in2));
	}

	for (int i = 0; i < q; i++) {
		int start, end; cin >> start >> end >> x;
		vector<bool> visit(n, false);

	}
}