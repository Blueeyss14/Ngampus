#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    stack S;
    createStack_103032300084(S);

    push_103032300084(S, 'A');
    push_103032300084(S, 'Y');
    push_103032300084(S, 'A');
    push_103032300084(S, 'J');
    push_103032300084(S, 'B');
    push_103032300084(S, 'A');
    push_103032300084(S, 'L');
    push_103032300084(S, 'F');
    push_103032300084(S, 'I');

    printInfo_103032300084(S);

    pop_103032300084(S);
    pop_103032300084(S);
    pop_103032300084(S);
    pop_103032300084(S);
    pop_103032300084(S);


    printInfo_103032300084(S);

    return 0;
}
