#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <time.h>
#define MAX 18

struct Tabela{

char *nome;
float tempoMedio;
float tempoTotal;
int numeroTrocas;
int numeroComparacoes;
int comparacoesMelhorCaso;
int trocasMelhorCaso;
int comparacoesPiorCaso;
float tempoMelhorCaso;
int trocasPiorCaso;
float tempoPiorCaso;

};

struct Resultado{
int comparacoes;
int trocas;
float tempo;
};

void imprimeResultado(struct Tabela tabela)
{
printf("\n______________________________________________________");
printf("\nMetodo: %s",tabela.nome);
printf("\nNumero de Trocas: %d",tabela.numeroTrocas);
printf("\nNumero de Comparacoes: %d",tabela.numeroComparacoes);
printf("\nTempo Total: %.3f",tabela.tempoTotal);

printf("\nNumero de comparacoes melhor caso: %d",tabela.comparacoesMelhorCaso);
printf("\nNumero de trocas Melhor Caso: %d",tabela.trocasMelhorCaso);
printf("\nTempo melhor caso: %f",tabela.tempoMelhorCaso);

printf("\nNumero de comparacoes Pior caso: %d",tabela. comparacoesPiorCaso);
printf("\nNumero de trocas Pior caso: %d",tabela.trocasPiorCaso);
printf("\nTempo pior caso : %.3f",tabela.tempoPiorCaso);

printf("\n________________________________________________________\n");
}


struct Resultado bubbleSort(int *vetor)
{
  int swap = 0;
  int end = MAX - 1;
  int i;
  float tInicial, tFinal, tempo;
  int aux;
  struct Resultado resultado;
  tabela.numeroComparacoes = 0;
  tabela.numeroTrocas = 0;
  tInicial = 0.000;

  while(end > 0 || swap == 1)
  {
      swap = 0;

      for (i = 0; i < end; i++)
      {
          resultado.comparacoes++;  // Numero de comparações ++

          if(vetor[i] > vetor[i+1])
          {
              resultado.trocas++;   // Numero de trocas ++

              aux = vetor[i];
              vetor[i] = vetor[i+1];
              vetor[i+1] = aux;

              swap = 1;
          }
      }
      end--;
  }
  tFinal = 1 ;// tempo fina
  resultado.tempo = tFinal - tInicial;
  return resultado;
}


int main()
{
    setlocale(LC_ALL, "Portuguese");
    struct Tabela tabela;
    tabela.numeroComparacoes = 0;
    tabela.numeroTrocas = 0;

    int vet[MAX] = {1,5,2,4,3,6,9,7,8,10};
    tabela = bubbleSort(vet);
    imprimeResultado(tabela);





    printf("Hello, 2 the world!\n");

    struct Resultado resultado;
    struct Tabela tabelaBubble;
    int vetor[] = {7,3,2,1,5,6,4,8,9,10};

    int vetorBubble[] = vetor[];
    int vetorShell[] = vetor[];
    int vetorTeste[] = vetor[];

    // Normal Buble
    struct Resultado resultado = bubbleSort(vetorTest);
        tabelaBubble.numeroComparacoes = resultado.comparacoes ;
        tabelaBubble.tempoTotal = resultado.tempo;
        tabelaBubble.numeroTrocas = resultado.trocas;

    // Melhor Buble
    struct Resultado resultado = bubbleSort(vetorTest);
        tabelaBubble.comparacoesMelhorCaso = resultado.comparacoes ;
        tabelaBubble.tempoMelhorCaso = resultado.tempo;
        tabelaBubble.trocasMelhorCaso = resultado.trocas;
    ;
    //Inverter array

    // Pior Buble
    struct Resultado resultado = bubbleSort(vetorTest);
        tabelaBubble.comparacoesPiorCaso = resultado.comparacoes ;
        tabelaBubble.tempoPiorCaso = resultado.tempo;
        tabelaBubble.trocasPiorCaso = resultado.trocas;

    for(i=0;i<10;i++)
        printf("%d",vetorTest[i]);


return 0;
}


