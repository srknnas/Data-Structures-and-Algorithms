#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Node {
	int data;
	struct Node* next;
};

//inserts a node at the end of the list.
struct Node* Insert(Node* head, int data)
{
	Node* temp = (Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = NULL;
	if(head == NULL)
		head = temp;
	else {
		Node* temp1 = head;
		while(temp1->next != NULL)
			temp1 = temp1->next;
		temp1->next = temp;
	}
	return head;
}

//Ekrana yazma
void Print(struct Node* head) 
{	
	if(head == NULL)
	{
		printf("\n");
		return;		
	}
	printf(" %d", head->data);
	Print(head->next);	
}

//Ekrana ters yazma
void ReversePrint(struct Node* head)
{
	if(head == NULL)
		return;
	ReversePrint(head->next);
	printf(" %d", head->data);
}

int main(int argc, char *argv[]) {
	struct Node* head = NULL;
	head = Insert(head, 2);
	head = Insert(head, 4);
	head = Insert(head, 6);
	head = Insert(head, 8);
	head = Insert(head, 10);
	Print(head);
	ReversePrint(head);
}
