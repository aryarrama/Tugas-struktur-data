// file: bubble_sort_animation.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void bubbleSortAnimation() {
    cout << "=== ANIMASI BUBBLE SORT ===" << endl;
    cout << "Menampilkan proses Bubble Sort dari 10 data random\n" << endl;
    
    // Generate 10 angka random
    int arr[10];
    srand(time(0));
    
    cout << "Data awal: ";
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 100 + 1;
        cout << arr[i] << " ";
    }
    cout << endl << endl;
    
    // Proses bubble sort dengan animasi
    for (int i = 0; i < 9; i++) {
        cout << "=== iterasi " << i+1 << " ===" << endl;
        for (int j = 0; j < 9-i; j++) {
            cout << "Langkah " << j+1 << ": ";
            cout << "Bandingkan arr[" << j << "]=" << arr[j] 
                 << " dan arr[" << j+1 << "]=" << arr[j+1];
            
            if (arr[j] > arr[j+1]) {
                cout << " -> Tukar" << endl;
                swap(arr[j], arr[j+1]);
                
                // Tampilkan array setelah pertukaran
                cout << "  Array sekarang: ";
                for (int k = 0; k < 10; k++) {
                    cout << arr[k] << " ";
                }
                cout << endl;
            } else {
                cout << " -> Tidak perlu ditukar" << endl;
            }
        }
        cout << endl;
    }
    
    cout << "=================================" << endl;
    cout << "Hasil akhir (terurut): ";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "PROGRAM BUBBLE SORT ANIMASI" << endl;
    cout << "============================" << endl;
    bubbleSortAnimation();
    return 0;
}