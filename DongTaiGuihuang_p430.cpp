//
// Created on 2023/10/1.
//
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
const int maxn=1000;
int num[maxn], dp[maxn];
int main(void){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&num[i]);
    }
    dp[0]=num[0];
    for(int i=1;i<n;i++){
        dp[i]=max(dp[i-1]+num[i],num[i]);
    }
    int k=dp[0];
    for(int i=1;i<n;i++){
        if(k<dp[i]){
            k=dp[i];
        }
    }
    printf("%d\n",k);
    return 0;
}
