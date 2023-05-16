/*
Dekripsi : body program bagan pertandingan
Tanggal Pembuatan : 8/5/2023
Author : Ferdi, Hanif, Revandi.
*/

#include "automaticBinary.h"



void runProgram(){
        tampilanMenuUtama();
        inputOpsiMenu();
        switch (input)
        {
        case 1:
            system("cls");
            inputJumlahTim();
            char** names = (char**)malloc(sizeof(char*) * totalTim);
            printf("Masukkan nama-nama tim:\n");
            // for (int i = 0; i < totalTim; i++){
            //     names[i] = (char*)malloc(sizeof(char) * 50);
            //     printf("Tim %d: ", i + 1);
            //     scanf("%s", names[i]);
            // }
            for (size_t i = 0; i < totalTim; i++)
            {
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
            
            printf("%d", root->id);
            //printBinaryTree(root,0);
            printf("\n");
            printLevelOrder(root);
            printf("\n");
            
            for (int i = 0; i < totalTim; i++) {
                free(names[i]);
            }
            free(names); 
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

    
    //hapusSemuaTim()
}

// void createNamaTim(){
//     inputNamaTim();
//     char** names = (char**)malloc(sizeof(char*) * totalTim);
//     printf("Masukkan nama-nama tim:\n");
//     for (int i = 0; i < n; i++) {
//         names[i] = (char*)malloc(sizeof(char) * 50);
//         printf("Tim %d: ", i + 1);
//         scanf("%s", names[i]);
//     }
//     printf("\n\nAnda yakin ?\n1. Ya\n2. Kembali\n");
//     inputOpsiMenu();
//     switch (input)
//     {
//     case 1:
//         createBracket(&root,names);
//         printBracket(root,0);
//         break;
//     case 2:
//         runProgram();
//         break;
//     }
// }

void printBracket(address node, int level) {
    if (node == NULL) {
        return;
    }
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    if (node->left == NULL && node->right == NULL) {
        printf("%s %d\n", node->name, node->id);
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

// void hapusSemuaTim(char** names){
//     for (int i = 0; i < n; i++) {
//         free(names[i]);
//     }
//     free(names); 
// }


// Prosedur untuk menampilkan tampilan menu utama

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

/* Print nodes at a given level */
void printGivenLevel(address root, int level)
{
    if (root == NULL)
        return;
    if (level == 1){
        printf("%s ", root->name);
        printf("%d\n", root->skor);
    }
    else if (level > 1) {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}
 
void printLevelOrder(address root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++) {
        printGivenLevel(root, i);
        printf("\n");
    }
}

int height(address node)
{
    if (node == NULL)
        return 0;
    else {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        /* use the larger one */
        if (lheight > rheight) {
            return (lheight + 1);
        }
        else {
            return (rheight + 1);
        }
    }
}

// //  print tree
// void printBinaryTree(address node, int level)
// {
//     queue<Node*> treeLevel, temp;
//     treeLevel.push(root);
//     int counter = 0;
//     int height = heightOfTree(root) - 1;
//     double numberOfElements = pow(2, (height + 1)) - 1;
//     while (counter <= height) {
//         Node* removed = treeLevel.front();
//         treeLevel.pop();
//         if (temp.empty()) {
//             printSpace(numberOfElements
//                            / pow(2, counter + 1),
//                        removed);
//         }
//         else {
//             printSpace(numberOfElements / pow(2, counter),
//                        removed);
//         }
//         if (removed == nullptr) {
//             temp.push(nullptr);
//             temp.push(nullptr);
//         }
//         else {
//             temp.push(removed->left);
//             temp.push(removed->right);
//         }
//         if (treeLevel.empty()) {
//             cout << endl << endl;
//             treeLevel = temp;
//             while (!temp.empty()) {
//                 temp.pop();
//             }
//             counter++;
//         }
//     }
// }

//printspace
// void printSpace(double n, address removed)
// {
//     for (; n > 0; n--) {
//         cout << "\t";
//     }
//     if (removed == nullptr) {
//         cout << " ";
//     }
//     else {
//         cout << removed->data;
//     }
// }   


    
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

address searchAddress(address root, int oldname){
    //address lokasi;
    // if ((oldname == root->name) && (root != NULL)){
    //     lokasi = root;
    //     return lokasi;
    // }
    // else {
    //     //searchAddress(&(root->left));
    //     //searchAddress(&(root->right));
    // }
}