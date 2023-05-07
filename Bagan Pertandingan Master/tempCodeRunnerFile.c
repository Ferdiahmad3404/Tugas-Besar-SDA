#include <stdio.h>
#include <stdlib.h>

// Define struct untuk node
struct node {
  int data;
  struct node* left;
  struct node* right;
};

// Fungsi untuk membuat node baru
struct node* newNode(int data) {
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}


// Fungsi untuk print level order
void printLevelOrder(struct node* root) {
  // Jika root NULL, kembalikan
  if (root == NULL) return;
  
  // Buat queue untuk menyimpan node pada setiap level
  struct node* queue[1000];
  int front = 0;
  int rear = 0;

  // Masukkan root ke dalam queue
  queue[rear] = root;
  rear++;
  
  while (front < rear) {
    // Simpan jumlah node pada level saat ini
    int levelNodes = rear - front;
    
    // Selama jumlah node tersebut tidak sama dengan 0, lakukan langkah berikut:
    while (levelNodes > 0) {
      // Ambil node pertama dari queue dan print datanya
      struct node* node = queue[front];
      printf("%d ", node->data);
      
      // Jika node tersebut memiliki left child, masukkan ke dalam queue
      if (node->left != NULL) {
        queue[rear] = node->left;
        rear++;
      }
      
      // Jika node tersebut memiliki right child, masukkan ke dalam queue
      if (node->right != NULL) {
        queue[rear] = node->right;
        rear++;
      }
      
      // Kurangi jumlah node pada level saat ini
      levelNodes--;
      front++;
    }
  }
}

int main() {
  // Buat pohon binary dinamis dengan nilai node otomatis
  struct node* root = NULL;
  root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80);
  
  // Print pohon dengan level order
  printf("Level Order traversal of binary tree is: \n");
  printLevelOrder(root);
  
  return 0;
}
