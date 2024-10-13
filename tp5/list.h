#include <iostream>
#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

using namespace std;

typedef string infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList_103032300084(List &L);
address createNewElementList_103032300084(infotype data);
void insertLast_103032300084(List &L, address P);
void showAllData_103032300084(List L);
address shortestName_103032300084(List L);
void showFirstKNameC_103032300084(List L, int k, char c);

