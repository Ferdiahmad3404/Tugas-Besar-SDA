#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Node {
    char* name;
    struct Node* left;
    struct Node* right;
};

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

int main() {
    // Input jumlah tim
    int n;
    printf("Masukkan jumlah tim: ");
    scanf("%d", &n);

    // Input nama-nama tim
    char** names = (char**)malloc(sizeof(char*) * n);
    printf("Masukkan nama-nama tim:\n");
    for (int i = 0; i < n; i++) {
        names[i] = (char*)malloc(sizeof(char) * 50);
        printf("Tim %d: ", i + 1);
        scanf("%s", names[i]);
    }

    // Buat pohon dan bagan pertandingan
    struct Node* root = NULL;
    createBracket(&root, names, n);

    // Cetak bagan pertandingan dalam bentuk bracket
    printf("Bagan Pertandingan:\n");
    printBracket(root, 0);
    printf("\n");

    // Hapus semua node pada pohon
    while (root != NULL) {
        struct Node* temp = root;
        root = NULL;
        free(temp);
    }

    // Hapus semua nama tim dari memori
    for (int i = 0; i < n; i++) {
        free(names[i]);
    }
    free(names);

    return 0;
}
