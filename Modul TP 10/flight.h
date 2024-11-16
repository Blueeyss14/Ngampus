#ifndef FLIGHT_H_INCLUDED
#define FLIGHT_H_INCLUDED
#define info(P) P->info
#define next(P) P->next
#define first(L) L.first
//#include <string>

using namespace std;

struct jadwalPenerbangan {
    string kode;
    string jenis;
    string tanggal;
    string waktu;
    string asal;
    string tujuan;
    int kapasitas;
};

typedef struct elemenJadwal *adr_jadwalP;

typedef jadwalPenerbangan infotype;

struct elemenJadwal {
    infotype info;
    adr_jadwalP next;
};

struct ListJadwal {
    adr_jadwalP first;
};

void createListJadwal_103032300084(ListJadwal &L);
adr_jadwalP createElemenJadwal_103032300084(infotype X);
void InsertLastJ_103032300084(ListJadwal &L, adr_jadwalP P);
void ShowJadwal_103032300084(ListJadwal L);
void deleteFirst_103032300084(ListJadwal &L, adr_jadwalP &P);
bool SearchJ_103032300084(ListJadwal L, string dari, string ke, string tanggal);

#endif // FLIGHT_H_INCLUDED
