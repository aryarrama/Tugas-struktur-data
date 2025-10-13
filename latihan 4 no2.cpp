#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

class Stack {
private:
    int data[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
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

    int pop() {
        if (!isEmpty()) {
            int value = data[top];
            top--;
            return value;
        } else {
            cout << "Stack Kosong!\n";
            return -1;
        }
    }
};

int main() {
    Stack S;
    int input;
    
    cout << "====== PROGRAM PUSH SAMPAI PENUH DAN POP SAMPAI KOSONG ======\n";
    cout << "Masukkan data (input: 999 untuk berhenti):\n";
    
    // Proses PUSH
    while (true) {
        cout << "Input data: ";
        cin >> input;
        
        if (input == 999) {
            cout << "Proses input selesai.\n";
            break;
        }
        
        if (S.isFull()) {
            cout << "Stack sudah penuh! Proses input dihentikan.\n";
            break;
        }
        
        S.push(input);
    }
    
    cout << "\n====== MENGELUARKAN ISI STACK ======\n";
    // Proses POP
    while (!S.isEmpty()) {
        int poppedValue = S.pop();
        cout << "Data yang diPOP: " << poppedValue << endl;
    }
    
    cout << "Stack sekarang kosong.\n";
    return 0;
}