#include <iostream>
#include "flight.h"

using namespace std;

void tampilkanMenu() {
    cout << "\n=== MENU JADWAL PENERBANGAN ===\n";
    cout << "1. Tambah Jadwal Penerbangan\n";
    cout << "2. Hapus Jadwal Penerbangan Pertama\n";
    cout << "3. Tampilkan Semua Jadwal Penerbangan\n";
    cout << "4. Cari Jadwal Penerbangan\n";
    cout << "5. Keluar\n";
    cout << "Pilih menu: ";
}

int main() {
    ListJadwal L;
    createListJadwal_103032300084(L);

    int pilihan;
    do {
        tampilkanMenu();
        cin >> pilihan;

        switch (pilihan) {
        case 1: {
            infotype jadwal;
            cout << "\nMasukkan data jadwal penerbangan:\n";
            cout << "Kode Penerbangan: ";
            cin >> jadwal.kode;
            cout << "Jenis Pesawat: ";
            cin >> jadwal.jenis;
            cout << "Tanggal (format: YYYY-MM-DD): ";
            cin >> jadwal.tanggal;
            cout << "Waktu (format: HH:MM): ";
            cin >> jadwal.waktu;
            cout << "Asal Penerbangan: ";
            cin >> jadwal.asal;
            cout << "Tujuan Penerbangan: ";
            cin >> jadwal.tujuan;

            adr_jadwalP P = createElemenJadwal_103032300084(jadwal);
            InsertLastJ_103032300084(L, P);
            cout << "Jadwal penerbangan berhasil ditambahkan!\n";
            break;
        }
        case 2: {
            adr_jadwalP deleted;
            deleteFirst_103032300084(L, deleted);
            if (deleted != NULL) {
                cout << "Jadwal penerbangan dengan kode " << info(deleted).kode << " berhasil dihapus.\n";
            } else {
                cout << "List kosong, tidak ada jadwal yang dapat dihapus.\n";
            }
            break;
        }
        case 3: {
            cout << "\nDaftar Jadwal Penerbangan:\n";
            ShowJadwal_103032300084(L);
            break;
        }
        case 4: {
            string dari, ke, tanggal;
            cout << "\nMasukkan data untuk mencari jadwal penerbangan:\n";
            cout << "Asal Penerbangan: ";
            cin >> dari;
            cout << "Tujuan Penerbangan: ";
            cin >> ke;
            cout << "Tanggal (format: YYYY-MM-DD): ";
            cin >> tanggal;

            bool ditemukan = SearchJ_103032300084(L, dari, ke, tanggal);
            if (ditemukan) {
                cout << "Jadwal penerbangan ditemukan!\n";
            } else {
                cout << "Jadwal penerbangan tidak ditemukan.\n";
            }
            break;
        }
        case 5:
            cout << "Terima kasih telah menggunakan program ini.\n";
            break;
        default:
            cout << "Pilihan tidak valid, silakan coba lagi.\n";
        }
    } while (pilihan != 5);

    return 0;
}
