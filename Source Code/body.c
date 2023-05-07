#include "nbtrees.h"


/**** Manajemen Memory ****/
address Alokasi (int X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi gagal, mengirimkan nil */
/* Author: Mahardika Pratama
	Nim	: 221524055*/

{
	 /* Kamus Lokal */
	 address P;
	 /* Algoritma */
	 P = (address) malloc (sizeof (nbtree));
	 if (P != nil)		/* Alokasi berhasil */
	 {
		P->id = X;
        P->info = nil;
        P->skor = nil;
		P->left = nil;
		P->right = nil;
		P->parent = nil;
	 }
	 return (P);
}

void DeAlokasi (address P)
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */
/* Author: Mahardika Pratama
	Nim	: 221524055*/

{
	if (P != nil)
	{
		free (P);
	}
}

void CreateTree(address *root, int TotalTim)
/* IS : Tree belum terbuat
    FS : Tree sudah terbuat
    Author: Revandi
	Nim	: 221524056
*/
{	
	address P, Q, X;
	infotype name, parent;
	infotype confirm;
	int i;
	
    int Tim = 0;
	i = 1;
	
	while (Tim != TotalTim*2){
    	if (IsEmpty(*root)){
    		*root = Alokasi(Tim);
        } else{
        	X = Alokasi(Tim);
        	//vvv Otomatis mencari parentnya vvv

            //   //
            if(Search(*root, parent)){
				P = NSearch(*root,parent);
            	if (P != nil){
            		if (P->info != X->info){
	            		X->parent = P;
	            		if(P->left == nil){
	            			P->left = X;
						}else{
							if(P->left->right != nil){
								Q = P->left;
								while (Q->right != nil){
									Q = Q->right;
								}
								Q->right = X;
							}else{
								P->left->right = X;
							}
						}
					}else{
						printf("Tidak bisa menjadi parent diri sendiri...\n");
	                    i--;
					}		
				}
			}else{
				printf("Parent tidak ditemukan...\n");
                i--;
			}
		}
		i++;
		printf("Tambah node lagi ? (y/n) : ");
		scanf(" %c", &confirm);
	}
}

boolean IsEmpty(address X){
/* Mengirimkan true jika Isi_Tree KOSONG */
/*Author : Keanu Rayhan Harits */
/*Nim : 221524043 */

    if(X == nil){
        return true;
    }
    return false;
}


void PreOrder (address P){
/* Traversal PreOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara PreOrder : Parent, fs, nb */
/*Author : Banteng Harisantoso */
/*Nim : 221524036 */

    boolean resmi;
    address bantu;
    bantu = P;
    if(P != nil){
        printf("%c ", P->info);
        PreOrder(P->left);
        PreOrder(P->right);
    }
}

void InOrder(address P){
/* Traversal InOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara InOrder : fs, Parent, Sisa anak lain */
/*Author : Mochamad Fathur Rabbani */
/*Nim : 221524045 */

    address Pcur = P;   
    boolean Resmi = true;
    int level = 0;
    while(Pcur != NULL)
    {
      	if (Pcur->left != nil && Resmi)
      	{
        	Pcur = Pcur->left;
      	} else {
        	if (Resmi)
        	{
        		printf("%c ",Pcur->info);
        	}
        	address parent = Pcur->parent;
        	if (parent != nil && Pcur == parent->left){
        		printf("%c ", parent->info);
        	}

        	if (Pcur->right != NULL)
        	{
            	Resmi = true;
            	Pcur = Pcur->right;
        	} else {
            	Resmi = false;
            	Pcur = Pcur->parent;
        	} 
      	}        
    }
}

void PostOrder(address P) {
/* Traversal PostOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara PostOrder :  fs, nb, Parent */
/*Author : Reza Maulana Aziz */
/*Nim : 221524057 */

  	if (P != nil) {
    	PostOrder(P->left);
    	printf("%c ", P->info);
      	PostOrder(P->right);
  	}
}

void Level_order(address X, int Maks_node)
/* Traversal LevelOrder */
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditampilkan secara Level Order */
/*Author : Niqa Nabila Nur Ihsani */
/*Nim : 221524054 */

{
	if (IsEmpty(X)) {
        printf("Tree kosong!\n");
        return;
    }
    
    address Q[Maks_node];
    int front = 0, rear = 0;
    Q[rear++] = X;
    
    while (front != rear) {
        address curr = Q[front++];
        printf("%c ", curr->info);
        
        address child = curr->left;
        while (child != nil) {
            Q[rear++] = child;
            child = child->right;
        }
    }
}

void PrintTree(address P, char childPtr[]){
/* IS : P terdefinisi */
/* FS : Semua simpul P sudah ditulis ke layar */
/*Author : Muhamad Fahri Yuwan Dwi Putra */
/*Nim : 221524047 */

    char tempChildPtr[255];
    strcpy(tempChildPtr, childPtr);
    strcat(tempChildPtr, "-");
    if (P!=nil){
        printf("%s%c\n",childPtr,P->info);
        PrintTree(P->left,tempChildPtr);
        PrintTree(P->right,childPtr);
    }
}

boolean Search (address P, infotype X){
/* Mengirimkan true jika ada node dari P yang bernilai X */
/*Author : Mahardika Pratama */
/*Nim : 221524044 */

    if (P == nil) {
    	return false;
    } else if (P->info == X) {
        return true;
    } else {
        address child = P->left;
        while (child != nil) {
            address result = NSearch(child, X);
            if (result != nil) {
                return true;
            }
            child = child->right;
        }
        return false;
    }
}

address NSearch(address P, infotype X) {
/* Mengirimkan address node jika ada node dari P yang bernilai X */
/*Author : Mahardika Pratama */
/*Nim : 221524044 */ 

    if (P == nil) {
        return nil;
    } else if (P->info == X) {
        return P;
    } else {
        address child = P->left;
        while (child != nil) {
            address result = NSearch(child, X);
            if (result != nil) {
                return result;
            }
            child = child->right;
        }
        return nil;
    }
}

int nbElmt(address P) {
/* Mengirimkan banyak elemen (node) di pohon non biner P */
/*Author : Zahran Anugerah Rizqullah */
/*Nim : 221524063 */   

  	if (IsEmpty(P)) {
    	return 0;
  	}
  	else {
  		return nbElmt(P->left) + nbElmt(P->right) + 1; 
  	}
}


int nbDaun(address X){
/* Mengirimkan banyak daun (node) pohon non biner P */
/*Author : Arnanda Prasatya */
/*Nim : 221524034 */   

    /* Kamus Data */
    address Pcur;
    boolean Resmi;
    int Daun;
        
    /* Algoritma */
    Pcur = X; // Pcur sama-sama menunjuk root.
    Resmi = true;
    Daun = 0;
        
    while (Pcur != nil){
        if (Pcur->left != nil && Resmi){
            Pcur = Pcur->left;
        } else {
            if (Pcur->left == nil){
                Daun++;
            }
            if (Pcur->right != nil){
                Pcur = Pcur->right;
                Resmi = true;
            } else {
                Pcur = Pcur->parent;
                Resmi = false;
            }
        }
    }
    return Daun;
}


int getLevelUntil(address P, infotype X, int level) {
// referensi https://www.geeksforgeeks.org/get-level-of-a-node-in-a-binary-tree/// referensi https://www.geeksforgeeks.org/get-level-of-a-node-in-a-binary-tree/
/*Author : Farhan Muhammad Luthfi */
/*Nim : 221524039 */    
    if (P == NULL) {
        return -1;
    } 
    if (P->info == X) {
        return level;
    }
    int downlevel = getLevelUntil(P->left, X, level+1);
    if (downlevel != -1) {
        return downlevel;
    }
    downlevel = getLevelUntil(P->right, X, level);
    return downlevel;
}

int Level(address P, infotype X) {
/* Mengirimkan level dari node X yang merupakan salah satu simpul */ 
/* dr pohon P. Akar (P) levelnya adalah 0. Pohon tidak kosong */
// referensi https://www.geeksforgeeks.org/get-level-of-a-node-in-a-binary-tree/// referensi https://www.geeksforgeeks.org/get-level-of-a-node-in-a-binary-tree/
/*Author : Farhan Muhammad Luthfi */
/*Nim : 221524039 */    
	return getLevelUntil(P, X, 0);
}



int Depth (address P) {
/* Pohon Biner mungkin Kosong, mengirimkan 'depth' yaitu tinggi dari Pohon */
/* Basis : Pohon Kosong, tingginya Nol */
/*Author : Muhammad Hanif */
/*Nim : 221524050 */

    address Pcur = P; //untuk firstnya atau akarnya
    int resmi = 1;
    int hasil = 0;
    int temp = 0;
        
    do {
        if(Pcur->left != NULL && resmi) {
            Pcur = Pcur->left;
            temp++;
        } else {
            if(Pcur->right != NULL) {
                Pcur = Pcur->right;
                resmi = 1;
            } else {
                Pcur = Pcur->parent;
                resmi = 0;
                if(temp > hasil) hasil = temp;
                temp--;
            }
        }
    } while(Pcur->parent != NULL);
    return hasil;
}

int Max(infotype Data1, infotype Data2)
/* Mengirimkan Nilai terbesar dari dua data */
/*Author : Yusuf */
/*Nim : 221524062 */
{
    if (Data1 > Data2)
    {
        return Data1;
    }
    else
    {
        return Data2;
    }
}

int Derajat(address P, infotype X){
    /* Pohon Non Biner mungkin Kosong, mengirimkan 'derajat' yaitu jumlah anak dari suatu node */
    /* Basis : Pohon Kosong, derajatnya Nol */
    /* Author: Jeihan Ilham Kr */
    /* Nim : 221524042 */

    if(Search(P,X) == true){
        address indxParent = NSearch(P,X);
        if(indxParent->left != nil){
            address child = indxParent->left;
            int numChild = 0;
            while(child != nil){
                numChild++;
                child = child->right;
            }
            return numChild;
        }
    }
    return 0;
}

int Degree (address P, infotype X){
/* Pohon Non Biner mungkin Kosong, mengirimkan 'degree' yaitu jumlah anak dari satu node */
/* Basis : Pohon Kosong, degreenya Nol */
/*Author : Faris Abulkhoir */
/*Nim : 221524040 */

    /*Kamus Data*/
    address tmp;
    int child = 0;
        
    if(IsEmpty(P)){
        return nil;
    } else {
        tmp = NSearch(P, X);
        if(tmp == NULL){
            return nil;
        } else {
            tmp = P;
            if(tmp->left != nil){
                child++;
                tmp = tmp->left;
                while(tmp->right != nil){
                    child++;
                    tmp = tmp->right;
                }
        	}
        }
    }
    return child;
}