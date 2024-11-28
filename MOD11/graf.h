#ifndef GRAF_H_INCLUDED
#define GRAF_H_INCLUDED
#define nextVertex(v) v->nextVertex
#define nextEdge(e) e->nextEdge
#define firstVertex(v) v.firstVertex
#define firstEdge(e) e->firstEdge
#define idVertex(v) v->idVertex

#include <iostream>
using namespace std;

typedef struct vertex *adrVertex;
typedef struct edge *adrEdge;

struct vertex {
    char idVertex;
    adrVertex nextVertex;
    adrEdge firstEdge;
};

struct edge {
    char destVertexID;
    int weight;
    adrEdge nextEdge;
};

struct graph {
    adrVertex firstVertex;
};

void createVertex_103032300084(char newVertexID, adrVertex &v);
void initGraph_103032300084(graph &G);
void addVertex_103032300084(graph &G, char newVertexID);
void buildGraph_103032300084(graph &G);
void buildGraph_103032300084(graph &G);

#endif // GRAF_H_INCLUDED
