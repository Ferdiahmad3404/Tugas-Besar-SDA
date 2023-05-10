/*
Dekripsi : body program bagan pertandingan
Tanggal Pembuatan : 8/5/2023
Author : Ferdi, Hanif, Revandi.
*/

#include "automaticBinary.h"

void createBracket(address* node, char** names, int n) {
    if (n == 1) {
        (*node) = (struct Node*)malloc(sizeof(struct Node));
        (*node)->name = (char*)malloc(sizeof(char) * 50);
        strcpy((*node)->name, names[0]);
        (*node)->skor = -1;
        (*node)->left = NULL;
        (*node)->right = NULL;
    }
    else {
        
        (*node) = (struct Node*)malloc(sizeof(struct Node));
        (*node)->left = (struct Node*)malloc(sizeof(struct Node));
        (*node)->right = (struct Node*)malloc(sizeof(struct Node));
        createBracket(&((*node)->left), names, n / 2);
        createBracket(&((*node)->right), names + n / 2, n - n / 2);
    }
}

void printBracket(address node, int level) {
    if (node == NULL) {
        return;
    }
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    if (node->left == NULL && node->right == NULL) {
        printf("%s\n", node->name);
    }
    else {
        printf("[\n");
        printBracket(node->left, level + 1);
        printBracket(node->right, level + 1);
        for (int i = 0; i < level; i++) {
            printf("  ");
        }
        printf("]\n");
    }
}


// Prosedur untuk menampilkan tampilan menu utama
void tampilanMenuUtama(){
    printf("Bagan Pertandingan\n");
    printf("1. Buat Bagan\n");
    printf("2. Panduan\n");
    printf("99. Exit\n");
}

void printLevelOrder(address root) {
    if (root == NULL) {
        return;
    }
    address* queue = (struct Node**)malloc(sizeof(struct Node*) * 100);
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        address current = queue[front++];
        printf("%s \n", current->name);
        printf("%d ", current->skor);
        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
    free(queue);
}

void tampilanPanduan(){
    system("cls");
    printf("Panduan\n");
    printf("1. Tim yang berpartisipasi dalam turnamen atau kejuaraan harus lebih dari satu.\n");
    printf("2. Tim yang kalah dalam pertandingan akan langsung gugur.\n");
    printf("3. Tim yang bertahan sampai akhir keluar sebagai pemenang.\n");
    printf("4. Pembagian tim menggunakan sistem “Bye”.\n");
}

int inputan(){
    int opsi;
    printf("Pilih Opsi : ");
    scanf("%d",&opsi);
    return opsi;
}