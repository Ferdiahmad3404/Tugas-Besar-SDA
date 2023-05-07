#include "automaticBinary.h"

void createBracket(struct Node** node, char** names, int n) {
    if (n == 1) {
        (*node) = (struct Node*)malloc(sizeof(struct Node));
        (*node)->name = (char*)malloc(sizeof(char) * 50);
        strcpy((*node)->name, names[0]);
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
void tampilanMenuUtama(struct Node** node, char** names, int n){
    printf("Bagan Pertandingan\n");
    printf("1. Buat Bagan\n");
    printf("2. Panduan\n");
    printf("99. Exit\n");
    pilihTampilanMenu(node, names, n);
}

// Prosedur untuk memilih menu di menu utama
void pilihTampilanMenu(struct Node** node, char** names, int n){
    int input;
    scanf("%d", &input);
    switch (input)
    {
    case 1:
        system("cls");
        createBracket(node, names, n);
        break;
    case 2:
        system("cls");
        printf("panduan\n");
        break;
    case 99:
        exit(0);
        break;
    default:
        printf("Input tidak valid.\n");
        break;
    }
}
