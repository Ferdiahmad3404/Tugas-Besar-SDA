#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Kamus Data
struct Node {
    char* name;
    struct Node* left;
    struct Node* right;
};

/***************************/
/*  S P E S I F I K A S I  */
/***************************/

void createBracket(struct Node** node, char** names, int n);
// Fungsi untuk membuat node yang membentuk menjadi tree / bracket secara otomatis sesuai dengan jumlah sebanyak n (generator tree)

int getLevel(struct Node* node, char* name, int level);
// Fungsi ini untuk mendapatkan level dari sebuah tree tersebut

void printBracket(struct Node* node, int level);
// Prosedur untuk menampilkan binary tree yang berbentuk bracket





