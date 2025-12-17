#include <stdio.h>
#include <stdlib.h>

// Struktur node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Fungsi untuk membuat node baru
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk menampilkan linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("List kosong.\n");
        return;
    }
    
    Node* current = head;
    printf("Isi Linked List: ");
    
    // Karena circular, kita perlu berhenti ketika kembali ke head
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    
    printf("(kembali ke %d)\n", head->data);
}

// Fungsi untuk menambahkan node di awal
Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    
    if (head == NULL) {
        // Jika list kosong, node baru menunjuk ke dirinya sendiri
        newNode->next = newNode;
        printf("Memasukkan %d di awal (list sebelumnya kosong)\n", data);
        return newNode;
    }
    
    // Cari node terakhir
    Node* last = head;
    while (last->next != head) {
        last = last->next;
    }
    
    // Sisipkan di awal
    newNode->next = head;
    last->next = newNode;
    
    printf("Memasukkan %d di awal\n", data);
    return newNode;
}

// Fungsi untuk menambahkan node di akhir
Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    
    if (head == NULL) {
        // Jika list kosong, node baru menunjuk ke dirinya sendiri
        newNode->next = newNode;
        printf("Memasukkan %d di akhir (list sebelumnya kosong)\n", data);
        return newNode;
    }
    
    // Cari node terakhir
    Node* last = head;
    while (last->next != head) {
        last = last->next;
    }
    
    // Sisipkan di akhir
    last->next = newNode;
    newNode->next = head;
    
    printf("Memasukkan %d di akhir\n", data);
    return head;
}

// Fungsi untuk menghapus node dengan nilai tertentu
Node* deleteNode(Node* head, int key) {
    if (head == NULL) {
        printf("List kosong. Tidak dapat menghapus %d\n", key);
        return NULL;
    }
    
    Node* current = head;
    Node* prev = NULL;
    
    // Cari node yang akan dihapus
    do {
        if (current->data == key) {
            break;
        }
        prev = current;
        current = current->next;
    } while (current != head);
    
    // Jika node tidak ditemukan
    if (current->data != key) {
        printf("Node dengan nilai %d tidak ditemukan\n", key);
        return head;
    }
    
    // Jika hanya ada satu node
    if (current->next == head && current == head) {
        printf("Menghapus %d (satu-satunya node)\n", key);
        free(current);
        return NULL;
    }
    
    // Jika node yang dihapus adalah head
    if (current == head) {
        // Cari node terakhir
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        
        head = head->next;
        last->next = head;
        printf("Menghapus %d (node head)\n", key);
    } else {
        // Jika node yang dihapus bukan head
        prev->next = current->next;
        printf("Menghapus %d\n", key);
    }
    
    free(current);
    return head;
}

// Fungsi untuk menampilkan proses traverse
void traverseList(Node* head) {
    printf("\n--- Proses Traverse ---\n");
    
    if (head == NULL) {
        printf("List kosong. Tidak ada yang bisa ditraverse.\n");
        return;
    }
    
    Node* current = head;
    int count = 1;
    
    printf("Memulai traverse dari head (%d):\n", head->data);
    
    do {
        printf("Langkah %d: Mengunjungi node dengan nilai %d\n", count, current->data);
        current = current->next;
        count++;
    } while (current != head);
    
    printf("Traverse selesai. Kembali ke head (%d). Total node: %d\n\n", head->data, count-1);
}

// Fungsi untuk membebaskan memori
void freeList(Node* head) {
    if (head == NULL) return;
    
    Node* current = head;
    Node* nextNode;
    
    do {
        nextNode = current->next;
        free(current);
        current = nextNode;
    } while (current != head);
}

int main() {
    Node* head = NULL;
    
    printf("=========================================\n");
    printf("  IMPLEMENTASI CIRCULAR SINGLE LINKED LIST\n");
    printf("=========================================\n\n");
    
    // Demonstrasi insert
    printf("--- OPERASI INSERT ---\n");
    head = insertAtBeginning(head, 30);
    displayList(head);
    
    head = insertAtBeginning(head, 20);
    displayList(head);
    
    head = insertAtBeginning(head, 10);
    displayList(head);
    
    head = insertAtEnd(head, 40);
    displayList(head);
    
    head = insertAtEnd(head, 50);
    displayList(head);
    
    // Demonstrasi traverse
    traverseList(head);
    
    // Demonstrasi delete
    printf("--- OPERASI DELETE ---\n");
    head = deleteNode(head, 30); // Hapus node tengah
    displayList(head);
    
    head = deleteNode(head, 10); // Hapus node head
    displayList(head);
    
    head = deleteNode(head, 50); // Hapus node akhir
    displayList(head);
    
    // Traverse setelah delete
    traverseList(head);
    
    // Coba hapus node yang tidak ada
    head = deleteNode(head, 100);
    displayList(head);
    
    // Hapus semua node
    printf("\n--- MENGHAPUS SEMUA NODE ---\n");
    head = deleteNode(head, 20);
    displayList(head);
    
    head = deleteNode(head, 40);
    displayList(head);
    
    // Traverse list kosong
    traverseList(head);
    
    // Bebaskan memori
    freeList(head);
    
    return 0;
}