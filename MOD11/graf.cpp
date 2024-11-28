#include <iostream>
#include "graf.h"

void createVertex_103032300084(char newVertexID, adrVertex &v){
    v = new vertex;
    idVertex(v) = newVertexID;
    nextVertex(v) = NULL;
    firstEdge(v) = NULL;
}

void initGraph_103032300084(graph &G){
    firstVertex(G) = NULL;
}

void addVertex_103032300084(graph &G, char newVertexID){
   adrVertex v;
   createVertex_103032300084(newVertexID, v);

   if (firstVertex(G) == NULL){
    firstVertex(G) = v;
   } else {
    adrVertex u = firstVertex(G);
    while (nextVertex(u) != NULL) {
        u = nextVertex(u);
    }
    nextVertex(u) = v;
   }
}

void buildGraph_103032300084(graph &G){
   initGraph_103032300084(G);
   char vertexID;
    cout << "Masukkan ID Vertex (huruf): " << endl;
   while (true){
       cin >> vertexID;
       if (vertexID >= 'A' && vertexID <= 'Z') {
           bool dupe = false;
           adrVertex u;
           u = firstVertex(G);
           while (u != NULL){
               if (idVertex(u) == vertexID) {
                   dupe = true;
               }
               u = nextVertex(u);
           }
           if (! dupe){
               addVertex_103032300084(G, vertexID);
           } else {
               cout << vertexID << " " << "Sudah ada. Silahkan masukkan ID yang lain" << endl;
           }
       } else {
           cout << "Proses selesai" << endl;
           break;
       }
   }
}


