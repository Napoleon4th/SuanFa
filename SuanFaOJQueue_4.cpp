//
// Created on 2023/10/3.
//
#include<iostream>
#include<cstdio>
using namespace std;
struct Node{
    int val;
    struct Node* next;
};
class LinkedQueue{
private:
    Node *head, *rear;
public:
    void InitQueue(LinkedQueue &l);
    bool Push(int n);
    bool Pop(int &n);
    bool IsEmpty();
    void MakeEmpty();
    bool GetTop(int &n);
    ~LinkedQueue(){MakeEmpty();};
};

void LinkedQueue::InitQueue(LinkedQueue &l) {
    head=rear=new Node;
    head->next= nullptr;
}

bool LinkedQueue::Push(int n) {
    Node *newnode = new Node;
    if(newnode== nullptr){
        return false;
    }
    newnode->val=n;
    rear->next=newnode;
    rear=newnode;
    return true;
}

bool LinkedQueue::Pop(int &n) {
    if(head==rear){
        cout<<"Empty!";
        return false;
    }
    else{
        Node *temp=head->next;
        n=temp->val;
        head->next=temp->next;
        if(rear==temp){
            rear=head;
        }
        delete temp;
        return true;
    }
}

bool LinkedQueue::IsEmpty() {
    if(head==rear){
        return true;
    }
    return false;
}

void LinkedQueue::MakeEmpty() {
    int m;
    while(!IsEmpty()){
        Pop(m);
    }
}

bool LinkedQueue::GetTop(int &n) {
    if(head==rear){
        return true;
    }
    else{
        n=head->next->val;
        return true;
    }
}

int main(void)
{
    int n;
    cin>>n;
    LinkedQueue l1;
    LinkedQueue l2;
    int count=0;
    l1.InitQueue(l1);l2.InitQueue(l2);
    for(int i=0;i<n;i++){
        int m;
        scanf("%d",&m);l1.Push(m);
    }
    for(int i=0;i<n;i++){
        int m;
        scanf("%d",&m);l2.Push(m);
    }
    while(!l1.IsEmpty()&&!l2.IsEmpty()){
        int m1,m2;
        l1.GetTop(m1);l2.GetTop(m2);
        if(m1==m2){
            l1.Pop(m1);l2.Pop(m2);
            count++;
        }
        else{
            l2.Pop(m2);
            l2.Push(m2);
            count++;
        }
    }
    cout<<count;
    return 0;
}