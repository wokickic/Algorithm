#include <iostream>
#define MAX 10
#define max(a,b) ((a > b) ? (a) : (b))
using namespace std;

int n;
int num[MAX];
char op[MAX-1];

int cal(int idx){
    int ret = num[idx - 1];
    for(int i = idx; i < n; i+=2){
        if(op[i] == '+') ret += num[i + 1];
        else if(op[i] == '-') ret -= num[i + 1];
        else ret *= num[i + 1];
    }
    return ret;
}

int dfs(int idx){

    return 0;
}

int main (void){
    int ans = 0;

    scanf("%d\n",&n);

    for(int i = 0; i < n; i++){
        if((i % 2) == 1) scanf("%c",&op[i]);
        else scanf("%d",&num[i]);
    }
    ans = cal(1);

    for(int i = 0; i < n; i++){
        ans = max(ans, dfs(i));
    }
    
    printf("%d\n",ans);
}