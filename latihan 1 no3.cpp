#include <iostream>
using namespace std;

int main() {
    int skor;
    cout << "Masukkan skor: ";
    cin >> skor;

    if (skor == 100) {
        cout << "Skor sempurna!" << endl;
    } else if (skor >= 90) {
        cout << "Grade: A" << endl;
    } else if (skor >= 80) {
        cout << "Grade: B" << endl;
    } else if (skor >= 70) {
        cout << "Grade: C" << endl;
    } else if (skor >= 60) {
        cout << "Grade: D" << endl;
    } else {
        cout << "Grade: F" << endl;
    }

    return 0;
}
