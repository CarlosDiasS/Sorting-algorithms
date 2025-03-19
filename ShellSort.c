#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


void ShellSort(int *vet, int n){

    int i,j,chave;

    int h=1;
    while(h<n){
        h = h*3+1;
    }
    while(h>0){
        for(i=h;i<n;i++){
            chave = vet[i];
            j=i;
        }
        while (j>h-1 && chave <= vet[j-h]){
            vet[j] = vet[j-h];
            j = j-h;
        }
        vet[j] = chave;
    }
    h = h/3;

}








main(){



    return 0;
}