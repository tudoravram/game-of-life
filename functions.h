void citire_variabile(int *T, int *N, int *M, int *K, FILE *fileIn);

void afisare(char **a, int N, int M, FILE *fileOut);

void free_a(char **a, int N);

void free_b(short **b, int N);

int numar_vecini(char **a, int N, int M, int i, int j);

void generatie_matrice(char **a, short **b, int N, int M);

void aplicare_reguli(char **a, short **b, int N, int M);
void aplicare_reguli_2(char **a, short **b, int N, int M, char **copie);

void task_1(char **a, int N, int M, int K, FILE *fileOut);

void task_2(char **a, int N, int M, int K, FILE *fileOut);
