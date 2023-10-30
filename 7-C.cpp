//
// Created on 2023/10/30.
//
#include<cstdio>

const int Max = 100005;
int n,k,ans,arr[Max*3];
int find(int u){return arr[u]==u?u:arr[u]=find(arr[u]);}

int main(void)
{
    int x,y;
    scanf("%d %d",&n,&k);
    for(int i=1;i<n*3;i++){
        arr[i]=i;
    }
    while(k>0){
        scanf("%d %d",&x,&y);
        if(x>n||y>n){
            ans++;
            continue;
        }
        else{
            if(find(x)==find(y)||find(x)==find(y+n)){ans++;}
            else{
                arr[find(x)]=arr[find(y+n+n)];
                arr[find(x+n)]=arr[find(y)];
                arr[find(x+n+n)]= arr[find(y+n)];
            }
        }
        k--;
    }
    printf("%d",ans);
    return 0;
}