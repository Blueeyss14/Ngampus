#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#define Info(P) P->Info
#define Left(P) P->Left
#define Right(P) P->Right

#include <iostream>
using namespace std;

typedef struct elmNode *adrNode;
typedef int infotype;

struct elmNode {
    infotype Info;
    adrNode Left;
    adrNode Right;
};

adrNode newNode_103032300084(infotype x);
void insertNode_103032300084(adrNode &root, adrNode p);
void printInOrder_103032300084(adrNode root);
adrNode mostLeftNode_103032300084(adrNode root);
adrNode mostRightNode_103032300084(adrNode root);

#endif // TREE_H_INCLUDED
