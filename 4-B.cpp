//
// Created on 2023/10/2.
//
#include <iostream>
#include<cstdlib>
#define MaxSize 100;
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
    int Gettop(SqStack<T> &s, T &x);
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
int SqStack<T>::Gettop(SqStack<T> &s, T &x)
{
    if(s.top==-1){
        return -1;
    }
    x = s.stack[s.top];
    return x;
}

template<class T>
bool SqStack<T>::IsFull(SqStack<T> &s)
{
    if(s.top+1>=s.size){
        return true;
    }
    return false;
}

using namespace std;

bool isPossiblePopSequence(int n, int sequence[]) {
    SqStack<int> st;
    st.InitStack(st);
    int index = 0;
    int temp;
    for (int i = 1; i <= n; ++i) {
        st.Push(st,i);

        while (!st.IsEmpty(st) && index < n && st.Gettop(st,temp) == sequence[index]) {
            st.Pop(st,temp);
            ++index;
        }
    }

    return st.IsEmpty(st);
}

int main() {
    int n;
    cin >> n;
    int sequence[1000];

    for (int i = 0; i < n; ++i) {
        cin >> sequence[i];
    }

    bool result = isPossiblePopSequence(n, sequence);
    cout << (result ? "True" : "False") << endl;

    return 0;
}