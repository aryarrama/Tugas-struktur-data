#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur data mahasiswa
typedef struct mahasiswa {
    char NIM[15];
    char NAMA[50];
    int NILAI;
    struct mahasiswa *next;
} Mahasiswa;

Mahasiswa *head = NULL;

// a. Program untuk mengisikan data baru (tersusun naik berdasarkan NILAI)
void insertData(char nim[], char nama[], int nilai) {
    Mahasiswa *newNode = (Mahasiswa*)malloc(sizeof(Mahasiswa));
    strcpy(newNode->NIM, nim);
    strcpy(newNode->NAMA, nama);
    newNode->NILAI = nilai;
    newNode->next = NULL;
    
    // Jika linked list kosong atau nilai newNode lebih kecil dari head
    if (head == NULL || newNode->NILAI < head->NILAI) {
        newNode->next = head;
        head = newNode;
        return;
    }
    
    // Mencari posisi yang tepat (tersusun naik berdasarkan NILAI)
    Mahasiswa *current = head;
    while (current->next != NULL && current->next->NILAI < newNode->NILAI) {
        current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
}

// b. Program untuk menampilkan data dengan NILAI sama dengan 90
void displayNilai90() {
    Mahasiswa *current = head;
    int found = 0;
    
    printf("\nData Mahasiswa dengan NILAI 90:\n");
    printf("--------------------------------\n");
    
    while (current != NULL) {
        if (current->NILAI == 90) {
            printf("NIM: %s, NAMA: %s, NILAI: %d\n", 
                   current->NIM, current->NAMA, current->NILAI);
            found = 1;
        }
        current = current->next;
    }
    
    if (!found) {
        printf("Tidak ada data dengan NILAI 90\n");
    }
    printf("--------------------------------\n");
}

// c. Program untuk menampilkan seluruh data
void displayAll() {
    Mahasiswa *current = head;
    
    printf("\nSeluruh Data Mahasiswa (Tersusun berdasarkan NILAI):\n");
    printf("----------------------------------------------------\n");
    
    if (current == NULL) {
        printf("Linked List kosong\n");
        return;
    }
    
    while (current != NULL) {
        printf("NIM: %s, NAMA: %s, NILAI: %d\n", 
               current->NIM, current->NAMA, current->NILAI);
        current = current->next;
    }
    printf("----------------------------------------------------\n");
}

// d. Program untuk menghapus data dengan NIM 2007140022 (SPESIFIK)
void deleteNIM2007140022() {
    Mahasiswa *current = head;
    Mahasiswa *prev = NULL;
    
    // Mencari data dengan NIM = 2007140022
    while (current != NULL && strcmp(current->NIM, "2007140022") != 0) {
        prev = current;
        current = current->next;
    }
    
    // Jika data tidak ditemukan
    if (current == NULL) {
        printf("Data dengan NIM 2007140022 tidak ditemukan\n");
        return;
    }
    
    // Jika data ditemukan di head
    if (prev == NULL) {
        head = current->next;
    } 
    // Jika data ditemukan di tengah atau akhir
    else {
        prev->next = current->next;
    }
    
    printf("Data dengan NIM 2007140022 berhasil dihapus:\n");
    printf("NIM: %s, NAMA: %s, NILAI: %d\n", 
           current->NIM, current->NAMA, current->NILAI);
    
    free(current);
}

// e. Program untuk menghitung nilai rata-rata kelas
float calculateAverage() {
    Mahasiswa *current = head;
    int total = 0, count = 0;
    
    if (current == NULL) {
        printf("Linked List kosong\n");
        return 0.0;
    }
    
    while (current != NULL) {
        total += current->NILAI;
        count++;
        current = current->next;
    }
    
    return (float)total / count;
}

// Fungsi untuk menampilkan menu
void displayMenu() {
    printf("\n=== MENU LINKED LIST MAHASISWA ===\n");
    printf("1. Tambah Data Mahasiswa\n");
    printf("2. Tampilkan Data dengan NILAI 90\n");
    printf("3. Tampilkan Semua Data\n");
    printf("4. Hapus Data dengan NIM 2007140022\n");  // DIUBAH
    printf("5. Hitung Rata-rata Kelas\n");
    printf("6. Keluar\n");
    printf("Pilihan: ");
}

// Fungsi utama
int main() {
    int choice;
    char nim[15], nama[50];
    int nilai;
    
    // Data contoh untuk testing
    insertData("2007140010", "Budi", 85);
    insertData("2007140022", "Siti", 90);  // Data yang akan dihapus
    insertData("2007140033", "Ahmad", 78);
    insertData("2007140044", "Dewi", 92);
    insertData("2007140055", "Rina", 90);
    
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Masukkan NIM: ");
                scanf("%s", nim);
                printf("Masukkan NAMA: ");
                scanf(" %[^\n]s", nama);
                printf("Masukkan NILAI: ");
                scanf("%d", &nilai);
                insertData(nim, nama, nilai);
                printf("Data berhasil ditambahkan\n");
                break;
                
            case 2:
                displayNilai90();
                break;
                
            case 3:
                displayAll();
                break;
                
            case 4:  // DIUBAH - langsung hapus NIM 2007140022
                deleteNIM2007140022();
                break;
                
            case 5:
                printf("Nilai rata-rata kelas: %.2f\n", calculateAverage());
                break;
                
            case 6:
                printf("Program selesai\n");
                break;
                
            default:
                printf("Pilihan tidak valid\n");
        }
    } while(choice != 6);
    
    return 0;
}