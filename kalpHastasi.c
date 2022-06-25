#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<locale.h>
typedef struct Cycle{
	int orgName;
	char name[20];
	struct Cycle *next;
}Cycle;
int main(){
	srand(time(0));
	Cycle *head = malloc(sizeof(struct Cycle));
	Cycle *last = head;
	setlocale(LC_ALL,"Turkish");
	char organs[7][20] = {"Sað Karýncýk","Atardamar","Akciðer","Sol Kulakcýk","Sol Karýncýk","Aort Damarý","Sað Kulakcýk"};
	int var, year = 0, value;
	strcpy(head -> name,organs[0]);
	for(int i = 0; i < 6; i++){
		last -> next = malloc(sizeof(struct Cycle));
		strcpy(last -> next -> name,organs[(i + 1) % 7]);
		last = last -> next;
	}
	last -> next = head;
	last = head;
	do{	
		printf("%d.Yýlda-Yaþamasý için herhangi bir deðere basýn, Ölmesi için 0'a basýn = ",year + 1);
		scanf("%d",&var);
		int i;		
		for(int i = 0; i < 7; i++){
			last -> orgName = 1;
			last = last -> next;
			if(var == 0){
				last -> orgName = var;
			}
		}
		year++;
	}while(var != 0);
	value = rand() % 7;
	printf("\n\nHasta %d yýl yaþadý ve kan %s'de iken öldü\n",year,organs[value - 1]);
	return 0;
}
