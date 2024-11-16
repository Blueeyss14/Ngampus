#include <iostream>
#include "flight.h"
#include "flight.h"
using namespace std;

void createListJadwal_103032300084(ListJadwal &L){
    first(L) = NULL;
};

adr_jadwalP createElemenJadwal_103032300084(infotype X){
    adr_jadwalP P;
    P = new elemenJadwal;
    info(P) = X;
    next(P) = NULL;
    return P;
};

void InsertLastJ_103032300084(ListJadwal &L, adr_jadwalP P){
    if (first(L) == NULL) {
        first(L) = P;
    } else {
        adr_jadwalP Q;
        Q = first(L);
        while (next(Q) != NULL) {
            Q = next(Q);
        }
        next(Q) = P;
    }
};

void ShowJadwal_103032300084(ListJadwal L){
    adr_jadwalP P;
    P = first(L);
    if (first(L) == NULL){
        cout << "LIST KOSONG, TIDAK ADA YANG DI TAMPILKAN" << endl;
    }else{
        while (P != NULL){
            cout    << info(P).kode
                    << " "
                    << info(P).jenis
                    << " "
                    << info(P).tanggal
                    << " "
                    << info(P).waktu
                    << " "
                    << info(P).asal
                    << endl;
            P = next(P);
        }
    }
};

void deleteFirst_103032300084(ListJadwal &L, adr_jadwalP &P){
    if (first(L) == NULL){
        cout << "LIST KOSOSNG" << endl;
        P = NULL;
    }else{
        P = first(L);
        first(L) = next(P);
        next(P) = NULL;
    }
};

bool SearchJ_103032300084(ListJadwal L, string dari, string ke, string tanggal){
    adr_jadwalP P;
    P = first(L);
    while (P != NULL) {
        if (info(P).asal == dari && info(P).tujuan == ke && info(P).tanggal == tanggal) {
            return true;
        }
        P = next(P);
    }
    return false;
};
