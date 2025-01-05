/******************************************************************************
//     filaDinamica.c
// Este programa gerencia filas lineares ligadas (implementacao dinamica).
// As filas gerenciadas podem ter um numero arbitrario de elementos.
// Não usaremos sentinela ou cabeça nesta estrutura.
******************************************************************************/
#include <stdio.h>
#include <malloc.h>
#define ERRO -1
#define true 1
#define false 0
typedef int bool;
typedef int TIPOCHAVE;

typedef struct {
  TIPOCHAVE chave;
  // outros campos...
} REGISTRO;

typedef struct aux {
  REGISTRO reg;
  struct aux* prox;
} ELEMENTO, *PONT;;

typedef struct {
  PONT cabeca; //Aqui so mudei o nome de inicio para cabeca para melhor compreensao, eles são do mesmo tipo PONT
  PONT fim;
} FILA;

 
void inicializarFila(FILA* f){
  f->cabeca = (PONT) malloc(sizeof(ELEMENTO));
  f->cabeca->prox = NULL; //O cabeca aponta para nada, pois nao ha elementos validos ainda
  f->fim = f->cabeca; //O fim aponta para o cabeca
} /* inicializarFila */



/* Inserção no fim da fila */
bool inserirNaFila(FILA* f,REGISTRO reg) {
  PONT novo = (PONT) malloc(sizeof(ELEMENTO));
  novo->reg = reg;
  novo->prox = NULL;
  f->fim->prox = novo;
  f->fim = novo;
  return true;
} /* inserir */

/* Excluir  */
bool excluirDaFila(FILA* f, REGISTRO* reg) {
  if (f->cabeca->prox==NULL){ //"se a fila for vazia (antes da exclusao)"
    return false;                     
  }
  PONT apagar = f->cabeca->prox;
  *reg = apagar->reg;
  f->cabeca->prox = apagar->prox;
  if (f->cabeca->prox == NULL){ //"se a fila for vazia (depois da exclusao)"
    f->fim = f->cabeca;
  }
  free(apagar);
  return true;
} /* excluirDaFila */


/* Exibição da fila sequencial */
void exibirFila(FILA* f){
  PONT end = f->cabeca->prox;
  printf("Fila: \" ");
  while (end != NULL){
    printf("%d ", end->reg.chave);
    end = end->prox;
  }
  printf("\"\n");
} /* exibirFila */ 

int main(){
  FILA fila;
  REGISTRO reg1 = {10};
  REGISTRO reg2 = {2};
  REGISTRO reg3 = {5};

  inicializarFila(&fila);

  inserirNaFila(&fila, reg1);
  inserirNaFila(&fila, reg2);
  inserirNaFila(&fila, reg3);

  exibirFila(&fila);

  REGISTRO excluido;
  excluirDaFila(&fila, &excluido);
  printf("Elemento excluido: %d\n", excluido.chave);
  
  exibirFila(&fila);
}