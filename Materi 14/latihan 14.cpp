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
};

Mahasiswa* head = nullptr;

/* Fungsi delay (animasi sederhana) */
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
    } else {
        Mahasiswa* curr = head;
        Mahasiswa* prev = nullptr;

        do {
            if (baru->nim < curr->nim)
                break;
            prev = curr;
            curr = curr->next;
        } while (curr != head);

        if (prev == nullptr) {
            // Insert di awal
            Mahasiswa* last = head;
            while (last->next != head)
                last = last->next;

            baru->next = head;
            head = baru;
            last->next = head;
        } else {
            prev->next = baru;
            baru->next = curr;
        }
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
    Mahasiswa* prev = nullptr;

    do {
        if (curr->nim == nimCari)
            break;
        prev = curr;
        curr = curr->next;
    } while (curr != head);

    if (curr->nim != nimCari) {
        cout << "Data tidak ditemukan!\n";
        return;
    }

    if (curr == head && curr->next == head) {
        delete curr;
        head = nullptr;
    } else if (curr == head) {
        Mahasiswa* last = head;
        while (last->next != head)
            last = last->next;

        head = head->next;
        last->next = head;
        delete curr;
    } else {
        prev->next = curr->next;
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
        cout << "---------------------------\n";
        delay(700); // animasi
        curr = curr->next;
    } while (curr != head);
}

/* MENU UTAMA */
int main() {
    int pilihan;

    do {
        cout << "\nCIRCULAR LINKED LIST\n";
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