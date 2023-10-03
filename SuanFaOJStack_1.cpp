//
// Created on 2023/10/3.
//
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct Node{
    int val;
    struct Node* next;
};

class LinkLst{
private:
    Node *top;
    int len;
public:
    void IniteList(LinkLst &l);
    bool Push(int n);
    bool Pop(int &n);
    bool IsEmpty();
    void MakeEmpty();
    ~LinkLst(){MakeEmpty();};
};

void LinkLst::IniteList(LinkLst &l) {
    top= nullptr;
}

bool LinkLst::Push(int n) {
    if(top == nullptr){
        top = new Node;
        top->val=n;
        len++;
        return true;
    }
    else{
        Node *newnode = new Node;
        if(newnode== nullptr){
            return false;
        }
        newnode->val=n;
        newnode->next=top;
        top=newnode;
        return true;
    }
}

bool LinkLst::Pop(int &n) {
    if(IsEmpty()){
        printf("Wrong! Empty!\n"); return false;
    }
    else{
        Node *temp;
        temp=top;
        top=top->next;
        n=temp->val;
        delete temp;
        return true;
    }
}

bool LinkLst::IsEmpty() {
    if(top== nullptr){
        return true;
    }
    return false;
}

void LinkLst::MakeEmpty() {
    while(top!= nullptr){
        Node *temp;temp=top;
        top=top->next;
        delete temp;
    }
}

int main(void)
{
    int n;
    cin>>n;
    LinkLst l;
    l.IniteList(l);
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(s=="push"){
            int m;
            cin>>m;
            l.Push(m);
        }
        else if(s=="pop"){
            if(l.IsEmpty()){
                printf("-1\n");
            }
            else{
                int m;
                l.Pop(m);
                printf("%d\n",m);
            }
        }
    }
    return 0;
}
