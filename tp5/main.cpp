#include <iostream>
#include "list.h"
using namespace std;

int menu() {
    int pilihan;
    cout << "====MENU====" << endl;
    cout << "1. Menambahkan N data Baru" << endl;
    cout << "2. Tampilkan Semua Data" << endl;
    cout << "3. Pengunjung dengan nama terpendek yang muncul di list" << endl;
    cout << "4. Tampilkan data k pengunjung pertama yang memiliki nama berawalan karakter tertentu" << endl;
    cout << "0. Exit" << endl;
    cout << "Masukkan pilihan: ";
    cin >> pilihan;
    return pilihan;
}

int main() {
    List L;
    createList_103032300084(L);

    infotype data;
    address P;
    int k, input;
    char c;
    string kembali;

    input = menu();
    while (input != 0) {
        if (input == 1) {
            int jumlah;
            cout << "Jumlah data yang ditambahkan: ";
            cin >> jumlah;
            for (int i = 0; i < jumlah; i++) {
                cout << "Masukkan nama pengunjung: ";
                cin >> data;
                P = createNewElementList_103032300084(data);
                insertLast_103032300084(L, P);
            }
        } else if (input == 2) {
            showAllData_103032300084(L);
        } else if (input == 3) {
            address shortest = shortestName_103032300084(L);
            if (shortest != NULL) {
                cout << "Pengunjung dengan nama terpendek: " << info(shortest) << endl;
            }
        } else if (input == 4) {
            cout << "Masukkan nilai k: ";
            cin >> k;
            cout << "Masukkan karakter awal nama: ";
            cin >> c;
            showFirstKNameC_103032300084(L, k, c);
        } else {
            cout << "Pilihan Tidak Valid" << endl;
        }

        input = menu();
    }

    cout << "Anda Telah Keluar dari Program ini" << endl;
    return 0;
}
