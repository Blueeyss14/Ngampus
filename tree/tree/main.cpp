#include <iostream>

using namespace std;
#include "tree.h"

int main()
{
    adrNode root = NULL;
    adrNode palingKiri;
    adrNode palingKanan;

    insertNode_103032300084(root, newNode_103032300084(4));
    insertNode_103032300084(root, newNode_103032300084(6));
    insertNode_103032300084(root, newNode_103032300084(7));
    insertNode_103032300084(root, newNode_103032300084(8));
    insertNode_103032300084(root, newNode_103032300084(9));
    insertNode_103032300084(root, newNode_103032300084(12));
    insertNode_103032300084(root, newNode_103032300084(13));
    insertNode_103032300084(root, newNode_103032300084(15));
    insertNode_103032300084(root, newNode_103032300084(17));

    cout << "Menampilkan Urutannya: " << endl;
    printInOrder_103032300084(root);

    cout << "\nMenampilkan Paling Kiri: " << endl;
    palingKiri = mostLeftNode_103032300084(root);
    if (palingKiri != NULL) {
        cout << Info(palingKiri) << endl;
    } else {
        cout << "Kosong" << endl;
    }

    cout << "\nMenampilkan Paling Kanan: " << endl;
    palingKanan = mostRightNode_103032300084(root);
    if (palingKanan != NULL) {
        cout << Info(palingKanan) << endl;
    } else {
        cout << "Kosong" << endl;
    }

    return 0;
}
