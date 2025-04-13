#include "libraries.h"

struct Element
{
    int val;
    struct Element *next;
};

typedef struct Element Stack;

struct Element2
{
    Stack *stack;
    struct Element2 *next;
};

typedef struct Element2 Node;

void push(Stack** top, int v);
int pop(Stack** top);
int top(const Stack *top);
int isEmpty(const Stack* top);
void deleteStack(Stack** top);
void printStack(Stack* top, FILE *fileOut);
void createStack(Node **head);
void add(Node *head, int i, int j);
void printNode(Node *head, FILE *fileOut);
void free_node(Node *head);
