#include "automaticBinary.h"

void createBracket(struct Node** node, char** names, int n) {
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

void printBracket(struct Node* node, int level) {
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

void printLevelOrder(struct Node* root) {
    if (root == NULL) {
        return;
    }
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * 100);
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        struct Node* current = queue[front++];
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

// Prosedur untuk memilih menu di menu utama
void pilihTampilanMenu(struct Node** node, char** names, int n){
    int input;
    scanf("%d", &input);
   
}

int inputan(){
    int opsi;
    printf("Pilih Opsi : ");
    scanf("%d",&opsi);
    return opsi;
}