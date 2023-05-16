/*
Dekripsi : body program bagan pertandingan
Tanggal Pembuatan : 8/5/2023
Author : Ferdi, Hanif, Revandi.
*/

#include "automaticBinary.h"



void runProgram(){
        tampilanMenuUtama();
        inputOpsiMenu(&input);
        switch (input)
        {
        case 1:
            system("cls");
            inputJumlahTim();
            char** names = (char**)malloc(sizeof(char*) * totalTim);
            printf("Masukkan nama-nama tim:\n");
            for (int i = 0; i < totalTim; i++) {
                names[i] = (char*)malloc(sizeof(char) * 50);
                printf("Tim %d: ", i + 1);
                scanf("%s", names[i]);
            }
            printf("\n\nAnda yakin ?\n1. Ya\n2. Kembali\n");
            inputOpsiMenu();
            if (input == 2)
            {
                runProgram();
            }
            
            createBracket(&root,names,totalTim);
            printBracket(root,0);
            for (int i = 0; i < totalTim; i++) {
                free(names[i]);
            }
            free(names);

            char* name = "Ferdi";
            address lokasi = searchByName(root,name);
            editScoreByName(root,name,2);

            printBracket(root,0);

            inputOpsiMenu();
            break;
        case 2:
            tampilanPanduan();
            inputOpsiMenu();
            break;
        case 99:
            inProgram = 0;
            break;
        }
}


void createBracket(address* node, char** names, int totalTim) {
    
    if (totalTim == 1) {
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
        createBracket(&((*node)->left), names, totalTim / 2);
        createBracket(&((*node)->right), names + totalTim / 2, totalTim - totalTim / 2);
    }
}

void printBracket(address node, int level) {
    if (node == NULL) {
        return;
    }
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    if (node->left == NULL && node->right == NULL) {
        printf("%s %d\n", node->name, node->skor);
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

void tampilanMenuUtama(){
    system("cls");
    printf("Bagan Pertandingan\n");
    printf("[1] Buat Bagan\n");
    printf("[2] Panduan\n");
    printf("[99] Exit\n");
}

void tampilanPanduan(){
    system("cls");
    printf("Panduan\n");
    printf("[1] Tim yang berpartisipasi dalam turnamen atau kejuaraan harus lebih dari satu.\n");
    printf("[2] Tim yang kalah dalam pertandingan akan langsung gugur.\n");
    printf("[3] Tim yang bertahan sampai akhir keluar sebagai pemenang.\n");
    printf("[4] Pembagian tim menggunakan sistem “Bye”.\n");

    printf("0. Kembali\n");
}

void inputOpsiMenu(){
    printf("Pilih Opsi : ");
    scanf("%d",&input);
}

void inputJumlahTim(){
    printf("Masukkan jumlah tim: ");
    scanf("%d", &totalTim);
    if (totalTim < 2)
    {
        printf("Jumlah tim tidak boleh kurang dari 2 !!!");
        inputJumlahTim();
    }
    
    
}

address searchByName(address root, char* name) {
    if (root == NULL || strcmp(root->name, name) == 0) {
        return root;
    }

    if (strcmp(name, root->name) < 0) {
        return searchByName(root->left, name);
    } else {
        return searchByName(root->right, name);
    }
}


void editScoreByName(address root, char* name, int newScore) {
    address node = searchByName(root, name);
    if (node != NULL) {
        node->skor = newScore;
    } else {
        printf("Node dengan nama %s tidak ditemukan.\n", name);
    }
}



// void editTree(address *root)
// {
//     address change;
//     int namaTim, skor;

//     if ((*root) == NULL)
//     {
//         printf("\nTree Belum Dibuat!\n");
//     }
//     else
//     {
//     ulang:
//         printf("DAFTAR PARENTS\n");
//         listParent(*root);
//         printf("\nMasukkan Nama Yang Ingin Diedit: ");
//         scanf(" %s", &namaTim);
//         change = searchAddress(*root, namaTim);
//         if (change != NULL)
//         {
//             printf("Masukan skor: ");
//             scanf(" %c", &skor);
//             change->info = skor;
//             printf("\nUpdate Skor Sukses!\n");
//         }
//         else
//         {
//             printf("\nTim Tidak Ada, Ulangi. \n");
//             system("pause");
//             goto ulang;
//         }
//     }
// }
