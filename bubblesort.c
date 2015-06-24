#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define MAX 18


int main()
{
    int i = 0, vetor[MAX] = {2,8,4 ,6,1,8 ,3,9,5 ,7,88,29 ,49,22,22 ,80,24,82};

    bubbleSort(&vetor);

    for ( i = 0 ; i < MAX ; i++ )
        printf("%d, ", vetor[i]);
}

int bubbleSort(int *vetor)
{
  int swap = 0;
  int end = MAX - 1;
  int i;
  int aux;

  while(end > 0 || swap == 1)
  {
      swap = 0;

      for (i = 0; i < end; i++)
      {
          if(vetor[i] > vetor[i+1])
          {
              aux = vetor[i];
              vetor[i] = vetor[i+1];
              vetor[i+1] = aux;

              swap = 1;
          }
      }
      end--;
  }
}
