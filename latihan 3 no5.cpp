#include <iostream>
#include <string>
using namespace std;

struct Buku {
    int nomorAkses;
    string penulis;
    string judul;
    bool diterbitkan;
    int jumlah;
};

const int MAX_BUKU = 100;
Buku perpustakaan[MAX_BUKU];
int totalBuku = 0;

//untuk menampilkan informasi buku
void tampilkanInformasiBuku() {
    if(totalBuku == 0) {
        cout << "Perpustakaan kosong!\n";
        return;
    }
    
    int nomor;
    cout << "Masukkan nomor akses buku: ";
    cin >> nomor;
    
    for(int i = 0; i < totalBuku; i++) {
        if(perpustakaan[i].nomorAkses == nomor) {
            cout << "\n=== INFORMASI BUKU ===\n";
            cout << "Nomor Akses: " << perpustakaan[i].nomorAkses << endl;
            cout << "Judul: " << perpustakaan[i].judul << endl;
            cout << "Penulis: " << perpustakaan[i].penulis << endl;
            cout << "Status: " << (perpustakaan[i].diterbitkan ? "Tersedia" : "Dipinjam") << endl;
            cout << "Jumlah: " << perpustakaan[i].jumlah << " buku\n";
            return;
        }
    }
    cout << "Buku tidak ditemukan!\n";
}

//untuk menambah buku baru
void tambahBukuBaru() {
    if(totalBuku >= MAX_BUKU) {
        cout << "Perpustakaan penuh!\n";
        return;
    }
    
    cout << "\n=== TAMBAH BUKU BARU ===\n";
    cout << "Nomor Akses: ";
    cin >> perpustakaan[totalBuku].nomorAkses;
    cin.ignore();
    cout << "Judul: ";
    getline(cin, perpustakaan[totalBuku].judul);
    cout << "Penulis: ";
    getline(cin, perpustakaan[totalBuku].penulis);
    cout << "Jumlah: ";
    cin >> perpustakaan[totalBuku].jumlah;
    perpustakaan[totalBuku].diterbitkan = true;
    
    totalBuku++;
    cout << "Buku berhasil ditambahkan!\n";
}

//untuk menampilkan semua buku dari penulis tertentu
void tampilkanBukuPenulis() {
    if(totalBuku == 0) {
        cout << "Perpustakaan kosong!\n";
        return;
    }
    
    string penulis;
    cout << "Masukkan nama penulis: ";
    cin.ignore();
    getline(cin, penulis);
    
    cout << "\n=== BUKU OLEH " << penulis << " ===\n";
    bool ditemukan = false;
    for(int i = 0; i < totalBuku; i++) {
        if(perpustakaan[i].penulis == penulis) {
            cout << "- " << perpustakaan[i].judul;
            cout << " (No: " << perpustakaan[i].nomorAkses;
            cout << ", Jumlah: " << perpustakaan[i].jumlah << ")\n";
            ditemukan = true;
        }
    }
    if(!ditemukan) {
        cout << "Tidak ada buku dari penulis tersebut.\n";
    }
}

//untuk menghitung jumlah buku dengan judul tertentu
void hitungBukuJudul() {
    if(totalBuku == 0) {
        cout << "Perpustakaan kosong!\n";
        return;
    }
    
    string judul;
    cout << "Masukkan judul buku: ";
    cin.ignore();
    getline(cin, judul);
    
    int total = 0;
    for(int i = 0; i < totalBuku; i++) {
        if(perpustakaan[i].judul == judul) {
            total += perpustakaan[i].jumlah;
        }
    }
    cout << "Total buku dengan judul '" << judul << "': " << total << " buku\n";
}

//untuk menampilkan total semua buku di perpustakaan
void tampilkanTotalBuku() {
    int total = 0;
    for(int i = 0; i < totalBuku; i++) {
        total += perpustakaan[i].jumlah;
    }
    cout << "Total buku di perpustakaan: " << total << " buku\n";
    cout << "Jumlah judul buku berbeda: " << totalBuku << " judul\n";
}

//untuk meminjam buku 
void terbitkanBuku() {
    if(totalBuku == 0) {
        cout << "Perpustakaan kosong!\n";
        return;
    }
    
    int nomor;
    cout << "Masukkan nomor akses buku yang akan diterbitkan: ";
    cin >> nomor;
    
    for(int i = 0; i < totalBuku; i++) {
        if(perpustakaan[i].nomorAkses == nomor) {
            if(perpustakaan[i].jumlah > 0) {
                perpustakaan[i].jumlah--;
                cout << "Buku berhasil diterbitkan! Sisa: " << perpustakaan[i].jumlah << " buku\n";
                
                if(perpustakaan[i].jumlah == 0) {
                    perpustakaan[i].diterbitkan = false;
                    cout << "Buku habis! Status diubah menjadi tidak tersedia.\n";
                }
            } else {
                cout << "Stok buku habis!\n";
            }
            return;
        }
    }
    cout << "Buku tidak ditemukan!\n";
}

// Fungsi utama dengan menu
int main() {
    int pilihan;
    
    // Data sample untuk dicoba
    perpustakaan[0] = {10, "Arista Prasetyo Adi", "Panduan Cepat Belajar HTML, CSS, & MY SQL", true, 5};
    perpustakaan[1] = {20, "Rizki Hidayatullah", "Pemrograman Web PHP", true, 5};
    perpustakaan[2] = {30, "Abdul Kadir", "Logika Pemrograman PYTHON", true, 100};
    totalBuku = 3;
    
    cout << "=== SISTEM MANAJEMEN PERPUSTAKAAN ===\n";
    cout << "Data sample sudah dimasukkan untuk testing\n\n";
    
    do {
        cout << "=== MENU UTAMA ===\n";
        cout << "1. Tampilkan Informasi Buku\n";
        cout << "2. Tambah Buku Baru\n";
        cout << "3. Tampilkan Buku oleh Penulis\n";
        cout << "4. Hitung Buku dengan Judul Tertentu\n";
        cout << "5. Tampilkan Total Buku\n";
        cout << "6. Terbitkan Buku\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        
        switch(pilihan) {
            case 1: tampilkanInformasiBuku(); break;
            case 2: tambahBukuBaru(); break;
            case 3: tampilkanBukuPenulis(); break;
            case 4: hitungBukuJudul(); break;
            case 5: tampilkanTotalBuku(); break;
            case 6: terbitkanBuku(); break;
            case 0: cout << "Terima kasih telah menggunakan sistem perpustakaan!\n"; break;
            default: cout << "Pilihan tidak valid! Silakan pilih 0-6.\n";
        }
        cout << endl;
    } while(pilihan != 0);
    
    return 0;
}