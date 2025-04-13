#include "libraries.h"
#include "functions.h"
#include "stive.h"

int main(int argc, const char *argv[])
{

    FILE *fileIn = fopen(argv[1], "rt");
    FILE *fileOut = fopen(argv[2], "wt");

    if (fileIn == NULL) {
        printf("Nu s-a putut deschide fișierul.\n");
        exit(1);
    }
    
    char **a = NULL;
    int N, M, K, T;

    citire_variabile(&T, &N, &M, &K, fileIn);

    a = (char **) malloc(N * sizeof(char *));

    if (a == NULL)
    {
        printf("Eroare la alocarea memoriei");

        free_a(a, N);
        exit(1);
    }

    for (int i = 0; i < N; i++)
    {
        a[i] = (char *) malloc(M * sizeof(char));
        if (a[i] == NULL)
        {
            printf("Eroare la alocarea matricei");
            
            free_a(a, N);
            
            exit(1);
        }
    }
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            fscanf(fileIn, " %c", &a[i][j]); //citirea matricei
        }
    
        fgetc(fileIn);
    }
    
    if (T == 1)
    {
        task_1(a, N, M, K, fileOut);
    }
    
    free_a(a, N);
    
    fclose(fileIn);
    fclose(fileOut);
    return 0;
}