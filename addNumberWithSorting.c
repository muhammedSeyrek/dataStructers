#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	int data;
	struct node *next;
};
	struct node *start = NULL;
  	struct node *iter = NULL;
void addNumber(int number){
	struct node *added = (struct node*) malloc(sizeof(struct node));
	added -> data = number;
	added -> next = NULL;
	if(start == NULL){
		start = added;
	}else{
		iter = start;
		while(iter -> next != NULL){
			iter = iter -> next;
		}
		iter -> next = added;
	}
}
void print(int i){
	iter = start;
	if(iter -> next != NULL){
		for(int j = 0; j < i; j++){
			printf("%d ",iter -> data);
			iter = iter -> next;
		}
	}
}
void sortPrint(int newSort,int count){
	iter = start;
	for(int i = 1; i < newSort; i++){
		iter = iter -> next;
	}
	struct node *lastNode = malloc(sizeof(struct node));
	lastNode = iter;
	for(int i = 0; i < count; i++){
		printf("%d ",lastNode -> data);
		lastNode = lastNode -> next; 
	}
	lastNode -> next = NULL;
}
void removeNumber(int data){
	iter = start;
	if(iter != NULL){
		if(iter -> data == data){
			iter -> data = iter -> next -> data;
			iter = iter -> next -> next;
		}else{
			iter = iter -> next;
		}
	}
}
int main(){
	struct node *start = malloc(sizeof(struct node));
  	struct node *iter = start;
	int data = 1, i = 0;
	iter = start;
	while(data != 0){
		printf("Enter the number = ");
		scanf("%d",&data);	
		addNumber(data);
		i++;
	}
	iter -> next = NULL;
	iter = start;
	print(i);
	int newSort, removeN;
	int count = i - newSort;
	printf("\nEnter the number = ");
	scanf("%d",&newSort);
	sortPrint(newSort,count);
	printf("Enter the remove number = ");
	scanf("%d",&removeN);
	removeNumber(removeN);
	sortPrint(newSort,count - 1);
	return 0;
}
