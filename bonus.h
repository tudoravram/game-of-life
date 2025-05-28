#include "libraries.h"

struct lista
{
    int i, j;
    struct lista *next;
};

typedef struct lista Lista;

struct stiva
{
    Lista *lista;
    struct stiva *next;
};

typedef struct stiva Stiva;

void citire_stiva(Stiva **top, int k, FILE *fileIn);
void schimba(char **a, int i, int j);
Lista *popList(Stiva **top);
void task_bonus(char **a, int N, int M, int K, Stiva **top, FILE *fileOut);



