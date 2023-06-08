#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct Node{
	int data;
	struct Node *next;
	
}Node;



int main(){
	FILE *file = fopen("katsayilar.txt", "w");
	fprintf(file, "7\n0\n2\n3\n8");
	fclose(file); //bunu koymasam islem yapmýyor. Cunku hem olusturup hem islem yapmak icin once
	//olusturdugum dosyayý kapatmam gerekiyor.
	Node *head = malloc(sizeof(struct Node));
	Node *last = head;		
	file = fopen("katsayilar.txt", "r");
	int number;
	int counter = 0;
	while(fscanf(file, "%d", &number) != EOF){
		if(head == NULL)
			head -> data = number;
		last -> next = malloc(sizeof(struct Node));
		last -> data = number;
		last = last -> next;
		counter++;
	}
	last -> next = NULL;
	last = head;
	int xN;
	printf("please enter x number = ");
	scanf("%d", &xN);
	int result = 0;
	while(last -> next != NULL){
		int power = pow(xN, counter);
		result += ((last -> data) * power);
		last = last -> next;
		counter--;
	}
		
	printf("Print = %d", result);
	
	fclose(file);
	return 0;
}
