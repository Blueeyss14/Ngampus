#include "tree.h"

int main() {
    adrNode root = NULL;
    adrNode _palingKiri;
    adrNode _palingKanan;

    int x[10] ={1,2,3,4,5,6,7,8,9,10};

    for (int i = 0; i < 10; i++) {
        insertNode(root, newNode(x[i]));
    }

    cout << "tampikan data" << endl;
    printInOrder(root);

    cout << "\nPaling Kiri" << endl;
    _palingKiri = palingKiri(root);
    if (_palingKiri != NULL) {
        cout << Info(_palingKiri) << endl;
    } else {
        cout << "gak ada";
    }

    cout << "Paling Kanan" << endl;
    _palingKanan = palingKanan(root);
    if (_palingKanan != NULL) {
        cout << Info(_palingKanan) << endl;
    } else {
        cout << "gak ada";
    }



    return 0;
}