#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct Node {
	int key_value;
	struct Node* left;
	struct Node* right;
};

struct Node* root = 0;
struct Node* zero;
struct Node* one;
struct Node* two;
struct Node* three;
struct Node* four;
struct Node* five;
struct Node* six;
struct Node* nodeValue;
struct Node* deletedNode;

//left, root, right
void inorder(Node* p)
{
	if(p != NULL)
	{
		inorder(p->left);
		printf("%d ", p->key_value);
		inorder(p->right);
	}
}

//root, left, right
void preorder(Node* p)
{
	if(p != NULL)
	{
		printf("%d ", p->key_value);
		preorder(p->left);
		preorder(p->right);
	}
}

//left, right, root
void postorder(Node* p)
{
	if(p != NULL)
	{
		postorder(p->left);
		postorder(p->right);
		printf("%d ", p->key_value);
	}
}

//delete tree
Node* destroy_tree(Node* leaf)
{
	if(leaf != 0)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);				
		free(leaf);
		leaf = 0;
		return leaf;
	}
}

//search into tree
struct Node* binarySearch(int key, Node* leaf)
{
	if(leaf != 0)
	{
		if(key == leaf->key_value)
			return leaf;
		else if(key < leaf->key_value)
		{		
			if(deletedNode == leaf->left)
			{
				leaf->left = 0;
				return 0;
			}				
			else
				return binarySearch(key, leaf->left);
		}
		else if(key > leaf->key_value)
		{
			if(deletedNode == leaf->right)
			{
				leaf->right = 0;
				return 0;
			}				
			else
				return binarySearch(key, leaf->right);
		}			
		else
			return 0;
	}	
	else
		return 0;	
}

struct Node* binaryInsert(int key, Node** leaf)
{
	if(*leaf == 0) //birinci pointer degeri
	{
		*leaf = (Node*)malloc(sizeof(Node));
		(*leaf)->key_value = key;
		/* initialize the children to null */
		(*leaf)->left = 0;
		(*leaf)->right = 0;	
		return *leaf;
	}
	else if(key < (*leaf)->key_value)
		binaryInsert(key, &(*leaf)->left);
	else if(key > (*leaf)->key_value)
		binaryInsert(key, &(*leaf)->right);
}

int main(int argc, char *argv[]) {
	int value1;
	int value2;
	zero = binaryInsert(50, &(root)); //pointerin adresi ikinci pointera esittir.
	one = binaryInsert(25, &(root));
	two = binaryInsert(75, &(root));
	three = binaryInsert(10, &(one));
	four = binaryInsert(30, &(one));
	five = binaryInsert(60, &(two));
	six = binaryInsert(80, &(two));
	
	preorder(root);
	
	printf("\n");
	
	inorder(root);
	
	printf("\n");
	
	postorder(root);
	
	printf("\n");	
	
	printf("Aradiginiz degeri yaziniz: ");
	scanf("%d",&value1);
	value2 = binarySearch(value1, root)->key_value;
	if(value1 == value2)
		printf("Aranan deger bulundu. Aradiginiz deger: %d\n", value2);
	
	printf("Silmek istediginiz degeri yazin: ");
	scanf("%d",&value1);
	
	//Node pointeri buluyorum.
	nodeValue = binarySearch(value1, root);
	//Node pointeri baska bir yerde saklayip siliyorum.
	//Silmek demek baskalarinin kullanimina acmak anlamina geliyor.
	//Agac uzerinde silmek icin o pointerin kendisini bulmam gerekiyor.
	//Bir sonraki kodda ise aratma islemi yapiyorum zaten.
	deletedNode = nodeValue;
	nodeValue = destroy_tree(nodeValue);
	//two->right = destroy_tree(two->right);	
	
	//Sakladigim Node pointeri aratiyorum ve oraya bakan pointer'a 0 degeri atiyorum.
	//destroy_tree yapildiktan sonra bir kere binarySearch yapilmasi gerekmektedir.
	Node* deleted = binarySearch(value1, root);
	if(deleted == 0)
		printf("Girdiginiz deger silinmistir.");
	else
		printf("Deger silinememistir.");
}
