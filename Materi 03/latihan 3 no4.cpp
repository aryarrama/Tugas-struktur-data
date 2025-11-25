#include <iostream>
#include <string>
using namespace std;

struct Buku {
    int nomorAkses;
    string penulis;
    string judul;
    bool diterbitkan;  
};
int main() {
    const int jumlah_buku = 3;
    Buku perpustakaan[jumlah_buku];
    
    cout << "=== INPUT DATA BUKU PERPUSTAKAAN ===\n";
    for(int i = 0; i < jumlah_buku; i++) {
        cout << "\n--- Buku " << i+1 << " ---\n";
        cout << "Nomor Akses: ";
        cin >> perpustakaan[i].nomorAkses;
        cin.ignore();
        cout << "Penulis: ";
        getline(cin, perpustakaan[i].penulis);
        cout << "Judul: ";
        getline(cin, perpustakaan[i].judul);
        cout << "Status (1 untuk tersedia, 0 untuk dipinjam): ";
        int status;
        cin >> status;
        perpustakaan[i].diterbitkan = (status == 1);
    }
    
    cout << "\n=== DATA SELURUH BUKU ===\n";
    for(int i = 0; i < jumlah_buku; i++) {
        cout << "\nBuku " << i+1 << ":\n";
        cout << "Nomor Akses: " << perpustakaan[i].nomorAkses << endl;
        cout << "Penulis: " << perpustakaan[i].penulis << endl;
        cout << "Judul: " << perpustakaan[i].judul << endl;
        cout << "Status: " << (perpustakaan[i].diterbitkan ? "Tersedia" : "Dipinjam") << endl;
        cout << "-------------------" << endl;
    }
    
    return 0;
}