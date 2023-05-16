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
            system("cls");
            createBracket(&root,names,totalTim);
            for (int i = 0; i < totalTim; i++) {
                free(names[i]);
            }
            free(names);
                do{
                    printBracket(root,0);
                    tampilanEditSkor();
                    inputOpsiMenu();
                    if (input == 1)
                    {
                        char* name = "Ferdi";
                            char* namess = "Jeihan";
                            int skor;
                            // printf("\nMasukkan nama tim yang ingin di edit : ");
                            // scanf("%s", name);
                            printf("\n Pememang : %s\n",root->name);
                            editScoreByName(root,name,10);
                            printBracket(root,0);
                            editScoreByName(root,namess,11);
                            updateParentNode(root,name);
                            printBracket(root,0);

                            system("pause");
                    } else{
                        input = 0;
                        
                    }
                    
                } while ( root->skor == -1);

            
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

address searchParentByChildName(address root, char* name) {
    if (strcmp(root->right->name, name) == 0) {
        return root;
    }

    if (strcmp(root->left->name, name) == 0) {
        return root;
    }

    if (strcmp(name, root->left->name) < 0) {
        return searchParentByChildName(root->left, name);
    } else if(strcmp(name, root->right->name) < 0){
        return searchParentByChildName(root->right, name);
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

void updateParentNode(address root, char* name) {
    address parent = searchParentByChildName(root, name);
    int leftScore;
    int rightScore;
    if (parent->right->skor != -1 && parent->left->skor != -1)
    {
        if (parent == NULL ) {
            return; // Tidak dapat memperbarui jika parent atau parent anak tidak ada
        }
        if(parent->left != NULL && parent->right != NULL){
            leftScore = parent->left->skor;
            rightScore = parent->right->skor;
        } else if (parent->left == NULL && parent->right != NULL){
            leftScore = 0;
            rightScore = parent->right->skor;
        } else if (parent->left != NULL && parent->right == NULL){
            leftScore = parent->left->skor;
            rightScore = 0;
        }

        if (leftScore > rightScore ) {
            parent->name = parent->left->name; // Mengisi nama parent parent dengan nama parent anak sebelah kiri
        } else if (leftScore < rightScore ) {
            parent->name = parent->right->name; // Mengisi nama parent parent dengan nama parent anak sebelah kanan
        }
    }
    
    
}
