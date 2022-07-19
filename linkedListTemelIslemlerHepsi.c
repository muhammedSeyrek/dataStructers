#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	int data;
	struct node *next;
};

struct node *start = NULL;
struct node *temp = NULL;
struct node *end = NULL;

void basSil(){
	start = start -> next;
}

void sonSil(){
	end = start;
	while(end -> next -> next != NULL){
		end = end -> next;
	}
	end -> next = NULL;
}

void araSil(int veri){
	end = start;
	struct node *before = (struct node *) malloc(sizeof(struct node));
	struct node *after = (struct node *) malloc(sizeof(struct node));
	while(end -> next -> data != veri){
		end = end -> next;
	}
	before = end;
	after = end -> next -> next;
	free(end -> next);
	before -> next = after;
	
}

void basaEkle(int veri){
	struct node *basaGelecek = (struct node *) malloc(sizeof(struct node));
	basaGelecek -> data = veri;
	basaGelecek -> next = start;
	start = basaGelecek;
}
void arayaEkle(int x, int y){
	struct node *arayaEklenecek = (struct node *) malloc(sizeof(struct node));
	arayaEklenecek -> data = y;
	end = start;
	while(end -> next -> data != x){
		end = end -> next;
	}
	struct node *onune = (struct node *) malloc(sizeof(struct node));
	onune = end -> next;
	end -> next = arayaEklenecek;
	arayaEklenecek -> next = onune;
}
void sonaEkle(int veri){
	struct node *eklenecek = (struct node*) malloc(sizeof(struct node));
	eklenecek -> data = veri;
	eklenecek -> next = NULL;
	
	if(start == NULL){
		start = eklenecek;
	}else{
		end = start;
		while(end -> next != NULL){
			end = end -> next;
		}
		end -> next = eklenecek;
	}
}
int main(){
	while(1){
		int veri, veri2, islem, silEleman;
		printf("\n1 - Basa Ekle\n");
		printf("2 - Sona Ekle\n");
		printf("3 - Araya Ekle\n");
		printf("4 - Bastaki elemani sil\n");
		printf("5 - Sondaki elemani sil\n");
		printf("6 - Istenilen elemani sil\n");
		scanf("%d",&islem);
		if(islem < 4){
			printf("\nDeger giriniz = ");
			scanf("%d",&veri);
		}
		switch(islem){
			case 1:
				basaEkle(veri);
				break;
			case 2:
				sonaEkle(veri);
				break;
			case 3:
				printf("Hangi sayinin onune yerlestirilsin = ");
				scanf("%d",&veri2);
				arayaEkle(veri,veri2);
				break;
			case 4:
				basSil();
				break;
			case 5:
				sonSil();
				break;
			case 6:
				printf("Hangi elemani silmek istiyorsunuz : ");
				scanf("%d",&silEleman);
				araSil(silEleman);
				break;
		}
		end = start;
		while(end -> next != NULL){
			printf("%d => ",end -> data);
			end = end -> next;
		}
		printf("%d",end -> data);
	}
	return 0;
}
