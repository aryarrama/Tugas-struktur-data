#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    string gender;
    float nilai;
    Mahasiswa* next;
};

Mahasiswa* head = nullptr; // Head menunjukkan elemen teratas Stack

void insertData() {
    Mahasiswa* baru = new Mahasiswa();
    cout << "\n=== INPUT DATA MAHASISWA ===\n";
    cout << "Nama   : "; getline(cin >> ws, baru->nama);
    cout << "NIM    : "; getline(cin, baru->nim);
    cout << "Gender : "; getline(cin, baru->gender);
    cout << "Nilai  : "; cin >> baru->nilai;
    baru->next = head;
    head = baru;
    cout << "Data berhasil dimasukkan ke Stack!\n";
}

void hapusData() {
    if (head == nullptr) {
        cout << "Stack kosong, tidak ada data untuk dihapus.\n";
        return;
    }
    Mahasiswa* hapus = head;
    head = head->next;
    cout << "\nData mahasiswa dengan nama '" << hapus->nama << "' telah dihapus dari Stack.\n";
    delete hapus;
}

void cetakData() {
    if (head == nullptr) {
        cout << "Stack kosong.\n";
        return;
    }
    cout << "\n=== DATA DALAM STACK ===\n";
    Mahasiswa* bantu = head;
    int i = 1;
    while (bantu != nullptr) {
        cout << i++ << ". " << bantu->nama << " | " << bantu->nim
             << " | " << bantu->gender << " | Nilai: " << bantu->nilai << endl;
        bantu = bantu->next;
    }
}

int main() {
    int pilihan;
    do {
        cout << "\n=== MENU STACK (Linked List dengan Head) ===\n";
        cout << "1. INSERT DATA\n";
        cout << "2. HAPUS DATA\n";
        cout << "3. CETAK DATA\n";
        cout << "4. EXIT\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: insertData(); break;
            case 2: hapusData(); break;
            case 3: cetakData(); break;
            case 4: cout << "Program selesai.\n"; break;
            default: cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 4);
}