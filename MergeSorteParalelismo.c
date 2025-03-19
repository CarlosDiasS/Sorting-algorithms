#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

void PrintVet(int n, int vet[])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }
}

void merge(int *vetor, int inicio, int meio, int fim)
{
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int *L = (int *)malloc(n1 * sizeof(int)); // Criar arrays temporários
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copiar os dados para os arrays temporários
    for (i = 0; i < n1; i++)
    {
        L[i] = vetor[inicio + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = vetor[meio + 1 + j];
    }

    i = 0; j = 0; k = inicio;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            vetor[k] = L[i];
            i++;
        }
        else
        {
            vetor[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        vetor[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        vetor[k] = R[j];
        j++;
        k++;
    }

    free(L); // Liberar memória
    free(R);
}

void mergeSort(int *vet, int inicio, int fim)
{
    if (inicio >= fim)
        return;

    int meio = (inicio + fim) / 2;

    // Usar paralelismo para ordenar as duas partes
    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp task
            mergeSort(vet, inicio, meio);
            #pragma omp task
            mergeSort(vet, meio + 1, fim);
        }
    }

    // Junta partes já ordenadas
    merge(vet, inicio, meio, fim);
}

void randomVet(int n, int *vet)
{
    #pragma omp parallel for
    for (int i = 0; i < n; i++)
    {
        vet[i] = rand() % 500;
    }
}

int main()
{
    omp_set_num_threads(8); // Define o número de threads

    srand(time(NULL));
    clock_t temp;
    int n = 100000;
    int *vet = (int *)malloc(n * sizeof(int));
    if (vet == NULL) return -1;

    randomVet(n, vet);

    temp = clock();
    mergeSort(vet, 0, n - 1); // Passa n - 1
    temp = clock() - temp;

    PrintVet(n, vet);
    printf("\n");
    printf("Tempo: %lf segundos\n", ((double)temp) / CLOCKS_PER_SEC); // Corrigido para segundos
    free(vet);
    return 0;
}
