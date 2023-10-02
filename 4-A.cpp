//
// Created on 2023/10/2.
//
#include<iostream>
#include<cstdio>

struct Node{
    int value;
    struct Node* next;
    struct Node* first;
};

class LinkedList{
public:
    int size;
    Node *head;
public:
    void InitList(LinkedList &l,int m);
    void Printvalue(Node* n);
    void Delete(LinkedList &l,Node* n);
};

void LinkedList::InitList(LinkedList &l,int m) {
    if (m <= 0) {
        exit(0);
    }
    l.head = (Node *) malloc(sizeof(Node));
    l.head->value = 1;
    l.head->first = l.head;
    l.head->next = l.head;
    Node *temp = l.head;
    if(m>1){
        for (int i = 2; i <= m; i++) {
            Node *newNode = (Node *) malloc(sizeof(Node));
            newNode->value = i;
            temp->next = newNode;
            newNode->first = temp;
            newNode->next = l.head;
            l.head->first = newNode;
            temp = newNode;
        }
    }
    l.size=m;
}

void LinkedList::Printvalue(Node *n) {
    printf("%d ",n->value);
}

void LinkedList::Delete(LinkedList &l,Node *n) {
    Node *temp1=n->next;
    Node *temp2=n->first;
    temp1->first=temp2;
    temp2->next=temp1;
    l.size--;
    free(n);
}

int main(void)
{
    int n,k,m;
    scanf("%d %d %d",&n,&m,&k);
    LinkedList List;
    List.InitList(List,n);
    Node *temp1=List.head;
    while(temp1->value!=k){
        temp1=temp1->next;
    }
    int count1=1;
    while(List.size>1){
        if(count1!=m){
            temp1=temp1->next;
            count1++;
        }
        else if(count1==m){
            List.Printvalue(temp1);
            Node* temp1_1=temp1;
            temp1=temp1->next;
            List.Delete(List,temp1_1);
            count1=1;
        }
    }
    printf("%d",temp1->value);
    printf("\n");

    LinkedList List2;
    List2.InitList(List2,n);
    Node *temp2=List2.head;
    while(temp2->value!=k){
        temp2=temp2->first;
    }
    int count2=1;
    while(List2.size>1){
        if(count2!=m){
            temp2=temp2->first;
            count2++;
        }
        else if(count2==m){
            List2.Printvalue(temp2);
            Node* temp1_1=temp2;
            temp2=temp2->first;
            List2.Delete(List2,temp1_1);
            count2=1;
        }
    }
    printf("%d",temp2->value);
    //printf("\n");
    return 0;
}
