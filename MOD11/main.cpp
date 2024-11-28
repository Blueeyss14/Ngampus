#include <iostream>
#include "graf.h"

using namespace std;

int main()
{
    graph G;
    adrVertex v;

    cout << "Membuat graph" << endl;
    cout << "--------------------" << endl;
    buildGraph_103032300084(G);

    v = firstVertex(G);
    while (v != NULL){
        cout << idVertex(v) << " ";
        v = nextVertex(v);
    }
    cout << endl;
    return 0;
}