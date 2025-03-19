#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void PrintVet(int n, int vet[])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }
}

void troca(int *vet, int i, int j)
{
    int aux = vet[i];
    vet[i] = vet[j];
    vet[j] = aux;
}

int particiona(int *vet, int inicio, int fim){

    int pivo = vet[fim];
    int i = inicio - 1; // o indice i comeca a esquerda do vetor vet[-1]

    //J comeca em vet[0], sendo comparado com i
    //asim, todos os elementos a esquerda do pivor, serao menores que ele

    for (int j = inicio; j < fim; j++)   {
        if (vet[j] <= pivo) // se o elemento for menor ou igual o pivo, trocam-se os dois de posicao
        {
            i++;
            troca(vet, i, j);
        }
    }

    //apos o j chegar ao fim do vetor:
    //move o pivô para a posição imediatamente após o último elemento menor ou igual,
    troca(vet, i + 1, fim);
    //retorna a posicao final do pivo (ultimo elemento)
    return i + 1;
}

void QuickSort(int *vet,int inicio,int fim){ // recursao em O(n log n)

    if(inicio<fim){ //caso base
        int p = particiona(vet,inicio,fim); 
        //ordena as sublistas, a esquerda e a direto de p
        QuickSort(vet,inicio,p-1);
        QuickSort(vet,p+1,fim);
    }
}

void randomVet(int n, int *vet)
{
    for (int i = 0; i < n; i++)
    {
        vet[i] = rand() % 20;
    }
}

int main()
{
    int n = 30;

    int *vet = malloc(sizeof(int)*n);
    randomVet(n,vet);

    PrintVet(n,vet);
    
    QuickSort(vet,0,n-1);
    printf("\n");
    PrintVet(n,vet);
    free(vet);
    return 0;
}
