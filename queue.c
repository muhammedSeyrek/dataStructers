#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	char* name[20];
	char* surName[20];
	char* jobs[20];
	struct Node *next;
	struct Node *prev;
}Node;
	Node *rear = NULL;
	Node *front = NULL;
void dequeue(){
	Node *iter = rear;
	rear = rear -> next;
	free(iter);		
}
void enqueue(){
	Node *iter = rear;
	Node *elements = malloc(sizeof(Node));
	printf("Please information of the person\n(Name, Surname, Jobs)\n");
	gets(elements -> name);
	gets(elements -> surName);
	gets(elements -> jobs);
	elements -> next = NULL;
	if(rear == NULL){
		front = elements;
		rear = elements;
		front -> prev = NULL;
		rear -> prev = NULL;
	}
	else{
		while(iter -> next != NULL){
			iter = iter -> next;
		}
		elements -> prev = iter;
		elements -> next = NULL;
		iter -> next = elements;
		front = elements;
	}
}
void peek(){
	Node *iter = rear;
	while(iter != NULL){
		puts(iter -> name);
		puts(iter -> surName);
		puts(iter -> jobs);
		iter = iter -> next;
	}
}
int main(){
	enqueue();
	enqueue();
	peek();
	dequeue();
	peek();
	return 0;
}
