//
// Created on 2023/10/3.
//
#include<iostream>
using namespace std;

struct Node{
    int id;
    int val;
    int ne;
    struct Node* next;
};

class LinkList{
private:
    int len=0;
public:
    Node*head;
    void IniteList(LinkList &l);
    bool Insert(int id,int data,int ne,Node* n);
    bool Print(Node* n);
};

void LinkList::IniteList(LinkList &l) {
    l.head=new Node;
    l.head->next= nullptr;
}

bool LinkList::Insert(int id, int data,int ne,Node* n) {
    Node* newnode = new Node;
    if(newnode== nullptr){
        cout<<"Wrong!";
        return false;
    }
    newnode->id=id;
    newnode->val=data;
    newnode->ne=ne;
    n->next=newnode;
    newnode->next= nullptr;
    return true;
}

bool LinkList::Print(Node *n) {
    if(n== nullptr){
        cout<<"Wrong!";
        return false;
    }
    cout<<n->id<<' '<<n->val<<' '<<n->ne<<endl;
    return false;
}


int main(void)
{
    LinkList l;
    l.IniteList(l);
    int n,first;
    cin>>n>>first;
    int nodes[2][n];
    int temp_id,temp_data,temp_next;
    for(int i=0;i<n;i++){
        cin>>temp_id>>temp_data>>temp_next;
        nodes[0][temp_id]=temp_data;
        nodes[1][temp_id]=temp_next;
    }
    temp_id=first;
    temp_data=nodes[0][temp_id];
    temp_next=nodes[1][temp_id];
    Node*temp=l.head;
    int count=0;
    while(temp_id!=-1){
        l.Insert(temp_id,temp_data,temp_next,temp);
        temp=temp->next;
        temp_id=temp_next;
        temp_data=nodes[0][temp_id];
        temp_next=nodes[1][temp_id];
        count++;
    }
    Node*temp2=l.head->next;
    while(count!=0){
        l.Print(temp2);
        temp2=temp2->next;
        count--;
    }
    return 0;
}