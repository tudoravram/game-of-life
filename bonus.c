#include "bonus.h"
#include "libraries.h"

void citire_stiva(Stiva **top, int K, FILE *fileIn)
{
    char s[1024]; // sir in care tin minte fiecare linie pe care o citesc (stivele cu pozitii)

    for (int ind1 = 0; ind1 < K; ind1++)
    {
        if (!fgets(s, sizeof(s), fileIn))
        {
            printf("Eroare la alocarea memoriei\n");
            exit(1);
        }

        Stiva *newNode = malloc(sizeof(Stiva));

        newNode->lista = NULL;
        newNode->next = *top;
        *top = newNode;

        int len = strlen(s);
        for (int ind = 0; ind < len; ind += 4)
        {
            int i = s[ind] - '0';
            int j = s[ind + 2] - '0';

            Lista *newList = malloc(sizeof(Lista));

            if (!newList)
            {
                printf("Eroare la alocarea memoriei\n");
                exit(1);
            }

            newList->i = i;
            newList->j = j;
            
            newList->next = newNode->lista;
            newNode->lista = newList;

            if (s[i + 3] == '\n' || s[i + 3] == '\0')
            {
                break;
            }

        }
    }
}


void schimba(char **a, int i, int j)
{
    if (a[i][j] == 'X')
    {
        a[i][j] = '+';
    }
    else if (a[i][j] == '+')
    {
        a[i][j] = 'X';
    }
}

Lista *popList(Stiva **top)
{
    Stiva *temp = *top;
    *top = (*top)->next;

    Lista *lista = temp->lista;
    free(temp);

    return lista;
}

void task_bonus(char **a, int N, int M, int K, Stiva **top, FILE *fileOut)
{
    for (int ind = 0; ind < K; ind++)
    {
        Lista *lista = popList(top);

        while (lista != NULL)
        {
            schimba(a, lista->i, lista->j);
            lista = lista->next;
        }
    }

    for (int i = 0; i < N; i++)
    {    
        for (int j = 0; j < M; j++)
        {
            fprintf(fileOut, "%c ", a[i][j]);
        }
        fprintf(fileOut, "\n");
    }
}
