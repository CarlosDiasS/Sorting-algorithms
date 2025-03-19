#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int Left(int n)
{
    return 2 * n + 1;
}
int Right(int n)
{
    return 2 * n + 2;
}

void PrintVet(int *vet, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vet[i]);
    }
    printf("\n");
}

void Troca(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void MaxHeapify(int *vet, int i, int n)
{
    int maior = i;
    int left = Left(i);
    int right = Right(i);

    if (left < n && vet[left] > vet[maior])
    {
        maior = left;
    }

    if (right < n && vet[right] > vet[maior])
    {
        maior = right;
    }
    if (maior != i)
    {
        Troca(&vet[i], &vet[maior]);
        MaxHeapify(vet, maior, n);
    }
}

void buildMaxHeap(int *vet, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    { // exclui o Maxheapify para as folhas
        MaxHeapify(vet, i, n);
    }
}

int getMax(int *vet)
{
    return vet[0];
}

void increaseKey(int *vet, int i,int n){

    vet[i]++;
    buildMaxHeap(vet,n);
}
void decreaseKey(int *vet, int i,int n){

    vet[i]--;
    buildMaxHeap(vet,n);
}

int main(int argc, char const *argv[])
{
    int vet[] = {1, 16, 14, 10, 8, 7, 3, 4, 1};
    int n = sizeof(vet) / sizeof(vet[0]);
    buildMaxHeap(vet, n);
    PrintVet(vet, n);
    printf("%d", getMax(vet));
    printf("\n");
    increaseKey(vet,2,n);
    PrintVet(vet, n);
    printf("\n");
    decreaseKey(vet,3,n);
    PrintVet(vet, n);
    return 0;
}
