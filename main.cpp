#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Node {
	int data;
	struct Node* next;
};

struct Node* head;

void Insert(int data);
void Print();
void Delete(int n);

//Basa ekleme
void Insert(int x)
{
	Node* temp = (Node*)malloc(sizeof(struct Node));
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

void Delete(int n)
{
	struct Node* temp1 = head;
	if(n == 1) {
		head = temp1->next; //head now poitns to second node
		free(temp1);
	}
	else if(n >= 2) {
		int i;
		for(i = 0; i < n - 2; i++)
			temp1 = temp1->next; //temp1 points to (n-1)th Node
		struct Node* temp2 = temp1->next; //nth Node
		temp1->next = temp2->next; // (n+1)th Node
		free(temp2);
	}	
}

int main(int argc, char *argv[]) {
	int n;
	head = NULL;
	
	Insert(2);
	Insert(4);
	Insert(6);
	Insert(5);
	
	//Ekrana yazma
	Print();
	
	printf("Enter a position\n");
	scanf("%d",&n);
	
	//N'inci elemani silme
	Delete(n);
	
	//Ekrana yazma
	Print();
}
