#include <iostream>
using namespace std;

int main() {
    long x[12][14];
    cout << "Ukuran tiap elemen long = " << sizeof(long) << " byte" << endl;
    cout << "Alamat x[0][0] = 0x1000" << endl;
    cout << "Alamat x[2][4] = 0x" 
         << hex << (0x1000 + ((2 * 14) + 4) * sizeof(long)) << endl;
    return 0;
}