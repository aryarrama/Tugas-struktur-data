#include <iostream>
using namespace std;

int main() {
    float x[5][8];
    cout << "Ukuran tiap elemen float = " << sizeof(float) << " byte" << endl;
    cout << "Alamat x[0][0] = 0x1000" << endl;
    cout << "Alamat x[2][4] = 0x" 
         << hex << (0x1000 + ((2 * 8) + 4) * sizeof(float)) << endl;
    return 0;
}