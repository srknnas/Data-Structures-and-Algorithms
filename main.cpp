#include <iostream>
#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#define MAX_QUEUE_SIZE  100

typedef struct queueADT {
    int * contents;
    int front;
    int count;
} queueADT;

typedef struct node
{
	struct node *next;
	int vertex;
}node;

node* adj [13];
int visitedDepth[13];
int visitedBreadth[13];

queueADT * QueueCreate(void)
{
    queueADT * queue;
    queue = (queueADT *)malloc(sizeof(queueADT));
    
    int *newContents;
    newContents = (int *)malloc(sizeof(int) * MAX_QUEUE_SIZE);
   
    if (queue == NULL) {
        fprintf(stderr, "Insufficient Memory for new Queue.\n");
    }
    
    queue->front = 0;
    queue->count = 0;
    queue->contents = newContents;

    return queue;
}

void QueueDestroy(queueADT * queue)
{
    free(queue->contents);
    queue->contents = NULL;

    free(queue);
}

void Enqueue(queueADT * queue, int element)
{
    int newElementIndex;
    if (queue->count >= MAX_QUEUE_SIZE) {
        fprintf(stderr, "QueueEnter on Full Queue.\n");
    }
    newElementIndex = (queue->front + queue->count)%MAX_QUEUE_SIZE;
    queue->contents[newElementIndex] = element;
    queue->count++;
}

int Dequeue(queueADT * queue)
{
    int oldElement;
    if (queue->count <= 0) {
        fprintf(stderr, "QueueDelete on Empty Queue.\n");
    }
    /* Save the element so we can return it. */
    oldElement = queue->contents[queue->front];
    queue->front++;
    queue->front %= MAX_QUEUE_SIZE;
    queue->count--;
    return oldElement;
}

int QueueIsEmpty(queueADT * queue)
{
    return queue->count <= 0;
}

int QueueIsFull(queueADT * queue)
{
    return queue->count >= MAX_QUEUE_SIZE;
}

void depthFirstSearch(int i)
{
	//root secildi
	node* p = adj[i];
	visitedDepth[i] = 1;
	printf("Visited %d\n", i);
	
	while(p != NULL)
	{
		i = p->vertex;
		if(!visitedDepth[i])					
			depthFirstSearch(i);					
		p = p->next;
	}
}

void BreadthFirstSearch(int startVertex)
{	
	queueADT*  q1 = QueueCreate();
	visitedBreadth[startVertex] = 1;
	
	//Kuyruga eklendi.
	Enqueue(q1, startVertex);
	printf("Added Queue: %d\n", startVertex);
	
	while(!QueueIsEmpty(q1))
	{
		int currentVertex = Dequeue(q1);		
		printf("Visited %d\n", currentVertex);	
		printf("Deleted Queue: %d\n", currentVertex);	
		
		node* temp = adj[currentVertex];
		
		while(temp != NULL)
		{
			int adjVertex = temp->vertex;
			
			if(!visitedBreadth[adjVertex])
			{
				visitedBreadth[adjVertex] = 1;
				Enqueue(q1, adjVertex);
				printf("Added Queue: %d\n", adjVertex);
			}
				
			temp = temp->next;
		}	
		
		printf("\n");	
	}	
}

void addEdge(int v, int w)
{
	node *q;
	//acquire memory for the new node
	q=(node*)malloc(sizeof(node));
	q->vertex=w;
	q->next=NULL;
	//insert the node to beginning of the linked list
	q->next = adj[v];
	adj[v]= q;
}

int main(int argc, char** argv) {
	
	//Create Graph
	addEdge(0,1);
	addEdge(1,0);
	
	addEdge(0,2);
	addEdge(2,0);
	
	addEdge(0,6);
	addEdge(6,0);
	
	addEdge(0,5);
	addEdge(5,0);
	
	addEdge(6,4);
	addEdge(4,6);
	
	addEdge(4,3);
	addEdge(3,4);
	
	addEdge(3,5);
	addEdge(5,3);
	
	addEdge(5,4);
	addEdge(4,5);
	
	addEdge(7,8);
	addEdge(8,7);
	
	addEdge(9,10);
	addEdge(10,9);
	
	addEdge(9,11);
	addEdge(11,9);
	
	addEdge(9,12);
	addEdge(12,9);
	
	printf("Depth First Search Algorithm\n");
	depthFirstSearch(0);
	printf("\nBreadth First Search Algorithm\n");	
	BreadthFirstSearch(0);
	
	return 0;
}
