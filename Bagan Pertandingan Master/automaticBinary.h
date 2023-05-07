#include <stdio.h>
#include <stdlib.h>

// Kamus Data
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

/***************************/
/*  S P E S I F I K A S I  */
/***************************/

struct Node* createNode(int data);
// Fungsi untuk membuat sebuah node baru

struct Node* createTree(int arr[], int n);
// Fungsi untuk membuat tree secara otomatis sesuai dengan jumlah node yang di inginkan (generator tree)

int getLevel(struct Node* root, int data, int level);
// Fungsi untuk mendapatkan level dari sebuah tree yang terbentuk

void printLevelOrder(struct Node* root);
// Prosedur untuk menampilkan binary tree dengan level order





