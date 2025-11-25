#include <iostream>
using namespace std;

int main() {
    char x[12];
    cout << "Ukuran tiap elemen char = " << sizeof(char) << " byte" << endl;
    cout << "Alamat x[0] = 0x1000" << endl;
    cout << "Alamat x[8] = 0x" << hex << (0x1000 + 8 * sizeof(char)) << endl;
    return 0;
}