#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void troca(int *vet, int i, int j)
{
    int aux = vet[i];
    vet[i] = vet[j];
    vet[j] = aux;
}

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
    // Criar arrays temporários
    int L[n1], R[n2];
    // Copiar os dados para os arrays temporários
    for (i = 0; i < n1; i++)
    {
        L[i] = vetor[inicio + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = vetor[meio + 1 + j];
    }

    i = 0, j = 0;
    k = inicio;
    while (i < n1 && j < n2)
    { // enquanto o indexador nao ultrapssar o fim dos arrays
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
}

void mergeSort(int *vet, int inicio, int fim)
{
    if (inicio >= fim)
        return;
    int meio = (inicio + fim) / 2;

    // Ordena as duas partes
    mergeSort(vet, inicio, meio);
    mergeSort(vet, meio + 1, fim);

    // Junta partes já ordenadas
    merge(vet, inicio, meio, fim);
}

void randomVet(int n,int *vet){

    for(int i=0;i<n;i++){
        vet[i] = rand()%500;
    }


}

int main()
{   
    srand(time(NULL));
    clock_t  temp;
    int n = 100000;
    int *vet = (int * )malloc(n*sizeof(int));
    if(vet == NULL) return -1;
    //int n = sizeof(vet)/4;

    randomVet(n,vet);

    temp = clock();
    mergeSort(vet, 0, n-1);
    temp = clock()-temp;
     
    PrintVet(n,vet);
    printf("\n");
    printf("Tempo: %lf",((double)temp)/((CLOCKS_PER_SEC/1000)));
    free(vet);
    return 0;
}
