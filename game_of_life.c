#include <stdio.h>
#include <stdlib.h>

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

void task_1(char **a, int N, int M, int K, FILE *fileOut)
{
    short **b = (short **) malloc(N * sizeof(short *)); //matrice in care tin minte numarul vecinilor fiecarui element

    if (b == NULL)
    {
        printf("Eroare la alocarea memoriei");

        free(b);

        exit(1);
    } 

    for (int i = 0; i < N; i++)
    {
        b[i] = (short *) malloc(M * sizeof (short));
        if (b[i] == NULL)
        {
            printf("Eroare la alocarea memoriei");

            for (int j = 0; j < i; j++)
            {
                free(b[i]);
            }
            free(b);

            exit(1);
        }
    }

    for (int ind = 0; ind < K; ind++) //calcularea generatiilor de K ori
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                b[i][j] = numar_vecini(a, N, M, i, j); //numararea vecinilor fiecarei celule
            }
        }

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
        
        afisare(a, N, M, fileOut);
        fprintf(fileOut, "\n");
    }
    
    for (int i = 0; i < N; i++)
    {
        free(a[i]);
    }
    free(a);

    for (int i = 0; i < N; i++)
    {
        free(b[i]);
    }
    free(b);
}

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

    fscanf(fileIn, "%d", &T); //numarul testului

    fscanf(fileIn, "%d%d", &N, &M); //dimensiunea grilei

    fscanf(fileIn, "%d", &K); //numarul generatiilor de calculat

    a = (char **) malloc(N * sizeof(char *));

    if (a == NULL)
    {
        printf("Eroare la alocarea memoriei");

        free(a);
        exit(1);
    }

    for (int i = 0; i < N; i++)
    {
        a[i] = (char *) malloc(M * sizeof(char));
        if (a[i] == NULL)
        {
            printf("Eroare la alocarea matricei");
            
            for (int j = 0; j < i; j++)
            {
                free(a[j]);
            }

            free(a);
            

            exit(1);
        }
    }

    fgetc(fileIn);


    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            fscanf(fileIn, "%c", &a[i][j]); //citirea matricei
        }

        fgetc(fileIn);

    }

    fclose(fileIn);
    


    if (T == 1)
    {
        afisare(a, N, M, fileOut);

        fprintf(fileOut, "\n");

        task_1(a, N, M, K, fileOut);
    }

    for (int i = 0; i < N; i++)
    {
        free(a[i]);
    }
    free(a);

    fclose(fileOut);
    return 0;
}