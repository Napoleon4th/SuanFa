//
// Created on 2023/10/10.
//
#include<iostream>
#include<cstdio>
int main(void)
{
    int n;
    scanf("%d",&n);
    int num[2][n];
    for(int i=0;i<n;i++){
        scanf("%d %d",&num[0][i],&num[1][i]);
    }
    int ans[2][n];
    int ans_count=0;
    int count=0;int fir;int last;int next;int next_last;
    while(count<n-1){
        fir=num[0][count];
        last=num[1][count];
        next=num[0][count+1];
        if(next>last){
            ans[0][ans_count]=fir;
            ans[1][ans_count]=last;
            ans_count++;count++;
        }
        else{
            while(next<=last&&count<n-1){next_last=num[1][count+1];
                if(next_last<=next){
                    count++;
                    next=num[0][count+1];
                }
                else{
                    last=next_last;
                    count++;
                    next=num[0][count+1];
                }
            }
            ans[0][ans_count]=fir;
            ans[1][ans_count]=last;
            ans_count++;count++;
        }
    }
    if(count==n-1){
        ans[0][ans_count]=num[0][count];ans[1][ans_count]=num[1][count];ans_count++;
    }
    for(int i=0;i<ans_count;i++){
        printf("%d %d\n",ans[0][i],ans[1][i]);
    }
    return 0;
}
