
#include "tree.h"

adrNode newNode(infotype data) {
    adrNode p = new elmNode;
    Info(p) = data;
    Right(p) = NULL;
    Left(p) = NULL;
    return p;
}

void insertNode(adrNode &root, adrNode p) {
    if (root == NULL) {
        root = p;
    } else if (Info(p) < Info(root)) {
        insertNode(Left(root),p);
    } else if (Info(p) > Info(root)) {
        insertNode(Right(root),p);
    }
}

void printInOrder(adrNode root) {
    if (root != NULL) {
        printInOrder(Left(root));
        cout << Info(root) << " ";
        printInOrder(Right(root)); 
    }
}

adrNode palingKiri(adrNode root) {
    if (root !=NULL) {
        if (Left(root) == NULL) {
            return root;
        }
        return palingKiri(Left(root));
    }
    return NULL;
}

adrNode palingKanan(adrNode root) {
    if (root !=NULL) {
        if (Right(root) == NULL) {
            return root;
        }
        return palingKanan(Right(root));
    }
    return NULL;
}