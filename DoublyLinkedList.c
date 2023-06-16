/*
    Jay-Ar Portagana
    Data Structure: Doubly linked list 
    Doubly linked list using c++ programming language

    Terminal: 
    [Compile]   gcc -o DoublyLinkedList DoublyLinkedList.c
    [Run]       .\DoublyLinkedList          
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};
struct Node* head;

struct Node* NewNode(int data)
{

    //calculate the required space for newNode
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

//insert node at start
void insertAtHead(int data)
{
    struct Node* newNode = NewNode(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    //swap head and newNode
    head->prev = newNode;
    newNode->next = head;
    head = newNode;

}


//display output
void print() 
{
    struct Node* tempo = head;
    if(tempo == NULL) 
    {
        return;
    }
    else
    {
    printf("Forward: ");
    while(tempo->next != NULL)
    {
        printf("%i ", tempo->data);
        tempo = tempo->next;
    }
    printf("%i \n", tempo->data);

    printf("Backward: ");
    while(tempo->prev != NULL)
    {
        printf("%i ", tempo->data);
        tempo = tempo->prev;
    }
    printf("%i \n", tempo->data);
    }

}


//return allocated memory to operating system
void freeSpace()
{
    struct Node* tempo = head;
        while(head->next != NULL)
        {
            tempo = head->next;
            free(head); 
            head = tempo;
        }
}

int main(void)
{
    head = NULL; 
    insertAtHead(10); print();
    insertAtHead(20); print();
    insertAtHead(30); print();
    print();
    freeSpace();
    return 0;
}