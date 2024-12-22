#include <iostream>
#include "Tree.h"
using namespace std;

adrNode newNode_103032300084(infotype x){
    adrNode p = new elmNode;
    info(p) = x;
    left(p) = NULL;
    right(p) = NULL;
    return p;
};

void insertNode_103032300084(adrNode &root, adrNode P){
    if (root == NULL) {
        root = P;
    } else if (info(P) < info(root)) {
        insertNode_103032300084(left(root), P);
    } else if (info(P) > info(root)) {
        insertNode_103032300084(right(root), P);
    }
};

void deleteNode_103032300084(adrNode &root, adrNode &P){
    if (root == NULL) {
        cout << "Root Kosong" << endl;
    } else {
        if (info(P) < info(root)) {
            deleteNode_103032300084(left(root), P);
        } else if (info(P) > info(root)) {
            deleteNode_103032300084(right(root), P);
        } else {
            if (left(root) == NULL && right(root) == NULL) {
                root = NULL;
            } else if (left(root) == NULL) {
                root = right(root);
            } else if (right(root) == NULL) {
                root = left(root);
            } else {
                adrNode temp = findMin_103032300084(right(root));
                info(root) = info(temp);
                deleteNode_103032300084(right(root), temp);
            }
        }
    }
}

void printInOrder_103032300084(adrNode root){
    if (root != NULL) {
        printInOrder_103032300084(left(root));
        cout << info(root) << " ";
        printInOrder_103032300084(right(root));
    }
};

adrNode findMin_103032300084(adrNode root){
    if(root == NULL){
        return NULL;
    }else{
        adrNode P = root;
        while (left(P) != NULL){
            P = left(P);
        }
        return P;
    }
}
