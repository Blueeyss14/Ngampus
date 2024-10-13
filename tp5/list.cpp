#include <iostream>
#include "list.h"
using namespace std;


void createList_103032300084(List &L) {
    first(L) = NULL;
}

address createNewElementList_103032300084(infotype data) {
    address p = new elmlist;
    info(p) = data;
    next(p) = NULL;
    return p;
}

void insertLast_103032300084(List &L, address P) {
    if (first(L) == NULL) {
        first(L) = P;
    } else {
        address x = first(L);
        while (next(x) != NULL) {
            x = next(x);
        }
        next(x) = P;
    }
}

void showAllData_103032300084(List L) {
    address p = first(L);
    while (p != NULL) {
        cout << info(p) << ", ";
        p = next(p);
    }
    cout << endl;
}

address shortestName_103032300084(List L) {
    address p = first(L);
    address shortest = p;

    while (p != NULL) {
        if (info(p).length() <= info(shortest).length()) {
            shortest = p;
        }
        p = next(p);
    }

    return shortest;
}

void showFirstKNameC_103032300084(List L, int k, char c) {
    address p = first(L);
    int count = 0;

    while (p != NULL && count < k) {
        if (info(p)[0] == c) {
            cout << info(p) << ", ";
            count++;
        }
        p = next(p);
    }
    cout << endl;
}
