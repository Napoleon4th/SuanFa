//
// Created on 2023/10/30.
//
#include <iostream>
#include <string>
#include<cstdlib>

using namespace std;
#define MaxSize 100000;
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

int FindLongest(string str) {
    SqStack<int> s;
    int maxLen = 0;
    int lastIndex = -1;
    s.InitStack(s);
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == 'M') {
            s.Push(s,i);
        } else if (str[i] == 'S') {
            if (!s.IsEmpty(s)) {
                int temp;
                s.Pop(s,temp);
                s.Gettop(s,temp);
                int validLen = i - (s.IsEmpty(s) ? lastIndex : temp);
                maxLen = max(maxLen, validLen);
            } else {
                lastIndex = i;
            }
        }
    }

    return maxLen;
}

int main() {
    string str;
    cin >> str;

    int maxLength = FindLongest(str);

    cout << maxLength << endl;

    return 0;
}
