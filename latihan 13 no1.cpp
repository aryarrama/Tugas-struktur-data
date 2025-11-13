#include <iostream>
#include <string>
using namespace std;

// Struktur data mahasiswa
struct Mahasiswa {
    string nama;
    string nim;
    string gender;
    float nilai;
    Mahasiswa* next;
    Mahasiswa* prev;
};

// Pointer awal dan akhir
Mahasiswa* head = nullptr;
Mahasiswa* tail = nullptr;

// Fungsi membuat node baru
Mahasiswa* buatNode(string nama, string nim, string gender, float nilai) {
    Mahasiswa* baru = new Mahasiswa;
    baru->nama = nama;
    baru->nim = nim;
    baru->gender = gender;
    baru->nilai = nilai;
    baru->next = nullptr;
    baru->prev = nullptr;
    return baru;
}

// Fungsi insert data secara terurut naik berdasarkan NIM
void insertData(string nama, string nim, string gender, float nilai) {
    Mahasiswa* baru = buatNode(nama, nim, gender, nilai);

    // Jika list kosong
    if (head == nullptr) {
        head = tail = baru;
        cout << "Data berhasil ditambahkan.\n";
        return;
    }

    // Jika NIM lebih kecil dari head (sisip di depan)
    if (nim < head->nim) {
        baru->next = head;
        head->prev = baru;
        head = baru;
        cout << "Data berhasil ditambahkan di awal list.\n";
        return;
    }

    // Jika NIM lebih besar dari tail (sisip di akhir)
    if (nim > tail->nim) {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
        cout << "Data berhasil ditambahkan di akhir list.\n";
        return;
    }

    // Sisip di tengah (urut naik berdasarkan NIM)
    Mahasiswa* bantu = head;
    while (bantu != nullptr && bantu->nim < nim) {
        bantu = bantu->next;
    }

    // Jika NIM sudah ada
    if (bantu != nullptr && bantu->nim == nim) {
        cout << "Gagal! NIM sudah ada di dalam list.\n";
        delete baru;
        return;
    }

    // Sisip di tengah
    baru->next = bantu;
    baru->prev = bantu->prev;
    bantu->prev->next = baru;
    bantu->prev = baru;
    cout << "Data berhasil ditambahkan di tengah list.\n";
}

// Fungsi hapus data berdasarkan NIM
void hapusData(string nim) {
    if (head == nullptr) {
        cout << "List masih kosong!\n";
        return;
    }

    Mahasiswa* hapus = head;

    // Cari node dengan NIM yang cocok
    while (hapus != nullptr && hapus->nim != nim) {
        hapus = hapus->next;
    }

    if (hapus == nullptr) {
        cout << "Data dengan NIM " << nim << " tidak ditemukan.\n";
        return;
    }

    // Jika hanya ada satu data
    if (head == tail) {
        head = tail = nullptr;
    }
    // Jika yang dihapus adalah head
    else if (hapus == head) {
        head = head->next;
        head->prev = nullptr;
    }
    // Jika yang dihapus adalah tail
    else if (hapus == tail) {
        tail = tail->prev;
        tail->next = nullptr;
    }
    // Jika yang dihapus di tengah
    else {
        hapus->prev->next = hapus->next;
        hapus->next->prev = hapus->prev;
    }

    delete hapus;
    cout << "Data berhasil dihapus.\n";
}

// Fungsi cetak seluruh data
void cetakData() {
    if (head == nullptr) {
        cout << "List masih kosong.\n";
        return;
    }

    cout << "\n=== DAFTAR DATA MAHASISWA ===\n";
    Mahasiswa* bantu = head;
    while (bantu != nullptr) {
        cout << "NIM     : " << bantu->nim << endl;
        cout << "Nama    : " << bantu->nama << endl;
        cout << "Gender  : " << bantu->gender << endl;
        cout << "Nilai   : " << bantu->nilai << endl;
        cout << "-----------------------------\n";
        bantu = bantu->next;
    }
}

// Fungsi utama
int main() {
    int pilihan;
    string nama, nim, gender;
    float nilai;

    do {
        cout << "\nLIN. DOUBLE LINKED LIST\n";
        cout << "==========================\n";
        cout << "1. INSERT DATA\n";
        cout << "2. HAPUS DATA\n";
        cout << "3. CETAK DATA\n";
        cout << "4. EXIT\n";
        cout << "Pilihan (1–4): ";
        cin >> pilihan;
        cin.ignore(); // membersihkan buffer input

        switch (pilihan) {
            case 1:
                cout << "\nMasukkan Nama   : ";
                getline(cin, nama);
                cout << "Masukkan NIM    : ";
                getline(cin, nim);
                cout << "Masukkan Gender : ";
                getline(cin, gender);
                cout << "Masukkan Nilai  : ";
                cin >> nilai;
                cin.ignore();
                insertData(nama, nim, gender, nilai);
                break;

            case 2:
                cout << "\nMasukkan NIM yang akan dihapus: ";
                getline(cin, nim);
                hapusData(nim);
                break;

            case 3:
                cetakData();
                break;

            case 4:
                cout << "Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
                break;
        }

    } while (pilihan != 4);

    return 0;
}