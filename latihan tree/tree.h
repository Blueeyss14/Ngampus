#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <iostream>
using namespace std;

#define Left(P) P->Left
#define Right(P) P-> Right
#define Info(P) P-> Info
typedef struct elmNode* adrNode;
typedef int infotype;

struct elmNode {
    infotype Info;
    adrNode Right;
    adrNode Left;
};

adrNode newNode(infotype data);
void insertNode(adrNode &root, adrNode p);
void printInOrder(adrNode root);
adrNode palingKiri(adrNode root);
adrNode palingKanan(adrNode root);
#endif // TREE_H_INCLUDED