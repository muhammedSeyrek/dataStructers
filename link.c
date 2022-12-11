#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	char* name[20];
	char* surName[20];
	char* jobs[20];
	struct Node *next;
}Node;
	Node *head = NULL;
void print(){
	Node *iter = head;
	while(iter != NULL){
		puts(iter -> name);
		puts(iter -> surName);
		puts(iter -> jobs);
		iter = iter -> next;
	}
}
void addPerson(){
	Node *iter = head;
	Node *elements = malloc(sizeof(Node));
	printf("Name, Surname, Jobs\n");
	gets(elements -> name);
	gets(elements -> surName);
	gets(elements -> jobs);
	elements -> next = NULL;
	if(head == NULL){
		head = elements;
	}
	else{
		while(iter -> next != NULL){
			iter = iter -> next;
		}
		iter -> next = elements;
		iter = elements;
	}
}
int main(){
	addPerson();
	addPerson();
	print();	
	return 0;
}
