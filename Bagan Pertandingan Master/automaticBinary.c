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



// Prosedur untuk menampilkan menu utama
void menuUtama(){
    int inProgram, input;
    inProgram = 1;
    
    while (inProgram == 1)
        {
            printf("\n1. Enque Q1\n2. Deque Q1\n3. Add First N1\n4. Add Last N1\n5. Add After N1\n6. Delete First N1\n7. Exit\n");
            scanf("%d",&input);
    
            switch (input)
            {
            case 1:
                break;

            case 2:
                break;

            case 3:
                break;

            default:
                break;
            }
            printf("\n\n");
        }
}
