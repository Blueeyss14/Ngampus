#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>

#define info(P) (P)->info
#define first(L) ((L).first)
#define next(P) (P)->next

struct infotype {
    std::string kode;
    std::string jenis;
    std::string tanggal;
    std::string waktu;
    std::string asal;
    std::string tujuan;
};

struct ElemenJadwal {
    infotype info;
    ElemenJadwal* next;
};

typedef ElemenJadwal* adr_jadwalP;

struct ListJadwal {
    adr_jadwalP first;
};

// Deklarasi fungsi-fungsi
void createListJadwal_103032300084(ListJadwal &L);
adr_jadwalP createElemenJadwal_103032300084(infotype jadwal);
void InsertLastJ_103032300084(ListJadwal &L, adr_jadwalP P);
void deleteFirst_103032300084(ListJadwal &L, adr_jadwalP &P);
void ShowJadwal_103032300084(ListJadwal L);
bool SearchJ_103032300084(ListJadwal L, std::string dari, std::string ke, std::string tanggal);

// Macro untuk mengakses info

#endif
