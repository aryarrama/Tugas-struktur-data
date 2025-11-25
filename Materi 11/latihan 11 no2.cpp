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

Mahasiswa* top = nullptr; // Tidak ada head, hanya top untuk stack

void pushData() {
    Mahasiswa* baru = new Mahasiswa();
    cout << "\n=== INPUT DATA MAHASISWA ===\n";
    cout << "Nama   : "; getline(cin >> ws, baru->nama);
    cout << "NIM    : "; getline(cin, baru->nim);
    cout << "Gender : "; getline(cin, baru->gender);
    cout << "Nilai  : "; cin >> baru->nilai;
    baru->next = top;
    top = baru;
    cout << "Data berhasil dimasukkan ke Stack!\n";
}

void popData() {
    if (top == nullptr) {
        cout << "Stack kosong, tidak ada data untuk dihapus.\n";
        return;
    }
    Mahasiswa* hapus = top;
    top = top->next;
    cout << "\nData mahasiswa dengan nama '" << hapus->nama << "' telah dihapus.\n";
    delete hapus;
}

void printData() {
    if (top == nullptr) {
        cout << "Stack kosong.\n";
        return;
    }
    cout << "\n=== DATA DALAM STACK ===\n";
    Mahasiswa* bantu = top;
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
        cout << "\n=== MENU STACK (Linked List tanpa Head) ===\n";
        cout << "1. INSERT DATA\n";
        cout << "2. HAPUS DATA\n";
        cout << "3. CETAK DATA\n";
        cout << "4. EXIT\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: pushData(); break;
            case 2: popData(); break;
            case 3: printData(); break;
            case 4: cout << "Program selesai.\n"; break;
            default: cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 4);
}