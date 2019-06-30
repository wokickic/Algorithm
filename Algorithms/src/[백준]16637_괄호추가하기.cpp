#include <iostream>
#define MAX 10
using namespace std;

int n;
int num[MAX];
char op[MAX-1];

int cal(){
    
}

int main (void){
    scanf("%d\n",&n);

    for(int i = 0; i < n; i++){
        if((i % 2) == 1) scanf("%c",&op[i]);
        else scanf("%d",&num[i]);
    }
}