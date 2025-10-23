#include <iostream>
using namespace std;

int main() {
    int x[2][3][5];
    cout << "Ukuran tiap elemen int = " << sizeof(int) << " byte" << endl;
    cout << "Alamat x[1][1][4] = 0x12EF" << endl;
    cout << "Alamat x[0][0][3] = 0x" 
         << hex << (0x12EF - (((1 * 3 * 5) + (1 * 5) + (4 - 3)) * sizeof(int))) << endl;
    return 0;
}