#include "libraries.h"

struct list
{
    int i, j;
    struct list *next;
};

typedef struct list List;

struct tree
{
    List *lista;
    struct tree *left, *right;
};

typedef struct tree Tree;

Tree* preinitializare(int K);
void parcurgere(Tree* root, int regula, char **a, int N, int M, int K, FILE *fileOut);
void afisare_task3(Tree* root, int N, int M, FILE *fileOut);
void free_tree(Tree* root);
