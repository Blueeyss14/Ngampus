#include "tree.h"
using namespace std;

adrNode newNode_103032300084(infotype x) {
    adrNode p = new elmNode;
    Info(p) = x;
    Left(p) = NULL;
    Right(p) = NULL;
}

void insertNode_103032300084(adrNode &root, adrNode p) {
    if (root == NULL) {
        root = p;
    } else if (Info(p) < Info(root)) {
        insertNode_103032300084(Left(root), p);
    } else if (Info(p) > Info(root)) {
        insertNode_103032300084(Right(root), p);
    }
}

void printInOrder_103032300084(adrNode root) {
    if (root != NULL) {
        printInOrder_103032300084(Left(root));
        cout << Info(root) << " ";
        printInOrder_103032300084(Right(root));
    }
}

adrNode mostLeftNode_103032300084(adrNode root) {
    if (root != NULL) {
        if (Left(root) == NULL) {
            return root;
        }
        return mostLeftNode_103032300084(Left(root));
    }
    return NULL;
}

adrNode mostRightNode_103032300084(adrNode root) {
    if (root != NULL) {
        if (Right(root) == NULL) {
            return root;
        }
        return mostRightNode_103032300084(Right(root));
    }
    return NULL;
}
