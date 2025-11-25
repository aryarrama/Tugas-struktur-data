#include <iostream>
using namespace std;

int main() {
    int x[15];
    cout << "Ukuran tiap elemen int = " << sizeof(int) << " byte" << endl;
    cout << "Alamat x[3] = 0x1000" << endl;
    cout << "Alamat x[9] = 0x" << hex << (0x1000 + (9 - 3) * sizeof(int)) << endl;
    return 0;
}