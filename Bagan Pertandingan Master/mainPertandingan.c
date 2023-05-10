/*
Dekripsi : main program bagan pertandingan
Tanggal Pembuatan : 8/5/2023
Author : Ferdi, Hanif, Revandi.
*/

#include "automaticBinary.c"
int main() {
    int inProgram = 1;
    int input = 0;

    jump: while (inProgram == 1)
    
    {
        tampilanMenuUtama();
        input = inputan();
        switch (input){
        case 1:
            system("cls");
                // Input jumlah tim
            int n;
            input: printf("Masukkan jumlah tim: ");
            scanf("%d", &n);

            // Input nama-nama tim
            if (n<2)
            {
                printf("Tidak bisa membuat bagan pertandingan harus lebih dari 1 tim\n");
                goto input;
            }
            
            char** names = (char**)malloc(sizeof(char*) * n);
            printf("Masukkan nama-nama tim:\n");
            for (int i = 0; i < n; i++) {
                names[i] = (char*)malloc(sizeof(char) * 50);
                printf("Tim %d: ", i + 1);
                scanf("%s", names[i]);
            }
            printf("Anda yakin ?\n1. Ya\n2. Kembali\n");
            input = inputan();
            system("cls");
                    
            switch (input)
            {
            case 1:
                    // Buat pohon dan bagan pertandingan
                struct Node* root = NULL;
                createBracket(&root, names, n);

                // Cetak bagan pertandingan dalam bentuk bracket
                printf("Bagan Pertandingan:\n");
                printBracket(root, 0);
                printf("\n");

                // Hapus semua node pada pohon
                while (root != NULL) {
                    struct Node* temp = root;
                    root = NULL;
                    free(temp);
                }

                // Hapus semua nama tim dari memori
                for (int i = 0; i < n; i++) {
                    free(names[i]);
                }
                free(names);  
                break;
            case 0:
                while (root != NULL) {
                    struct Node* temp = root;
                    root = NULL;
                    free(temp);
                }

                // Hapus semua nama tim dari memori
                for (int i = 0; i < n; i++) {
                    free(names[i]);
                }
                free(names); 
                goto jump;

            default:
                goto jump;
            }
            break;
        case 2:
            tampilanPanduan();
            printf("\n 0. Kembali\n");
            input = inputan();
            
            if(input == 0){
                system("cls");
                goto jump;
            }

            break;
        case 99:
            exit(0);
            break;
        default:
            printf("Input tidak valid.\n");
            break;
        }
    }


    

    return 0;
}
