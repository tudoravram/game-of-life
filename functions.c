#include "libraries.h"
#include "functions.h"

void citire_variabile(int *T, int *N, int *M, int *K, FILE *fileIn)
{
    fscanf(fileIn, "%d", T); //numarul testului  
 
    fscanf(fileIn, "%d%d", N, M); //dimensiunea grilei

    fscanf(fileIn, "%d", K); //numarul generatiilor de calculat
}

void afisare(char **a, int N, int M, FILE *fileOut)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            fprintf(fileOut, "%c", a[i][j]);
        }
        fprintf(fileOut, "\n");
    }
    fprintf(fileOut, "\n");
}

void free_a(char **a, int N)
{
    for (int i = 0; i < N; i++)
    {
        free(a[i]);
    }
    free(a);
}

void free_b(short **b, int N)
{
    for (int i = 0; i < N; i++)
    {
        free(b[i]);
    }
    free(b);
}

int numar_vecini(char **a, int N, int M, int i, int j)
{
    //vectori ai pozitiilor vecinilor in matrice
    const int dx[] = {-1, -1, -1, 1, 1, 1, 0, 0};
    const int dy[] = {-1, 0, 1, -1, 0, 1, -1, 1}; 

    int nr = 0; 

    for (int d = 0; d < 8; d++) //directiile in care cautam 
    {
        int di = i + dx[d];
        int dj = j + dy[d];

        if (di >= 0 && di < N && dj >= 0 && dj < M)
        {
            if (a[di][dj] == 'X') nr++;
        }
    }
    return nr; //numarul de vecini ai celulei 
}

void generatie_matrice(char **a, short **b, int N, int M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            b[i][j] = numar_vecini(a, N, M, i, j); //numararea vecinilor fiecarei celule
        }
    }
}

void aplicare_reguli(char **a, short **b, int N, int M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (b[i][j] == 3 && a[i][j] == '+') //reproducere
            {
                a[i][j] = 'X';
            }
            else if (b[i][j] < 2 && a[i][j] == 'X') //subpopulare
            {
                a[i][j] = '+';
            }
            else if (b[i][j] == 2 || b[i][j] == 3) //supravietuire
            {
                continue;
            }
            else if (b[i][j] > 3 && a[i][j] == 'X') //suprapopulare
            {
                a[i][j] = '+';
            }
            
        }
    }
}

void task_1(char **a, int N, int M, int K, FILE *fileOut)
{    
    short **b = (short **) malloc(N * sizeof(short *)); //matrice in care tin minte numarul vecinilor fiecarui element

    if (b == NULL)
    {
        printf("Eroare la alocarea memoriei");

        free_b(b, N);
        exit(1);
    } 

    for (int i = 0; i < N; i++)
    {
        b[i] = (short *) malloc(M * sizeof (short));

        if (b[i] == NULL)
        {
            free_b(b, N);
            exit(1);
        }
    }

    afisare(a, N, M, fileOut); //afisarea generatiei 0

    for (int i = 0; i < K; i++) //calcularea generatiilor de K ori
    {
        generatie_matrice(a, b, N, M);

        aplicare_reguli(a, b, N, M);        
        
        afisare(a, N, M, fileOut);
    }
    
    free_a(a, N);
    free_b(b, M);
}
