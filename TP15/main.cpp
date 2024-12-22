#include <iostream>
#include "Tree.h"
using namespace std;

int main() {
    adrNode root = NULL;

    insertNode_103032300084(root, newNode_103032300084(8));
    insertNode_103032300084(root, newNode_103032300084(9));
    insertNode_103032300084(root, newNode_103032300084(12));
    insertNode_103032300084(root, newNode_103032300084(13));
    insertNode_103032300084(root, newNode_103032300084(15));
    insertNode_103032300084(root, newNode_103032300084(17));
    insertNode_103032300084(root, newNode_103032300084(7));
    insertNode_103032300084(root, newNode_103032300084(6));
    insertNode_103032300084(root, newNode_103032300084(4));

    cout << "Input: ";
    printInOrder_103032300084(root);
    cout << endl;

    int Node[] = {8, 9, 12, 13, 15, 17, 7, 6, 4};
    for (int i = 0; i < 9; i++) {
        adrNode p = newNode_103032300084(Node[i]);
        deleteNode_103032300084(root, p);
        printInOrder_103032300084(root);
        cout << endl;
    }

    cout << "Kosong";
    printInOrder_103032300084(root);
    cout << endl;

    return 0;
}
