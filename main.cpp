#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Node {
	int data;
	struct Node* next;
};
struct Node* head;

void Insert(int x);
void Print();

//Basa ekleme
void Insert(int x)
{
	Node* temp = (Node*)malloc(sizeof(struct Node)); //pointerin gosterdigi yere alan aciyorum.
	temp->data = x;
	temp->next = NULL;
	if(head != NULL)
		temp->next = head;
	head = temp;
}

void Print() 
{
	struct Node* temp = head;
	printf("List is: ");
	while(temp != NULL)
	{
		printf(" %d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	int n, i, x;
	head = NULL;
	
	//Kac tane eleman eklenecek onun verisini aliyoruz.
	printf("How many numbers?\n");
	scanf("%d", &n);
	
	for(i = 0; i < n; i++){
		printf("Enter the Number \n");
		scanf("%d",&x);
		//Basa ekleme fonksiyonu
		Insert(x);
		//Ekrana yazma fonksiyonu
		Print();
	}
}
