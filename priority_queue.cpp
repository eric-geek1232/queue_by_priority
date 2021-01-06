/* by eric 06/01/2021*/

#include <stdlib.h>
#include <iostream>
#include <conio.h>

using namespace std;

/* node structure
------------------------------------------------------------------------*/
struct Node
{
	string data;
	int priority;
	Node *next;
};

/* Queue structure
------------------------------------------------------------------------*/
struct Queue
{
	Node *front;
	Node *rear ;
};

/* function prototypes
------------------------------------------------------------------------*/
Node *createNode(string name, int priority);
void insertElement(Queue *&queue, string name, int priority);
void addElement(Queue *&queue, string name, int priority);
void sortByPriority(Queue *&queue);
void showQueue(Queue *queue);
void dequeue(Queue *&queue);
bool isEmpty(Queue *queue);
void menu();

/* Main function
------------------------------------------------------------------------*/

int main()
{
	Queue *mainQueue = new Queue();
	mainQueue->front = NULL;
	mainQueue->rear = NULL;
	
	string name ;
	int priority;
	int option;
	
	do {
		menu(); 
		cin>> option;
		
		switch(option) {
			case 1:
				cout<< "\n Type one name: ";
				cin>> name;
				cout<< "\n Now Type its priority: ";
				cin>> priority;
				
				insertElement(mainQueue, name, priority);
				
				break;
			case 2:
				cout << "\n\n Showing by priority...\n"<< endl;
				
				if (mainQueue->front != NULL) {
					showQueue(mainQueue);	
				} else {
					cout<< "\n\tEmpty Queue...!"<< endl;	
				}
				
				break;
			
			case 3:
				cout<< "\n\n attending...\n\n"<< endl;
				dequeue(mainQueue);
				break;
			
			case 4:
				system("cls");
				cout<< "\tBig thanks for using this program!"<< endl;
				
				break;
			
			default:
				system("cls");
				cout<< "\n\tWrong option, \"Try Again\"...!"<< endl;
				
		}
		
		cout<< "\n"<< endl;
		system("pause"); 
		system("cls");
	} while (option != 4);
	
	return 0;
}

/* functions
------------------------------------------------------------------------*/ 

Node *createNode(string name, int priority)
{
	Node *newNode = new Node();
	
	newNode->data = name;
	newNode->priority = priority;
	newNode->next = NULL;
	
	return newNode;
};

void insertElement(Queue *&queue, string name, int priority)
{
	addElement(queue, name, priority);
	
	sortByPriority(queue);
	
	cout<< "\n\n\t"<< name<< " has been added...\n"<< endl;
}

void addElement(Queue *&queue, string name, int priority)
{
	Node *newNode = createNode(name, priority);
	
	if (isEmpty(queue)) {
		queue->front = newNode;			// add first element
	} else {
		queue->rear->next = newNode;	// add on rear
	}
	
	queue->rear = newNode;				// always point to the last node
}

void sortByPriority(Queue *&queue)
{
	Node *node_aux1, *node_aux2;
	int priority_aux;
	string data_aux;
	node_aux1 = queue->front;			// get the whole queue from the front
	
	// blubble sort
	while (node_aux1->next != NULL) {
		node_aux2 = node_aux1->next;
		while (node_aux2 != NULL) {
			if (node_aux1->priority > node_aux2->priority ) {
				priority_aux = node_aux1->priority;
				data_aux = node_aux1->data;
				node_aux1->priority = node_aux2->priority;
				node_aux1->data = node_aux2->data;
				node_aux2->priority = priority_aux;
				node_aux2->data = data_aux;
			}
			node_aux2 = node_aux2->next;
		}
		node_aux1 = node_aux1->next;
	}
}

void showQueue(Queue *queue)
{
	Node *node_aux;
	node_aux = queue->front;				// get the whole queue from the front
	
	cout<< " Data	 | Prioridad "<< endl;
	cout<< " ------------------- "<< endl;
	
	while (node_aux != NULL ) {
		cout<< " "<< node_aux->data<< "\t | "<< node_aux->priority<< endl;
		node_aux = node_aux->next;
 	}
}

bool isEmpty(Queue *queue){
	if(queue->front == NULL){
		return true;
	} else {
		return false;
	}
}

void dequeue(Queue *&queue){
	if(isEmpty(queue)){
		cout<< "\n\tEmpty queue...!\n"<< endl;
	} else{
		string data_aux;
		Node *queue_aux;
		
		data_aux = queue->front->data;			// get current data;
		queue_aux = queue->front;				// get the whole queue from the front
	
		if(queue->front == queue->rear){		// if one element remains
			queue->front = NULL;				// clear queue
			queue->rear = NULL;
		}
		else {
			queue->front = queue->front->next;	// overwrite main queue with next node
		}
	
		delete queue_aux;						// delete old queue
		
		if(!isEmpty(queue)){					// if it's not empty
			cout<< " [ "<< data_aux<< " ],\t";
			
			dequeue(queue);						// keep iterating recursive
		}
		else {
			cout<<" [ "<< data_aux<< " ]."<< endl;	
		}
	}
}

void menu()
{
	cout<< "\n\tQueue by priority \n\n"<< endl;
	
	cout<< "\t..::Menu::..\n"<< endl;
	cout<< " [1] Add new element "<< endl;
	cout<< " [2] Show queue "<< endl;
	cout<< " [3] Attend "<< endl;
	cout<< " [4] Exit "<< endl;
	cout<< "\n Choose: ";
}
