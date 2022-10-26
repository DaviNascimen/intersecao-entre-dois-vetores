#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ini 0
#define mx 100

void imprimirVetor(int *, int );
void preencherVetor(int *, int , int , int);
int conta_igual(int *,int *,int ,int ,int );
void imprimiC(int *,int *,int *,int,int);


int main(int argc, char *argv[]){
  int *a=NULL;
  int *b=NULL;
  int *c=NULL;
  int x=0;

  if(argc!=3){
    printf("Digite:\n\t%s <quantidade de elementos do primeiro vetor> <quantidade de elementos do segundo vetor>",argv[0]);

    return(1);
  }
  
  int qtd1= atoi(argv[1]);
  int qtd2= atoi(argv[2]);

  a=(int *) malloc(qtd1 * (sizeof(int)));  
  b=(int *) malloc(qtd2 * (sizeof(int))); 

  if(!a || !b){
    printf("Não há espaço suficiente!\nTente outra vez!");
    return(2);
  }

  srand(time(NULL));
  preencherVetor(a, qtd1, ini, mx);
  preencherVetor(b, qtd2, ini, mx);

  x= conta_igual(a,b,qtd1,qtd2,x);//quantidade de elementos repetidos

  c= (int *) malloc(x * (sizeof(int)));//espaço alocado para o vetor c
  
  if(!c){
    printf("Não há espaço suficiente!\nTente outra vez!");
    return(3);
  }
  
  printf("Vetor 1:\n");
   imprimirVetor(a, qtd1);

  printf("\n\nVetor 2:\n");
   imprimirVetor(b, qtd2);

  printf("\nVetor 3:");
   imprimiC(a,b,c,qtd1,qtd2);

  free(a);
  free(b);
  free(c);
  
  return 0;
}

//função que imprime os vetores A e B
void imprimirVetor(int *pd, int qtd){
    for (int k=0; k<qtd; k++){
        printf("[%p] %d\n",pd+k,*(pd+k));
    }
}

//função que preenche os vetores A e B
void preencherVetor(int *pd, int qtd, int inicial, int qtdFaixa){
    for (int k=0; k<qtd; k++){
        *(pd+k) = inicial + rand() % qtdFaixa;
      //O "for" abaixo verifica se o número gerado já pertence ao vetor, caso pertença, ele gera novamente outro número na mesma posição
      for (int i=0; i<k; i++){
       if(*(pd+k)==*(pd+i)){
         k--;
       }
      }
    }
}

//função que conta a quantidade de interseções entre A e B
int conta_igual(int *pa,int *pb,int quant1,int quant2,int px){
  for(int i=0; i<quant1; i++){
    for(int k=0; k<quant2; k++){
      if(*(pa+i) == *(pb+k)){
        px++;
        break;
      }
    } 
  }
  return px;
}

void imprimiC(int *pa,int *pb,int *pc,int quant1,int quant2){

  //Esse "for" roda por todos os elementos de A e B e armazena em C
  for(int i=0; i<quant1; i++){
    for(int k=0; k<quant2; k++){
      if(*(pa+i) == *(pb+k)){
        *(pc+i)=*(pa+i);
        printf("\n[%p] %d",(pc+i),*(pc+i));
      }
    } 
  }
if(*pc==0){
  printf("\nNão há interseção entre A e B!");
}
}