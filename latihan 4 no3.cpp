#include <iostream>
using namespace std;

const int MAX_SIZE = 7;

class Stack {
private:
    int data[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void push(int value) {
        if (!isFull()) {
            top++;
            data[top] = value;
            cout << "Data " << value << " berhasil diPUSH\n";
        } else {
            cout << "Stack Penuh!\n";
        }
    }
};

int main() {
    Stack S;
    int input;
    
    cout << "======== PROGRAM PUSH SAMPAI STACK PENUH =========\n";
    
    // PUSH sampai stack penuh
    while (!S.isFull()) {
        cout << "Masukkan data untuk diPUSH: ";
        cin >> input;
        S.push(input);
    }
    
    cout << "Stack sudah penuh, tidak bisa menambah data lagi!\n";
    return 0;
}