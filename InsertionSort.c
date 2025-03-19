#include <stdio.h>
#include <stdlib.h>

void troca(int *vet, int i, int j)
{
    int aux = vet[i];
    vet[i] = vet[j];
    vet[j] = aux;
}

//todos os elementos anteriores ao indice do loop devem estar ordenados 

void insertionSort(int n, int *vet){

    for(int i=1;i<n;i++){ // o elemento vet[0] ja esta ordenado 
        for(int j=i;j>0 && vet[j]<vet[j-1];j--){ // se o elemento for menor que o anterior, sao invertidos 
            troca(vet,j,j-1);
        }
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

    insertionSort(n,vetor);
    PrintVet(n, vetor);

    return 0;
}
