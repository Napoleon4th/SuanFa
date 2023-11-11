//
// Created on 2023/11/10.
//
#include <iostream>
using namespace std;
template<class T>
#define Maxsize 10000;
class Queue{
protected:
    T *queue;
    int front, rear;
    int size;
public:
    void InitQueue(Queue<T> &q);
    bool IsEmpty(Queue<T> &q);
    bool EnQueue(Queue<T> &q,T x);
    bool DeQueue(Queue<T> &q,T &x);
    bool GetTop(Queue<T> &q,T &x);
};

template<class T>
bool Queue<T>::GetTop(Queue<T> &q, T &x) {
    if(q.rear==q.front)return false;
    x=q.queue[q.front];
    return true;
}

template<class T>
void Queue<T>::InitQueue(Queue<T> &q)
{
    q.front=q.rear=0;
    q.size=Maxsize;
    q.queue=(T*)malloc(size*sizeof(T));
}
template<class T>
bool Queue<T>::IsEmpty(Queue<T> &q)
{
    if(q.rear==q.front){
        return true;
    }
    else
        return false;
}

template<class T>
bool Queue<T>::EnQueue(Queue<T> &q, T x)
{
    if((q.rear+1)%size==q.front) return false;
    q.queue[q.rear]=x;
    q.rear=(q.rear+1)%size;
    return true;
}

template<class T>
bool Queue<T>::DeQueue(Queue<T> &q, T &x)
{
    if(q.rear==q.front)return false;
    x=q.queue[q.front];
    q.front=(q.front+1)%size;
    return true;
}


string predictWinner(string senate) {
    int n = senate.size();

    Queue<int> radiant, dire;
    radiant.InitQueue(radiant);
    dire.InitQueue(dire);

    for (int i = 0; i < n; ++i) {
        if (senate[i] == 'R') {
            radiant.EnQueue(radiant,i);
        } else {
            dire.EnQueue(dire,i);
        }
    }

    while (!radiant.IsEmpty(radiant) && !dire.IsEmpty(dire)) {
        int r_index;radiant.GetTop(radiant,r_index);
        int d_index;dire.GetTop(dire,d_index);
        int temp;
        radiant.DeQueue(radiant,temp);
        dire.DeQueue(dire,temp);

        if (r_index < d_index) {
            radiant.EnQueue(radiant,r_index + n);
        } else {
            dire.EnQueue(dire,d_index + n);
        }
    }

    return radiant.IsEmpty(radiant) ? "Dire" : "Radiant";
}

int main() {
    string senate;
    cin >> senate;

    string winner = predictWinner(senate);

    cout << winner << endl;

    return 0;
}


