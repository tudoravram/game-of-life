#include "libraries.h"
#include "arbori.h"
#include "functions.h"

Tree* preinitializare(int K)
{
    if (K <= 0) {
        return NULL; 
    }

    Tree* newNode = (Tree*)malloc(sizeof(Tree));
    if (newNode == NULL) {
        printf("Eroare la alocarea memoriei pentru arbore.\n");
        exit(1);
    }

    newNode->lista = NULL;
    newNode->left = preinitializare(K - 1); 
    newNode->right = preinitializare(K - 1); 

    return newNode;
}

void parcurgere(Tree* root, int regula, char **a, int N, int M, int K, FILE *fileOut)
{
    if (root == NULL)
        return;

    if (regula == 1)
    {
        if (root->lista == NULL)
        {
            short **b = (short **) malloc(N * sizeof(short *));
            if (b == NULL)
            {
                printf("Eroare la alocarea memoriei (b)\n");
                exit(1);
            }

            for (int i = 0; i < N; i++)
            {
                b[i] = (short *) malloc(M * sizeof(short));
                if (b[i] == NULL)
                {
                    free_b(b, N);
                    exit(1);
                }
            }

            char **copie = (char **) malloc(N * sizeof(char *));
            if (copie == NULL)
            {
                printf("Eroare la alocarea memoriei (copie)\n");
                free_b(b, N);
                exit(1);
            }

            for (int i = 0; i < N; i++)
            {
                copie[i] = (char *) malloc(M * sizeof(char));
                if (copie[i] == NULL)
                {
                    free_a(copie, N);
                    free_b(b, N);
                    exit(1);
                }
            }

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    copie[i][j] = a[i][j];
                }
            }
            generatie_matrice(a, b, N, M);
            aplicare_reguli(a, b, N, M);

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    if (copie[i][j] != a[i][j])
                    {
                        List* newNode = (List*)malloc(sizeof(List));
                        if (newNode == NULL)
                        {
                            printf("Eroare la alocarea memoriei (List)\n");
                            free_a(copie, N);
                            free_b(b, N);
                            exit(1);
                        }
                        newNode->i = i;
                        newNode->j = j;
                        newNode->next = root->lista;
                        root->lista = newNode;
                    }
                }
            }

            free_a(copie, N);
            free_b(b, N);
        }
    }
    else
    {
        if (root->lista == NULL)
        {
            short **b = (short **) malloc(N * sizeof(short *));
            if (b == NULL)
            {
                printf("Eroare la alocarea memoriei (b)\n");
                exit(1);
            }

            for (int i = 0; i < N; i++)
            {
                b[i] = (short *) malloc(M * sizeof(short));
                if (b[i] == NULL)
                {
                    free_b(b, N);
                    exit(1);
                }
            }

            char **copie = (char **) malloc(N * sizeof(char *));
            if (copie == NULL)
            {
                printf("Eroare la alocarea memoriei (copie)\n");
                free_b(b, N);
                exit(1);
            }

            for (int i = 0; i < N; i++)
            {
                copie[i] = (char *) malloc(M * sizeof(char));
                if (copie[i] == NULL)
                {
                    free_a(copie, N);
                    free_b(b, N);
                    exit(1);
                }
            }

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    copie[i][j] = a[i][j];
                }
            }

            generatie_matrice(a, b, N, M);
            aplicare_reguli_2(a, b, N, M);
            
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    if (copie[i][j] != a[i][j])
                    {
                        List* newNode = (List*)malloc(sizeof(List));
                        if (newNode == NULL)
                        {
                            printf("Eroare la alocarea memoriei (List)\n");
                            free_a(copie, N);
                            free_b(b, N);
                            exit(1);
                        }
                        newNode->i = i;
                        newNode->j = j;
                        newNode->next = root->lista;
                        root->lista = newNode;
                    }
                }
            }

            free_a(copie, N);
            free_b(b, N);
        }
    }

    if (root->right != NULL)
    {
        parcurgere(root->right, 1, a, N, M, K, fileOut);
    }
    if (root->left != NULL)
    {
        parcurgere(root->left, 2, a, N, M, K, fileOut);
    }
}


void afisare_task3(Tree* root, int N, int M, FILE *fileOut)
{
    if (root == NULL)
        return;

    char **mat = (char **) malloc(N * sizeof(char *));
    if (mat == NULL)
    {
        printf("Eroare la alocarea memoriei (mat)\n");
        exit(1);
    }

    for (int i = 0; i < N; i++)
    {
        mat[i] = (char *) malloc(M * sizeof(char));
        if (mat[i] == NULL)
        {
            for (int k = 0; k < i; k++) 
            {
                free(mat[k]);
            }
            free(mat);
            exit(1);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            mat[i][j] = '+';
        }
    }
    List* list = root->lista;
    while (list != NULL)
    {
        mat[list->i][list->j] = 'X'; 
        list = list->next;
    }


    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            fprintf(fileOut, "%c", mat[i][j]);
        fprintf(fileOut, "\n");
    }
    fprintf(fileOut, "\n");

    for (int i = 0; i < N; i++)
    {
        free(mat[i]);
    }
    free(mat);

    afisare_task3(root->left, N, M, fileOut);
    afisare_task3(root->right, N, M, fileOut);
}


void free_tree(Tree* root)
{
    free_tree(root->left);
    free_tree(root->right);
    List* current = root->lista;
    while (current != NULL) {
        List* temp = current;
        current = current->next;
        free(temp); 
    }

    free(root);
}