#include "graph.h"

void createNode(char newVertexID, adrNode &n) {
    n = new elmNode;
    idNode(n) = newVertexID;
    nextNode(n) = NULL;
    firstEdge(n) = NULL;
}
