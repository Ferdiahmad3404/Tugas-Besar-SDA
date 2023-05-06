#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data) {
    struct node *newNode = (struct node *) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(struct node **root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }
    struct node *temp = *root;
    while (1) {
        if (data <= temp->data) {
            if (temp->left == NULL) {
                temp->left = createNode(data);
                return;
            }
            temp = temp->left;
        } else {
            if (temp->right == NULL) {
                temp->right = createNode(data);
                return;
            }
            temp = temp->right;
        }
    }
}

int main() {
    struct node *root = NULL;

    int n, i, x;
    printf("Enter the number of elements to be inserted: ");
    scanf("%d", &n);

    printf("Enter the elements to be inserted: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        insert(&root, x);
    }

    printf("\nLevel Order Traversal of the Binary Tree:\n");
    struct node *currentLevel[100], *nextLevel[100];
    int currentSize = 1, nextSize = 0;
    currentLevel[0] = root;
    while (currentSize > 0) {
        struct node *temp = currentLevel[0];
        printf("%d ", temp->data);
        currentSize--;
        if (temp->left != NULL) {
            nextLevel[nextSize] = temp->left;
            nextSize++;
        }
        if (temp->right != NULL) {
            nextLevel[nextSize] = temp->right;
            nextSize++;
        }
        if (currentSize == 0) {
            printf("\n");
            currentSize = nextSize;
            nextSize = 0;
            struct node *tempArr[100];
            for (i = 0; i < currentSize; i++) {
                tempArr[i] = currentLevel[i];
            }
            for (i = 0; i < nextSize; i++) {
                currentLevel[i] = nextLevel[i];
            }
            for (i = 0; i < currentSize; i++) {
                tempArr[i] = NULL;
            }
        }
    }
    return 0;
}
