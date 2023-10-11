#include<iostream>
#include<cstdio>
int main(void)
{
    int num[100000];
    int n;
    int count=0;
    while(scanf("%d", &n) == 1){
        num[count]=n;
        count++;
    }
    int ans[count];
    int temp1;
    for(int i=0;i<count;i++){
        int flag=0;
        temp1=num[i];
        for(int j=i+1;j<count;j++){
            if(num[j]>temp1){
                ans[i]=j-i;
                flag=1;
                break;
            }
        }
        if(flag==0){
            ans[i]=0;
        }
    }
    for(int i=0;i<count;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}