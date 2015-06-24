#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define MAX 18


int main()
{
    int i = 0, vetor[MAX] = {2,8,4 ,6,1,8 ,3,9,5 ,7,88,29 ,49,22,22 ,80,24,82};

    shellSort(&vetor);

    for( i = 0; i < MAX; i++)
    {
        printf("%d, " , vetor[i]);
    }

}


void shellSort(int *vetor)
{
   int i = (MAX - 1) / 2;
   int chave, k, aux;

   while(i != 0)
   {
      do
      {
         chave = 1;
         for(k = 0; k < MAX - i; ++k)
         {
            if(vetor[k] > vetor[k + i])
            {
               aux = vetor[k];
               vetor[k] = vetor[k + i];
               vetor[k + i] = aux;
               chave = 0;
            }
         }
      }while(chave == 0);
      i = i / 2;
   }
}
