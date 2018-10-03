#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

int main(void) {
	int n; cin >> n;
	v = vector<int>(n);

	for (int i = 0; i < n; i++)
		cin >> v[i];


}