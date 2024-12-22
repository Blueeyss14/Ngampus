#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include <iostream>

#define info(P) P->info
#define left(P) P->left
#define right(P) P->right

using namespace std;

typedef struct elmNode *adrNode;
typedef int infotype;

struct elmNode {
    infotype info;
    adrNode left;
    adrNode right;
};

adrNode newNode_103032300084(infotype x);
void insertNode_103032300084(adrNode &root, adrNode P);
void deleteNode_103032300084(adrNode &root, adrNode &P);
void printInOrder_103032300084(adrNode root);
adrNode findMin_103032300084(adrNode root);

#endif // TREE_H_INCLUDED
