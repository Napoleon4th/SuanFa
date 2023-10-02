//
// Created on 2023/10/2.
//
#include <cstdio>
const int maxn=100000;

int main(void)
{
    int m,n;
    int num[maxn];
    scanf("%d %d",&m,&n);
    int count=0;
    for(int i=0;i<m;i++){
        while(scanf("%d",&num[count])!=0){
            count++;
        }
        getchar();
        for(int j=count-n+1;j<count;j++){
            num[j-1]=num[j];
        }
        count-=1;
        for(int k=0;k<count;k++){
            printf("%d ",num[k]);
        }
        printf("#");
        printf("\n");
    }
    return 0;
}