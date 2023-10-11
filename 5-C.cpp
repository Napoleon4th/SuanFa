//
// Created on 2023/10/10.
//
#include<cstdio>
int main(void)
{
    int n;
    scanf("%d",&n);
    int city[n+1][n+1];
    int ans[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&city[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        int max=city[i][0];
        for(int j=1;j<n;j++){
            if(city[i][j]>max){
                max=city[i][j];
            }
        }
        city[i][n]=max;
    }
    for(int i=0;i<n;i++){
        int max=city[0][i];
        for(int j=1;j<n;j++){
            if(city[j][i]>max){
                max=city[j][i];
            }
        }
        city[n][i]=max;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int temp=city[i][n]<city[n][j]?city[i][n]:city[n][j];
            ans[i][j]=temp-city[i][j];
        }
    }
    int ans_all=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans_all+=ans[i][j];
        }
    }
    printf("%d",ans_all);
    return 0;
}