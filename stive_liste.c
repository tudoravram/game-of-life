#include "stive_liste.h"

//functii stive

void push(Stack **top, int v)
{
    Stack *newStack = (Stack *) malloc(sizeof(Stack));
    
    newStack->val = v;
    newStack->next = *top;
    *top = newStack;
}

void printStack(Stack *top, FILE *fileOut)
{
    while (top->next != NULL)
    {
        fprintf(fileOut, "%d ", top->val);
        top = top->next; 
    }

    fprintf(fileOut, "%d", top->val);

    fprintf(fileOut, "\n");
}

//functii noi

void createStack(Node **head)
{
    Node *newNode = (Node *) malloc(sizeof(Node));
    
    if (newNode == NULL)
    {
        printf("Eroare la alocarea memoriei");
        exit(1);
    }

    newNode->stack = NULL;
    newNode->next = NULL;

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *temp = *head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void add(Node *head, int i, int j)
{
    if (head == NULL)
    {
        return;
    }

    while (head->next != NULL)
    {
        head = head->next;
    }

    push(&head->stack, j);
    push(&head->stack, i);
}

void printNode(Node *head, FILE *fileOut)
{   
    int i = 1;
    while (head != NULL)
    {
        fprintf(fileOut, "%d ", i++);
        printStack(head->stack, fileOut);
        head = head->next;
    }
}

void free_node(Node *head)
{
    Node* newNode = NULL;

    while (head != NULL)
    {
        newNode = head;
        
        Stack* stiva = head->stack;
        while (stiva != NULL)
        {
            Stack* temp = stiva;
            stiva = stiva->next;
            free(temp);
        }
        
        free(newNode);

        head = head->next;
       
    }
}