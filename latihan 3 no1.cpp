#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    int nomor;
    string nama;
    int usia;
    float nilai;
};

int main() {
    Mahasiswa mhs;
    
    cout << "====== INPUT DATA MAHASISWA ======\n";
    cout << "No Urut: ";
    cin >> mhs.nomor;
    cin.ignore(); 
    cout << "Nama: ";
    getline(cin, mhs.nama);
    cout << "Usia: ";
    cin >> mhs.usia;
    cout << "Nilai: ";
    cin >> mhs.nilai;
    
    cout << "\n=== DATA MAHASISWA ===\n";
    cout << "No Urut: " << mhs.nomor << endl;
    cout << "Nama: " << mhs.nama << endl;
    cout << "Usia: " << mhs.usia << " tahun" << endl;
    cout << "Nilai: " << mhs.nilai << endl;
    
    return 0;
}