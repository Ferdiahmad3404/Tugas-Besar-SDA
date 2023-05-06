#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Fungsi untuk membuat sebuah node baru
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Fungsi untuk membuat binary tree secara otomatis
struct Node* createTree(int arr[], int n) {
    // Membuat root dari binary tree
    struct Node* root = createNode(arr[0]);
    
    // Membuat array dari node-node binary tree
    struct Node* nodes[n];
    nodes[0] = root;
    
    // Membuat binary tree secara otomatis
    int i = 0;
    while (i < n) {
        struct Node* curr = nodes[i];
        
        // Membuat child kiri dari node saat ini
        if (2*i+1 < n) {
            curr->left = createNode(arr[2*i+1]);
            nodes[2*i+1] = curr->left;
        }
        
        // Membuat child kanan dari node saat ini
        if (2*i+2 < n) {
            curr->right = createNode(arr[2*i+2]);
            nodes[2*i+2] = curr->right;
        }
        
        i++;
    }
    
    return root;
}

// Fungsi untuk menampilkan binary tree dengan level order
void printLevelOrder(struct Node* root) {
    if (root == NULL) return;
    
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    
    while (front != rear) {
        struct Node* curr = queue[front++];
        printf("%d ", curr->data);
        
        if (curr->left != NULL) queue[rear++] = curr->left;
        if (curr->right != NULL) queue[rear++] = curr->right;
    }
}


int main() {
    int counter, n;
    int *arr;
    printf("Input Jumlah Tim : ");
    scanf("%d", &counter);
    n = counter*2-1;
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
    
    struct Node* root = createTree(arr, n);
    
    printf("Binary Tree dengan Level Order: ");
    printLevelOrder(root);
    printf("\n");
    printf("Root = %d \n", root->data);
    printf("Root Left = %d \n", root->left->data);
    printf("Root Right = %d \n", root->right->data);
    printf("Root Left Left = %d \n", root->left->left->data);
    printf("Root Left Right = %d \n", root->left->right->data);
    printf("Root Right Left = %d \n", root->right->left->data);
    printf("Root Right Right = %d \n", root->right->right->data);

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
    
    

	return 0;
}