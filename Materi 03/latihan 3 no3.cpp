#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    int nomor;
    string nama;
    int umur;
    string alamat;
    float nilai;
};
int main() {
    const int JUMLAH = 15;
    Mahasiswa mhs[JUMLAH];
    
    cout << "=== INPUT DATA 15 MAHASISWA ===\n";
    for(int i = 0; i < JUMLAH; i++) {
        cout << "\n--- Mahasiswa " << i+1 << " ---\n";
        mhs[i].nomor = i + 1;
        cin.ignore();
        cout << "Nama: ";
        getline(cin, mhs[i].nama);
        cout << "Umur: ";
        cin >> mhs[i].umur;
        cin.ignore();
        cout << "Alamat: ";
        getline(cin, mhs[i].alamat);
        cout << "Nilai: ";
        cin >> mhs[i].nilai;
    }
    
    
    cout << "\n=== DATA SEMUA MAHASISWA ===\n";
    for(int i = 0; i < JUMLAH; i++) {
        cout << "\nNomor Urut: " << mhs[i].nomor << endl;
        cout << "Nama: " << mhs[i].nama << endl;
        cout << "Umur: " << mhs[i].umur << " tahun" << endl;
        cout << "Alamat: " << mhs[i].alamat << endl;
        cout << "Nilai: " << mhs[i].nilai << endl;
        cout << "-------------------" << endl;
    }
    
    return 0;
}