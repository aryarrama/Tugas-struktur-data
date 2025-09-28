#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    int nomor;
    string nama;
    int umur;
};

int main() {
    const int JUMLAH = 5;
    Mahasiswa mhs[JUMLAH];
    
    cout << "======== INPUT DATA 5 MAHASISWA =========\n";
    for(int i = 0; i < JUMLAH; i++) {
        cout << "\nMahasiswa " << i+1 << ":\n";
        mhs[i].nomor = i + 1; 
        cout << "Nama: ";
        cin.ignore();
        getline(cin, mhs[i].nama);
        cout << "Umur: ";
        cin >> mhs[i].umur;
    }
    
    cout << "\n======= DETAIL MAHASISWA NO URUT 2 ========\n";
    for(int i = 0; i < JUMLAH; i++) {
        if(mhs[i].nomor == 2) {
            cout << "No Urut: " << mhs[i].nomor << endl;
            cout << "Nama: " << mhs[i].nama << endl;
            cout << "Umur: " << mhs[i].umur << " tahun" << endl;
            break;
        }
    }
    
    return 0;
}