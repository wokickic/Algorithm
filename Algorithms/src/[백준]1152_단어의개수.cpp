#include <iostream>
#include <vector>
using namespace std;

int main(void) {
	int cnt = 0, i = 0;
	int len;
	char arr[1000001];

	scanf("%[^\n]s", arr);
	for (len = 0; arr[len] != NULL; len++);

	if (arr[0] == ' ') i += 1;
	if (arr[len - 1] == ' ') cnt -= 1;

	for (; i < len; i++) {
		if (arr[i] == ' ') cnt++;
	}
	printf("%d\n", cnt + 1);
}