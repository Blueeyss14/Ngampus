#include "list.h"
#include <iostream>

using namespace std;

int main() {
    List L;
    infotype input;
    address P;

    //1
    createList(L);
    //2
    cout << "angka pertama: ";
    cin >> input;

    //3
    P = allocate(input);

    //4
    insertFirst(L, P);

    //5
    printInfo(L);

    //6
    cout << "angka kedua: ";
    cin >> input;

    P = allocate(input);
    insertFirst(L, P);
    printInfo(L);

    //7
    cout << "angka ketiga: ";
    cin >> input;

    P = allocate(input);
    insertFirst(L, P);


    printInfo(L);

    return 0;
}
