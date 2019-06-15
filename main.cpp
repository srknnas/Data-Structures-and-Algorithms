#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Node {
	int data;
	struct Node* next;
};
struct Node* head;

void Insert(int data, int n);
void Print();

//N'inci kisma veri ekleme
void Insert(int data, int n)
{
	Node* temp1 = new Node(); //without using malloc
	temp1->data = data;
	temp1->next = NULL;
	//Basa ekleme
	if(n == 1) {
		temp1->next = head;
		head = temp1;
		return;
	}
	else if(n >= 2)
	{	
		Node* temp2 = head;
		for(int i = 0; i < n - 2; i++) {
			temp2 = temp2->next; //eklenecek Node'dan bir onceki Node'a geldik 
		}
		//Temp2'den sonra gelen verinin 
		//temp1'den sonra gelmesi saglandi
		temp1->next = temp2->next;
		//Temp2'den sonra temp1 gelmesi saglandi.
		temp2->next = temp1; //
	}
}

//Ekrana yazdirma
void Print() 
{
	//Bas Node kismi ayri bir degiskene atiyoruz.
	struct Node* temp = head;
	
	printf("List is: ");
	
	while(temp != NULL)
	{
		printf(" %d", temp->data); //Veriyi yazdir
		temp = temp->next; //Bir sonraki Node'a gec
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	head = NULL;
	
	//n inci kisma node ekleme
	Insert(2, 1);
	Insert(3, 2);
	Insert(4, 1);
	Insert(5, 2);
	Insert(6, 3);
	
	//Ekrana yazma fonksiyonu
	Print();
}
