#include "libraries.h"

struct Element
{
    int val;
    struct Element *next;
};

typedef struct Element Node;

void push(Node** top, int v);
int pop(Node** top);
int top(Node *top);
int isEmpty(Node* top);
void deleteStack(Node** top);
void printStack(Node* top);