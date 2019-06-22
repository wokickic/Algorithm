#include<stdio.h>

int main(void) {

	int arr[] = {1,2,3,4};
	int* parr = arr;

	printf("%d %d\n", arr, parr);

	printf("%d\n", ++arr[0]);
	printf("%d\n", ++parr);
	printf("%d\n", (*parr)++);
}