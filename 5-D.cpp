//
// Created on 2023/10/11.
//
#include <iostream>
using namespace std;

const int Max_Fish = 100005;
int Fish_loc[2][Max_Fish];
int Count;
bool Fish_Eaten[Max_Fish];

bool In_Same_Line(int x,int y)
{
    if(Fish_loc[0][x]==Fish_loc[0][y]||Fish_loc[1][x]==Fish_loc[1][y])
        return true;
    else
        return false;
}

void DFS(int n){
    Fish_Eaten[n]= true;
    for(int i=0;i<Count;i++){
        if(In_Same_Line(i,n) && !Fish_Eaten[i]){
            DFS(i);
        }
    }
}

int main(void)
{
    int n;
    cin>>n;
    Count=n;
    for(int i=0;i<Count;i++){
        cin>>Fish_loc[0][i];
        cin>>Fish_loc[1][i];
    }
    int num=0;
    for(int i=0;i<Count;i++){
        if(!Fish_Eaten[i])
        {DFS(i);
            num++;}
    }
    cout<<Count-num;
    return 0;
}