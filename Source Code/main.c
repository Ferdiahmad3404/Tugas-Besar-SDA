#include "body.c"

int main(){
	
	address Tree;
	Tree = nil;
	CreateTree(&Tree);
	printf("\nTraversal Pre Order : ");
	PreOrder(Tree);
	printf("\nTraversal In Order : ");
	InOrder(Tree);
	printf("\nTraversal Post Order : ");
	PostOrder(Tree);
	printf("\nTraversal Level Order : ");
	Level_order(Tree, nbElmt(Tree));
	char str[]="";
	printf("\n\n");
	PrintTree(Tree, str);
	printf("\nJumlah node pada tree ada : %d", nbElmt(Tree));
	printf("\nJumlah daun pada tree ada : %d", nbDaun(Tree));
	printf("\nKedalaman tree adalah : %d", Depth(Tree));
	printf("\nDerajat 'b' adalah : %d", Derajat(Tree, 'b'));
	printf("\njumlah anak dari node 'a' adalah : %d", Degree(Tree,'A'));
	
	boolean ketemu = false;
	char cari;
	printf("\n\nCari elemen bernilai : ");
	scanf(" %c", &cari);
	ketemu = Search(Tree, cari);
	if (ketemu == true){
		printf("elemen bernilai %c ditemukan", cari);
	}
	else{
		printf("elemen bernilai %c tidak ditemukan", cari);
	}
	
	address P = NSearch(Tree, 'd');
	printf("\nHuruf 'd' berada pada address %p", P);
	
	printf("\n\nelemen a ada pada level %d", Level(Tree, 'a'));
	printf("\nelemen b ada pada level %d", Level(Tree, 'b'));
	printf("\nelemen c ada pada level %d", Level(Tree, 'c'));
	printf("\nelemen d ada pada level %d", Level(Tree, 'd'));
	printf("\nelemen e ada pada level %d", Level(Tree, 'e'));
	printf("\nelemen f ada pada level %d", Level(Tree, 'f'));
	printf("\nelemen g ada pada level %d", Level(Tree, 'g'));
	printf("\nelemen h ada pada level %d", Level(Tree, 'h'));
	printf("\nelemen i ada pada level %d", Level(Tree, 'i'));
	printf("\nelemen j ada pada level %d", Level(Tree, 'j'));
	
	return 0;
}
