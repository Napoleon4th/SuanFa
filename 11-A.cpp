//
// Created on 2023/11/22.
//
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
//定义队列
template<class T>
#define Maxsize 100000
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
    ~Queue() {
        if (queue) {
            free(queue);
            queue = nullptr;
        }
    }
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
    q.queue = nullptr;
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
//定义树
struct BiTNode{
    char value;
    struct BiTNode *lchile, *rchild,*parent;
};

class BinaryTree{
public:
    BiTNode *root= nullptr;
public:
    BiTNode* CreatTree(const char nodes[], int size);
    bool Iscousins(BiTNode*n,char x,char y);
};

BiTNode *BinaryTree::CreatTree(const char *nodes, int size) {
    if (size == 0 || nodes[0] == '#') {
        return nullptr;
    }
    root = new BiTNode;
    root->value=nodes[0];
    Queue<BiTNode*> q;
    q.InitQueue(q);
    q.EnQueue(q,root);
    for(int i=1;i<size;i+=2){
        BiTNode*current;
        q.DeQueue(q,current);
        if (nodes[i] != '#') {
            current->lchile = new BiTNode;
            current->lchile->value=nodes[i];
            current->lchile->parent = current;
            q.EnQueue(q,current->lchile);
        }

        if (i + 1 < size && nodes[i + 1] != '#') {
            current->rchild = new BiTNode;
            current->rchild->value=nodes[i+1];
            current->rchild->parent = current;
            q.EnQueue(q,current->rchild);
        }
    }return root;
}

bool BinaryTree::Iscousins(BiTNode *n, char x, char y) {
    if(x==y)
        return false;
    Queue<BiTNode*> q2;
    q2.InitQueue(q2);
    q2.EnQueue(q2,n);
    int Current=1;int Next=0;
    BiTNode* xParent= nullptr;
    BiTNode* yParent= nullptr;
    while (!q2.IsEmpty(q2)){
        BiTNode* temp;
        q2.DeQueue(q2,temp);
        Current--;
        BiTNode* templ=temp->lchile;
        if(templ){
            if(templ->value==x){
                xParent=temp;
            } else if(templ->value==y){
                yParent=temp;
            }
            q2.EnQueue(q2,templ);
            Next++;
        }
        BiTNode* tempr=temp->rchild;
        if(tempr){
            if(tempr->value==x){
                xParent=tempr;
            }else if (tempr->value==y){
                yParent=tempr;
            }
            q2.EnQueue(q2,tempr);
            Next++;
        }
        if(xParent && yParent)
        {
            return xParent != yParent;
        }
        if(Current==0){
            if(xParent || yParent)
            {
                return false;
            }
            Current=Next;
            Next=0;
        }
    }
    return false;
}

int main(void)
{
    char *arr = new char[10000];
    int size=0;
    char temp;
    while (cin >> temp){
        arr[size++]=temp;
    }
    char x,y;
    scanf("%c",&x);
    scanf("%c",&y);
    BinaryTree Tree;
    Tree.root=Tree.CreatTree(arr,size);
    cout << (Tree.Iscousins(Tree.root, x, y) ? "true" : "false");
    return 0;
}