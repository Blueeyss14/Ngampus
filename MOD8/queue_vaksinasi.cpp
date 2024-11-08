#include <iostream>
#include "queue_vaksinasi.h"


void createQueue_103032300084(Queue &Q){
    head(Q) = NULL;
    tail(Q) = NULL;
}

bool isEmpty_103032300084(Queue Q){
    return head(Q) == NULL;
}

ElemQ* createElemQueue_103032300084(string nama, int usia, string pekerjaan, int nomor_antrean){
    ElemQ *P = new ElemQ;
    info(P).nama = nama;
    info(P).usia = usia;
    info(P).pekerjaan = pekerjaan;
    info(P).prioritas = usia >= 60 || pekerjaan == "tenaga kesehatan";
    info(P).nomor_antrean = nomor_antrean;
    info(P).kondisi_darurat = false;
    next(P) = NULL;
    return P;
}

void enqueue_103032300084(Queue &Q, ElemQ *P){
    if (isEmpty_103032300084(Q)){
        head(Q) = P;
        tail(Q) = P;
    }else if (info(P).prioritas){
        if (!info(head(Q)).prioritas){
            next(P) = head(Q);
            head(Q) = P;
        }else{
            ElemQ *temp = head(Q);
            while (next(temp) != NULL && info(next(temp)).prioritas){
                temp = next(temp);
            }
            next(P) = next(temp);
            next(temp) = P;
            if (next(P) == NULL){
                tail(Q) = P;
            }
        }
    }else{
        next(tail(Q)) = P;
        tail(Q) = P;
    }
}

void dequeue_103032300084(Queue &Q, ElemQ *&P){
    if (isEmpty_103032300084(Q)){
        P = NULL;
        cout << "Semua warga telah terlayani." << endl;
    }else{
        P = head(Q);
        head(Q) = next(head(Q));
        if (head(Q) == NULL){
            tail(Q) = NULL;
        }
        next(P) = NULL;
    }
}

ElemQ* front_103032300084(Queue Q){
    return head(Q);
}

ElemQ* back_103032300084(Queue Q){
    return tail(Q);
}

int size_103032300084(Queue Q){
    int count = 0;
    ElemQ *temp = head(Q);
    while (temp != NULL) {
        count++;
        temp = next(temp);
    }
    return count;
}

void printInfo_103032300084(Queue Q){
    ElemQ *P = head(Q);
    if (P == NULL){
        cout << "Antrian Kosong" << endl;
    }else {
        while (P != NULL){
            cout << endl << "------------------------------" << endl;
            cout << "Nama: " << info(P).nama << endl;
            cout << "Usia: " << info(P).usia << endl;
            cout << "Pekerjaan: " << info(P).pekerjaan << endl;
            if (info(P).prioritas){
                cout << "Prioritas: Ya" << endl;
            }else{
                cout << "Prioritas: Tidak" << endl;
            }
            cout << "Nomor Antrean: " << info(P).nomor_antrean << endl;
            cout << "------------------------------";
            P = next(P);
        }
    }
    cout << endl;
}

void serveQueue_103032300084(Queue &Q){
    int kouta = 100;
    ElemQ *P;
    while (!isEmpty_103032300084(Q) && kouta != 0){
        dequeue_103032300084(Q, P);
        cout << "Melayani warga:" << endl;
        cout << "------------------------------" << endl;
        cout << "Nama: " << info(P).nama << endl;
        cout << "Usia: " << info(P).usia << endl;
        cout << "Pekerjaan: " << info(P).pekerjaan << endl;
        if (info(P).prioritas){
            cout << "Prioritas: Ya" << endl;
        }else{
            cout << "Prioritas: Tidak" << endl;
        }
        cout << "Vaksinasi berhasil." << endl;
        cout << "------------------------------" << endl;
        kouta--;
    }
    if (kouta == 0){
        cout << endl << "Kapasitas penuh" << endl;
    }
    if (!isEmpty_103032300084(Q)){
        cout << endl << "Silakan datang kembali besok" << endl;
    }
}

void reassignQueue_103032300084(Queue &Q){
    Queue S;
    createQueue_103032300084(S);
    int P = size_103032300084(Q);
    ElemQ *R;
    while (P != 0 || !isEmpty_103032300084(Q)){
        dequeue_103032300084(Q, R);
        enqueue_103032300084(S, R);
        P--;
    }
    Q = S;
}

void checkWaitingTime_103032300084(Queue &Q, int waktu_sekarang){
    ElemQ *P = head(Q);
    if (waktu_sekarang > 120){
        P = head(Q);
        while (P != NULL){
            info(P).prioritas = true;
            P = next(P);
        }
    }
    reassignQueue_103032300084(Q);
}

void emergencyHandle_103032300084(Queue &Q, int nomor_antrean){
    ElemQ *P = head(Q);
    while (P != NULL){
        if (info(P).nomor_antrean == nomor_antrean){
            info(P).kondisi_darurat = true;
            info(P).prioritas = true;
            reassignQueue_103032300084(Q);
            return;
        }
        P = next(P);
    }
    cout << endl << "Tidak ada nomor antrian" << endl;
}

void updatePriority_103032300084(Queue &Q){
    ElemQ *P = head(Q);
    ElemQ *R;
    while (P != NULL){
        if (info(P).kondisi_darurat){
            reassignQueue_103032300084(Q);
        }
        P = next(P);
    }
}

ElemQ* findAndRemove_103032300084(Queue &Q, int nomor_antrean){
    ElemQ *P, *S, *R;
    P = head(Q);
    S = head(Q);
    while (next(P) != NULL){
        if (nomor_antrean == info(P).nomor_antrean){
            if (P == head(Q)){
                dequeue_103032300084(Q, R);
                cout << "Elemen dengan nomor antrean " << nomor_antrean << " ditemukan dan dihapus dari antrean." << endl;
                return R;
            }else if (P == tail(Q)){
                tail(Q) = S;
                next(tail(Q)) = NULL;
                cout << "Elemen dengan nomor antrean " << nomor_antrean << " ditemukan dan dihapus dari antrean." << endl;
                return P;
            }else{
                next(S) = next(P);
                next(P) = NULL;
                cout << "Elemen dengan nomor antrean " << nomor_antrean << " ditemukan dan dihapus dari antrean." << endl;
                return P;
            }
        }
        S = P;
        P = next(P);
    }
    cout << "Elemen dengan nomor antrean " << nomor_antrean << " tidak ditemukan dalam antrean." << endl;
    return NULL;
}
