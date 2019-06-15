#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Node {
	int data;
	struct Node* next;
};

struct Node* Reverse(struct Node* head) {
	struct Node *current, *prev, *next;
	current = head;
	prev = NULL;
	while(current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	return head;
}

//Insert a Node at the beginning
struct Node* Insert(Node* head, int x)
{
	Node* temp = (Node*)malloc(sizeof(struct Node));
	temp->data = x;
	temp->next = NULL;
	if(head != NULL)
		temp->next = head;
	head = temp;
	return head;
}

void Print(struct Node* head) 
{
	printf("List is: ");
	while(head != NULL)
	{
		printf(" %d", head->data);
		head = head->next;
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	struct Node* head = NULL;
	head = Insert(head, 2);
	head = Insert(head, 4);
	head = Insert(head, 6);
	head = Insert(head, 8);
	head = Insert(head, 10);
	Print(head);
	head = Reverse(head);
	Print(head);
}
