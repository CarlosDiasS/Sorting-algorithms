#include <stdio.h>
#include <stdlib.h>

void troca(int *vet, int i, int j)
{
    int aux = vet[i];
    vet[i] = vet[j];
    vet[j] = aux;
}

void selectionSort(int *vet, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int menor = i;
        for (int j = i + 1; j < n; j++)
        {
            if (vet[j] < vet[menor]) // compara cada elemento com o atual menor, percorre todo o array
                menor = j;
        }
        troca(vet, i, menor);
    }
}

void PrintVet(int n, int vet[])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }
}

int main()
{
    int vetor[] = {5, 6, 78, 45, 3, 6, 8, 2};
    int n = sizeof(vetor) / 4; //inteiros

    selectionSort(vetor, n);
    PrintVet(n, vetor);
    return 0;
}
