//
// Created on 2023/11/11.
//
#include<iostream>
#include<cstdlib>
#include<string>
#define MaxSize 10000;
using namespace std;
template<class T>
class SqStack{
protected:
    T *stack;
    int top;
    int size;
public:
    void InitStack(SqStack<T> &s);
    bool IsEmpty(SqStack<T> &s);
    bool IsFull(SqStack<T> &s);
    bool Push(SqStack<T> &s, T x);
    bool Pop(SqStack<T> &s, T &x);
    bool Gettop(SqStack<T> &s, T &x);
};

template<class T>
void SqStack<T>::InitStack(SqStack<T> &s)
{
    s.top=-1;
    s.size=MaxSize;
    s.stack=(T*)malloc(s.size* sizeof(T));
}

template<class T>
bool SqStack<T>::IsEmpty(SqStack<T> &s)
{
    if(s.top==-1)return true;
    return false;
}

template<class T>
bool SqStack<T>::Push(SqStack<T> &s, T x)
{
    if(s.top>=s.size-1){
        return false;
    }
    s.stack[++s.top]=x;
    return true;
}

template<class T>
bool SqStack<T>::Pop(SqStack<T> &s, T &x)
{
    if(s.top==-1){
        return false;
    }
    x = s.stack[s.top--];
    return true;
}

template<class T>
bool SqStack<T>::Gettop(SqStack<T> &s, T &x)
{
    if(s.top==-1){
        return false;
    }
    x = s.stack[s.top];
    return true;
}

template<class T>
bool SqStack<T>::IsFull(SqStack<T> &s)
{
    if(s.top+1>=s.size){
        return true;
    }
    return false;
}

int main(void)
{
    SqStack<char> s;
    s.InitStack(s);
    string n;
    cin>>n;
    int num=n.length()-1;
    while(num!=0){
        if(n[num]==','){
            num--;
        }
        else if(n[num]==')'){
            if(s.IsEmpty(s)){
                s.Push(s,n[num]);
                num--;
            }
            else if(!s.IsEmpty(s)){
                s.Push(s,n[num]);
                num--;
            }
        }
        else if (n[num]=='('){
            char temp;
            s.Gettop(s,temp);
            if(temp==')'&&n[num+1]==')'){
                cout<<'@';
                num--;
            } else{
                s.Pop(s,temp);
                num--;
            }
        } else{
            cout<<n[num];
            num--;
        }
    }
    return 0;
}