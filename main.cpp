#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define R 256

typedef struct Node
{
	int value;
	Node* next[R];
} Node;

//Birinci dereceden pointer icin node kadar yer ayriliyor.
Node* getNode()
{
	Node * pNode = NULL;
	pNode = (Node *)malloc(sizeof(Node));
	if (pNode)
	{
		for (int i = 0; i < R; i++)
		pNode->next[i] = NULL;
	}
	return pNode;
}

//kelimeye deger atama
void put(Node** x, char *key, int val, int d)
{         
	if (*x == NULL) 
		*x = getNode(); //Birinci dereceden pointer için yer ayiriyoruz.
		
	//Her bir karakter için asagida Recursive fonksiyon oldugundan 
	//karakterin uzunlugu esit oluncaya kadar devam eder. 
	if (d == strlen(key)) 
	{
		(*x)->value = val; //En son olusturulan pointer icine value degeri ataniyor.
		return;
	}
	char c = key[d];
	
	//karakterin degeri recursive fonksiyon ile yeniden pointer olusturuyor.
	put(&((*x)->next[c]), key, val, d+1);
}

//kelimenin degerini ogrenme
int get(Node* x, char * key, int d)
{
	if (x == NULL) 
		return -1; //-1 refers no match
	if (d == strlen(key)) 
		return x->value;
	
	char c = key[d];
	
	return get(x->next[c], key, d+1);
}


int main(int argc, char** argv) {
	int value;
	Node* root;
	
	put(&root, "the", 5, 0);
	put(&root, "shore", 7, 0);
	value = get(root, "the", 0);
	printf("%d\n", value);
	value = get(root, "shore", 0);
	printf("%d\n", value);
	
	return 0;
}
