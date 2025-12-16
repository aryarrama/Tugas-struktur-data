#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std;

struct Mahasiswa {
    string nama;
    string gender;
    int nim;
    float nilai;
    Mahasiswa* next;
    Mahasiswa* prev;
};

Mahasiswa* head = nullptr;

/* Delay untuk animasi */
void delay(int ms) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}

/* INSERT DATA (terurut berdasarkan NIM) */
void insertData() {
    Mahasiswa* baru = new Mahasiswa();

    cout << "Masukkan NIM    : ";
    cin >> baru->nim;
    cin.ignore();
    cout << "Masukkan Nama   : ";
    getline(cin, baru->nama);
    cout << "Masukkan Gender : ";
    getline(cin, baru->gender);
    cout << "Masukkan Nilai  : ";
    cin >> baru->nilai;

    if (head == nullptr) {
        head = baru;
        baru->next = head;
        baru->prev = head;
    } else {
        Mahasiswa* curr = head;

        do {
            if (baru->nim < curr->nim)
                break;
            curr = curr->next;
        } while (curr != head);

        Mahasiswa* prevNode = curr->prev;

        prevNode->next = baru;
        baru->prev = prevNode;
        baru->next = curr;
        curr->prev = baru;

        if (curr == head && baru->nim < head->nim)
            head = baru;
    }

    cout << "\nData berhasil ditambahkan!\n";
}

/* HAPUS DATA berdasarkan NIM */
void hapusData() {
    if (head == nullptr) {
        cout << "Linked List kosong!\n";
        return;
    }

    int nimCari;
    cout << "Masukkan NIM yang akan dihapus: ";
    cin >> nimCari;

    Mahasiswa* curr = head;
    bool found = false;

    do {
        if (curr->nim == nimCari) {
            found = true;
            break;
        }
        curr = curr->next;
    } while (curr != head);

    if (!found) {
        cout << "Data tidak ditemukan!\n";
        return;
    }

    if (curr->next == curr) {
        delete curr;
        head = nullptr;
    } else {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;

        if (curr == head)
            head = curr->next;

        delete curr;
    }

    cout << "Data berhasil dihapus!\n";
}

/* CETAK DATA (dengan animasi) */
void cetakData() {
    if (head == nullptr) {
        cout << "Linked List kosong!\n";
        return;
    }

    Mahasiswa* curr = head;
    int no = 1;

    cout << "\n===== DATA MAHASISWA =====\n";
    do {
        cout << "Data ke-" << no++ << endl;
        cout << "NIM    : " << curr->nim << endl;
        cout << "Nama   : " << curr->nama << endl;
        cout << "Gender : " << curr->gender << endl;
        cout << "Nilai  : " << curr->nilai << endl;
        cout << "--------------------------\n";
        delay(700); // animasi
        curr = curr->next;
    } while (curr != head);
}

/* MENU UTAMA */
int main() {
    int pilihan;

    do {
        cout << "\nCIRCULAR DOUBLY LINKED LIST\n";
        cout << "==========================\n";
        cout << "1. INSERT DATA\n";
        cout << "2. HAPUS DATA\n";
        cout << "3. CETAK DATA\n";
        cout << "4. EXIT\n";
        cout << "Pilihan (1 - 4) : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                insertData();
                break;
            case 2:
                hapusData();
                break;
            case 3:
                cetakData();
                break;
            case 4:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 4);

    return 0;
}
