#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

class Stack {
private:
    int data[MAX_SIZE];
    int top;

public:
    Stack() {
        // Mengisi stack dengan data yang sudah ada
        top = -1;
        for (int i = 0; i < MAX_SIZE; i++) {
            top++;
            data[top] = (i + 1) * 20; // Data 
        }
    }

    bool isEmpty() {
        return top == -1;
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
    
    cout << "====== PROGRAM POP SAMPAI STACK KOSONG ======\n";
    
    // POP sampai stack kosong
    while (!S.isEmpty()) {
        int poppedValue = S.pop();
        cout << "Data yang di-POP: " << poppedValue << endl;
    }
    
    cout << "Stack sekarang kosong.\n";
    return 0;
}