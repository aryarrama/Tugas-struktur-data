// file: binary_search.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

void binarySearchDemo() {
    cout << "=== BINARY SEARCH ===" << endl;
    cout << "Mencari angka tertentu dari 15 data terurut\n" << endl;
    
    // Generate 15 data random
    int data[15];
    srand(time(0));
    
    cout << "Membuat 15 data random..." << endl;
    for (int i = 0; i < 15; i++) {
        data[i] = rand() % 100 + 1;
    }
    
    // Sort data untuk binary search
    sort(data, data + 15);
    
    cout << "Data terurut: ";
    for (int i = 0; i < 15; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    
    // Pilih target (bisa dari data atau input user)
    int target;
    cout << "\nPilih angka yang ingin dicari: ";
    cin >> target;
    
    cout << "\n--- Proses Binary Search ---" << endl;
    cout << "Mencari: " << target << endl << endl;
    
    int left = 0;
    int right = 14;
    int mid;
    int count = 0;
    bool found = false;
    
    while (left <= right) {
        count++;
        mid = left + (right - left) / 2;
        
        cout << "Iterasi ke-" << count << ":" << endl;
        cout << "  Rentang indeks: [" << left << ".." << right << "]" << endl;
        cout << "  Mid = " << left << " + (" << right << " - " << left << ") / 2 = " << mid << endl;
        cout << "  data[" << mid << "] = " << data[mid] << endl;
        
        if (data[mid] == target) {
            cout << "  → DITEMUKAN! Angka " << target << " ada di indeks " << mid << endl;
            found = true;
            break;
        } else if (data[mid] < target) {
            cout << "  → " << data[mid] << " < " << target << ", cari di kanan" << endl;
            left = mid + 1;
        } else {
            cout << "  → " << data[mid] << " > " << target << ", cari di kiri" << endl;
            right = mid - 1;
        }
        cout << endl;
    }
    
    cout << "=============================" << endl;
    if (found) {
        cout << "Hasil: Angka " << target << " ditemukan" << endl;
    } else {
        cout << "Hasil: Angka " << target << " tidak ditemukan" << endl;
    }
    cout << "Jumlah iterasi pencarian: " << count << endl;
    
    // Tampilkan semua data dengan indeks
    cout << "\nData lengkap dengan indeks:" << endl;
    for (int i = 0; i < 15; i++) {
        cout << "Indeks " << i << ": " << data[i];
        if (i == mid && found) cout << " ← ditemukan";
        cout << endl;
    }
}

int main() {
    cout << "PROGRAM BINARY SEARCH" << endl;
    cout << "=====================" << endl;
    binarySearchDemo();
    return 0;
}