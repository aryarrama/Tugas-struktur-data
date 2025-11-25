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
    
    cout << "========= PROGRAM STACK DENGAN KONDISI KHUSUS =======\n";
    cout << "Instruksi:\n";
    cout << "- Input >= 60: PUSH ke stack\n";
    cout << "- Input < 60: POP dari stack\n";
    cout << "- Input 999: Selesai\n\n";
    
    while (true) {
        cout << "Masukkan data: ";
        cin >> input;
        
        if (input == 999) {
            cout << "Proses selesai.\n";
            break;
        }
        else if (input >= 60) {
            if (!S.isFull()) {
                S.push(input);
            } else {
                cout << "Stack Penuh\n";
                break;
            }
        }
        else if (input < 60) {
            if (!S.isEmpty()) {
                int poppedValue = S.pop();
                cout << "Data yang diPOP: " << poppedValue << endl;
            } else {
                cout << "Stack Kosong\n";
                break;
            }
        }
    }
    
    return 0;
}