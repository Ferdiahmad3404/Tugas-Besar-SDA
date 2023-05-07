#include "automaticBinary.c"
int main() {
    // Input jumlah tim
    int n;
    printf("Masukkan jumlah tim: ");
    scanf("%d", &n);

    // Input nama-nama tim
    char** names = (char**)malloc(sizeof(char*) * n);
    printf("Masukkan nama-nama tim:\n");
    for (int i = 0; i < n; i++) {
        names[i] = (char*)malloc(sizeof(char) * 50);
        printf("Tim %d: ", i + 1);
        scanf("%s", names[i]);
    }

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

    return 0;
}
