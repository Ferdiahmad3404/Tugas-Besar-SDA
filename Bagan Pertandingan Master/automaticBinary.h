/*
Dekripsi : header program bagan pertandingan
Tanggal Pembuatan : 8/5/2023
Author : Ferdi, Hanif, Revandi.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <math.h>

// Kamus Data
typedef struct Node * address;
typedef struct Node {
    char* name;
    int skor;
    address left;
    address right;
};



/***************************/
/*  S P E S I F I K A S I  */
/***************************/

void printLevelOrder(address node);

void createBracket(address* node, char** names, int n);
// Fungsi untuk membuat node yang membentuk menjadi tree / bracket secara otomatis sesuai dengan jumlah sebanyak n (generator tree)

int getLevel(address node, char* name, int level);
// Fungsi ini untuk mendapatkan level dari sebuah tree tersebut

void printBracket(address node, int level);
// Prosedur untuk menampilkan binary tree yang berbentuk bracket




