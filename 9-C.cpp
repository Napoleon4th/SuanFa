//
// Created on 2023/11/11.
//
#include<iostream>
#include<cstdlib>
#include<iostream>
#include<cstdio>
using namespace std;
struct BiTNode{
    char value;
    struct BiTNode *lchile, *rchild;
};

class BinaryTree{
public:
    BiTNode *root= nullptr;
public:
    BiTNode* CreatTree();
    void PostOrder(BiTNode *n);
};


BiTNode *BinaryTree::CreatTree() {
    char temp;
    scanf("%c",&temp);
    BiTNode *node= nullptr;
    if(temp=='@'){node= nullptr;}
    else{
        node=(BiTNode*) malloc(sizeof(BiTNode));
        node->value=temp;
        node->lchile=CreatTree();
        node->rchild=CreatTree();
    }
    return node;
}

void BinaryTree::PostOrder(BiTNode *n) {
    if(n!= nullptr){
        PostOrder(n->lchile);
        PostOrder(n->rchild);
        cout<<n->value;
    }

}


int main(void)
{
    BinaryTree tree;
    tree.root=tree.CreatTree();
    tree.PostOrder(tree.root);
    return 0;
}