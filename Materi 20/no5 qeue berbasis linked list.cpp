// file: queue_linked_list.cpp
#include <iostream>
using namespace std;

struct QueueNode {
    int data;
    QueueNode* next;
    
    QueueNode(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    QueueNode* front;
    QueueNode* rear;
    int size;
    
public:
    Queue() : front(nullptr), rear(nullptr), size(0) {
        cout << "Queue dibuat (kosong)" << endl;
    }
    
    void enqueue(int value) {
        QueueNode* newNode = new QueueNode(value);
        
        if (!rear) {
            // Queue kosong
            front = rear = newNode;
            cout << "\n[ENQUEUE] " << value << " masuk antrian" << endl;
            cout << "  → " << value << " menjadi FRONT dan REAR" << endl;
        } else {
            // Tambah di belakang
            rear->next = newNode;
            rear = newNode;
            cout << "\n[ENQUEUE] " << value << " masuk antrian" << endl;
            cout << "  → " << value << " menjadi REAR baru" << endl;
        }
        
        size++;
        displayQueue();
    }
    
    void dequeue() {
        if (!front) {
            cout << "\n[DEQUEUE] Queue kosong! Tidak bisa dequeue." << endl;
            return;
        }
        
        QueueNode* temp = front;
        int removedValue = front->data;
        
        cout << "\n[DEQUEUE] " << removedValue << " keluar antrian" << endl;
        
        if (front == rear) {
            // Hanya satu elemen
            front = rear = nullptr;
            cout << "  → Queue menjadi kosong" << endl;
        } else {
            // Lebih dari satu elemen
            front = front->next;
            cout << "  → " << front->data << " menjadi FRONT baru" << endl;
        }
        
        delete temp;
        size--;
        displayQueue();
    }
    
    void displayQueue() {
        cout << "Status Antrian:" << endl;
        cout << "Front → ";
        
        if (!front) {
            cout << "[kosong]";
        } else {
            QueueNode* temp = front;
            while (temp) {
                cout << "[" << temp->data << "]";
                if (temp->next) cout << " → ";
                temp = temp->next;
            }
        }
        
        cout << " ← Rear" << endl;
        cout << "Size: " << size << " elemen" << endl;
        
        // Visualisasi horizontal
        if (front) {
            cout << "Visual: ";
            QueueNode* temp = front;
            while (temp) {
                cout << "| " << temp->data << " |";
                if (temp->next) cout << " ← ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    
    void peek() {
        if (front) {
            cout << "Elemen terdepan (peek): " << front->data << endl;
        } else {
            cout << "Queue kosong, tidak ada elemen terdepan" << endl;
        }
    }
    
    void simulateQueue() {
        cout << "\n=== SIMULASI ANTRIAN BANK ===" << endl;
        cout << "Nasabah dengan nomor antrian masuk dan keluar" << endl;
        
        enqueue(101); // Nasabah 101
        enqueue(102); // Nasabah 102
        enqueue(103); // Nasabah 103
        
        cout << "\n--- Pelayanan dimulai ---" << endl;
        peek();
        dequeue(); // Nasabah 101 dilayani
        
        cout << "\n--- Nasabah baru datang ---" << endl;
        enqueue(104);
        enqueue(105);
        
        cout << "\n--- Pelayanan dilanjutkan ---" << endl;
        peek();
        dequeue(); // Nasabah 102
        dequeue(); // Nasabah 103
        dequeue(); // Nasabah 104
        
        cout << "\n--- Sisa antrian ---" << endl;
        peek();
        dequeue(); // Nasabah 105
        
        cout << "\n--- Coba dequeue saat kosong ---" << endl;
        dequeue();
    }
    
    ~Queue() {
        cout << "\nMembersihkan queue..." << endl;
        while (front) {
            dequeue();
        }
    }
};

int main() {
    cout << "QUEUE BERBASIS LINKED LIST" << endl;
    cout << "===========================" << endl;
    
    Queue q;
    
    cout << "\n=== DEMO OPERASI DASAR ===" << endl;
    
    q.displayQueue();
    
    cout << "\n1. Enqueue beberapa elemen:" << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    
    cout << "\n2. Dequeue satu elemen:" << endl;
    q.dequeue();
    
    cout << "\n3. Enqueue elemen baru:" << endl;
    q.enqueue(40);
    q.enqueue(50);
    
    cout << "\n4. Dequeue beberapa elemen:" << endl;
    q.dequeue();
    q.dequeue();
    
    cout << "\n=== SIMULASI ANTRIAN ===" << endl;
    Queue bankQueue;
    bankQueue.simulateQueue();
    
    return 0;
}