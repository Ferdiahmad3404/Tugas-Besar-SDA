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
            char** namaTim = (char**)malloc(sizeof(char*) * totalTim);
            printf("Masukkan nama-nama tim:\n");
            for (int i = 0; i < totalTim; i++) {
                namaTim[i] = (char*)malloc(sizeof(char) * 50);
                printf("Tim %d: ", i + 1);
                scanf("%s", namaTim[i]);
            }
            printf("\n\nAnda yakin ?\n1. Ya\n2. Kembali\n");
            inputOpsiMenu();
            if (input == 2)
            {
                runProgram();
            }
            system("cls");
            createBracket(&root,namaTim,totalTim);
            for (int i = 0; i < totalTim; i++) {
                free(namaTim[i]);
            }
            
            do  
            {
                printBracket(root,0);
                tampilanEditSkor();
                inputOpsiMenu();
                    if (input == 1)
                    {
                        char* tim1 = "Ferdi";
                        char* tim2 = "Hanif";
                        char* tim3 = "Yusuf";
                        char* tim4 = "Revandi";
                        printf("\nPememang : %s\n",root->name);
                        editScoreByName(root,tim1,3);
                        system("pause");
                        editScoreByName(root,tim2,2);
                        system("pause");
                        editScoreByName(root,tim3,2);
                        system("pause");
                        editScoreByName(root,tim4,1);
                        system("pause");
                        updateParentNode(root,tim1);
                        updateParentNode(root,tim3);
                        printBracket(root,0);    
                    } else{
                        input = 0;
                    }
            } while (strcmp(root->name, "TBD") == 0);
            printf("\nPememang : %s\n",root->name);
            system("pause");
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
        (*node)->name = "TBD";
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

void tampilanEditSkor(){
    printf("1. Edit Skor\n");
    printf("0. Exit\n");
}

address searchParentByChildName(address root, char* childName) {
    if (root == NULL) {
        return NULL; // Tidak dapat mencari jika root tidak ada
    }

    if ((root->left != NULL && strcmp(root->left->name, childName) == 0) ||
        (root->right != NULL && strcmp(root->right->name, childName) == 0)) {
        return root; // Node parent ditemukan: root merupakan parent dari child dengan nama yang cocok
    }

    address parent = searchParentByChildName(root->left, childName);
    if (parent == NULL) {
        parent = searchParentByChildName(root->right, childName);
    }

    return parent;
}


// address searchByName(address root, char* name) {
    
//     if (root == NULL || strcmp(root->name, name) == 0) {
//         return root;
//     }
//     printf("%s",name);
//     system("pause");
//     if (strcmp(name, root->name) != 0) {
//         searchByName(root->left, name);
//         searchByName(root->right, name);
//     }
// }
void editScoreByName(address root, char* name, int newScore) {
    address node = searchByName(root, name);

    if (node != NULL) {
        node->skor = newScore;
    }
}

void updateParentNode(address root, char* name) {
    address parent = searchParentByChildName(root, name);
    int leftScore;
    int rightScore;
    
        if (parent == NULL ) {
            return; // Tidak dapat memperbarui jika parent atau parent anak tidak ada
        }
        if (parent->left == NULL && parent->right == NULL)
        {
            return;
        }
        if (parent->left == NULL && parent->right->skor == -1)
        {
            leftScore = -1;
            rightScore = 0;
        } else if (parent->right == NULL && parent->left->skor == -1)
        {
            leftScore = 0;
            rightScore = -1;
        } else if (parent->right->skor == -1 && parent->left->skor == -1)
        {
            leftScore = parent->left->skor;
            rightScore = parent->right->skor;
        }

        if (leftScore > rightScore ) {
            parent->name = parent->left->name; // Mengisi nama parent parent dengan nama parent anak sebelah kiri
        } else if (leftScore < rightScore ) {
            parent->name = parent->right->name; // Mengisi nama parent parent dengan nama parent anak sebelah kanan
        }
    }

    
address searchByName(address root, char* name) {
    if (root == NULL) {
        return NULL; // Tidak dapat mencari jika root tidak ada
    }

    if (strcmp(root->name, name) == 0) {
        return root; // Node dengan nama yang cocok ditemukan
    }

    address foundNode = searchByName(root->left, name);
    if (foundNode == NULL) {
        foundNode = searchByName(root->right, name);
    }

    return foundNode;
}
