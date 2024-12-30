#ifndef GRAF_H_INCLUDED
#define GRAF_H_INCLUDED

#include <iostream>
using namespace std;

#define nextNode(v) v->nextNode
#define nextEdge(e) e->nextEdge
#define firstVertex(v) v.firstVertex
#define firstEdge(e) e->firstEdge
#define idNode(v) v->idNode
#define destVertexID(e) e->destVertexID
#define weight(e) e->weight

typedef int infoGraph;
typedef struct elmNode *adrNode;
typedef struct elmEdge *adrEdge;

struct elmNode {
    infoGraph Info;
    char idNode;
    adrNode nextNode;
    adrEdge firstEdge;
};

struct elmEdge {
    char destVertexID;
    int weight;
    adrEdge firstEdge;
};

struct graph {
    adrNode firstNode;
};




#endif // GRAF_H_INCLUDED