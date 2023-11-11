//
// Created on 2023/10/31.
//
#include<iostream>
#include<cstdlib>
#include<iostream>
#include<cstdio>
using namespace std;
struct BiTNode{
    int value;
    struct BiTNode *lchile, *rchild;
};

class BinaryTree{
public:
    BiTNode *root= nullptr;
public:
    void SearchInOrder(BiTNode* node,BiTNode *n,int tag);
    int Vist(BiTNode* n);
    BiTNode* CreatTree();
    BiTNode* Find(BiTNode* node, BiTNode* n, BiTNode* m);
};

int BinaryTree::Vist(BiTNode* n) {
    if(n!= nullptr){
        return n->value;
    }
    return -1;
}


void BinaryTree::SearchInOrder(BiTNode *node,BiTNode* n,int tag)
{
    if(node!= nullptr){
        SearchInOrder(node->lchile,n,tag);
        if(node->value==tag){
            n=node;
        }
        SearchInOrder(node->rchild,n,tag);
    }
}

BiTNode *BinaryTree::CreatTree() {
    int temp;
    scanf("%d",&temp);
    BiTNode *node= nullptr;
    if(temp==-1){node= nullptr;}
    else{
        node=(BiTNode*) malloc(sizeof(BiTNode));
        node->value=temp;
        node->lchile=CreatTree();
        node->rchild=CreatTree();
    }
    return node;
}

BiTNode *BinaryTree::Find(BiTNode *node, BiTNode *n, BiTNode *m) {
    if(!node)return nullptr;
    if(node->value==n->value||node->value==m->value)return node;
    BiTNode *left= Find(node->lchile,n,m);
    BiTNode *right= Find(node->rchild,n,m);
    if(left&&right)return node;
    return left?left:right;
}


int main(void)
{
    BinaryTree tree;
    tree.root=tree.CreatTree();
    int n,m;
    scanf("%d %d",&n,&m);
    //printf("%d %d",n,m);
    BiTNode *temp1= nullptr;
    BiTNode *temp2= nullptr;
    BiTNode *t1;
    BiTNode *t2;
    t1=tree.root;
    t2=tree.root;
    tree.SearchInOrder(t1,temp1,n);
    tree.SearchInOrder(t2,temp2,m);
    BiTNode *ans;
    ans=tree.Find(tree.root,temp1,temp2);
    int a = tree.Vist(ans);
    cout<<a;
    return 0;
}


