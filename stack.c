#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	char* name[20];
	char* surName[20];
	char* jobs[20];
	struct Node *next;
}Node;
	Node *top;
void push(){
	Node *elements = malloc(sizeof(Node));
	printf("Please information of the person\n(Name, Surname, Jobs)\n");
	gets(elements -> name);
	gets(elements -> surName);
	gets(elements -> jobs);
	elements -> next = NULL;
	if(top == NULL){
		top = elements;
	}
	else{
		elements -> next = top;
		top = elements;
	}
}
void pop(){
	Node *iter = top;
	top = top -> next;
	free(iter);
}
void print(){
	Node *iter = top;
	while(iter != NULL){
		puts(iter -> name);
		puts(iter -> surName);
		puts(iter -> jobs);
		iter = iter -> next;
	}
}
int main(){
	push();
	push();
	print();
	pop();
	print();
	return 0;
}
