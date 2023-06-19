#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node{
	int value;
	struct Node *next;
}Node;


void createCircuit(Node *head, Node *iter){
	int count = 10;
	while(count != 0){
		if(head == NULL)
			head -> value = rand() % 100;
		iter -> next = malloc(sizeof(Node));
		iter -> value = rand() % 100;
		iter = iter -> next;
		count--;
	}
	iter -> next = NULL;
	iter = head;
}

float print(Node *head, Node *iter){
	float result = 0; 
	int temp = 1, count = 1, index = 1;
	while(iter -> next != NULL){
		float top = 1.0, bottom = 0;
		while(count != 0){
			printf("R%d -> %d ", index, iter -> value);
			top *= iter -> value;
			bottom += iter -> value;
			iter = iter -> next;
			count--;
			index++;
		}
		result += (top / bottom);
		printf("\n");
		temp++;
		count = temp;
	}
	iter = head;
	return result;
}

void update(Node *head, Node *iter, int index, int data){
	for(int i = 0; i < index - 1; i++) {
		iter = iter -> next;
	}
	
	iter -> value = data;
	iter = head;
}

float singleRes(Node *head, Node *iter, int index){
	float result = 0, top = 1.0, bottom = 0;
	int temp = 1, count = 1, i = 0;
	while(iter -> next != NULL && i < index){
		top = 1.0, bottom = 0;
		while(count != 0){
			top *= iter -> value;
			bottom += iter -> value;
			iter = iter -> next;
			count--;
			i++;
		}
		result += (float)(bottom / top);
		temp++;
		count = temp;
	}
	iter = head;
	return result;
}

int printRn(Node *head, Node *iter, int index){
	float result = 0, top = 1.0, bottom = 0;
	int temp = 1, count = 1, i = 0, value;
	while(iter -> next != NULL && i < index - 1){
		iter = iter -> next;
		i++;
	}
	value = iter -> value;
	iter = head;
	return value;
}


int main(){
	srand(time(NULL));
	Node *head = malloc(sizeof(Node));
	Node *iter = head;
	createCircuit(head, iter);
	int volt = rand() % 100;
	char quit = 'n';
	int choose;	
	float resistance = print(head, iter);
	while(quit != 'q'){
		printf("\t\t\t\t\t\tBu devredeki volt = %d\n\n", volt);
		printf("\n1-Hesapla..\n2-Deger Guncelle..\n\n");
		printf("Secim = ");
		scanf("%d", &choose);
		if(choose == 1){
			printf("Rth = %.2f\n", resistance);
			printf("Resistors...\n");
			for(int i = 1; i <= 10; i++){
				printf("R%2d = %3d\t", i, printRn(head, iter, i));
				printf("I%2d = %3.2f\t", i, singleRes(head, iter, i));
				printf("V%2d = %3.2f\t", i, (float)volt / singleRes(head, iter, i));
				printf("P%2d = %3.2f\n", i, singleRes(head, iter, i) * (float)volt);
			}
			printf("\n");
			
			
		}
		else if(choose == 2){
			printf("Hangi R direnci degistirilecek = ");
			int change;
			scanf("%d", &change);
			printf("Hangi deger ile guncellemek istersiniz = ");
			int number;
			scanf("%d", &number);
			update(head, iter, change, number);
		}
		
		resistance = print(head, iter);
		printf("\n\n(q)-Cikis Yap (Devam icin -> ('n'))\n\n");
		scanf(" %c", &quit);
	}
	printf("R = %.2f", resistance);
	printf("\n\nTesekkurler...");
	
}
