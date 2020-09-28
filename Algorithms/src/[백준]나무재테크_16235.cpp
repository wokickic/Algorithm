#include <stdio.h>
#include <string.h>
#include "test.h"


int main(void) {
	TEST t;
	printf("%d %d\n", t.a, t.b);
}

//int main(void) {
//	char a[] = { "1234@naver.com;23423@nate.com;234234@daum.net" };
//	char *p;
//	char *b[100];
//	char tmp[1000];
//
//	strcpy(tmp, a);
//	p = strtok(tmp, ";");
//
//	
//	int i = 0;
//	while (p != NULL) {
//		b[i++] = p;
//		p = strtok(NULL, ";");
//	}
//
//	printf("a : %s\n", a);
//	puts(tmp);
//	for (int idx = 0; idx < i; idx++) {
//		printf("b[idx] : %s\n", b[idx]);
//	}
//}