#include <iostream>
#include <algorithm>
#include<cstdio>
using namespace std;
const int maxn=1000;
int dp[maxn][maxn], f[maxn][maxn];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            scanf("%d",&f[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        dp[n][i]=f[n][i];
    }
    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=i;j++){
            dp[i][j]= max(dp[i+1][j],dp[i+1][j+1])+f[i][j];
        }
    }
    printf("%d",dp[1][1]);
    return 0;
}
