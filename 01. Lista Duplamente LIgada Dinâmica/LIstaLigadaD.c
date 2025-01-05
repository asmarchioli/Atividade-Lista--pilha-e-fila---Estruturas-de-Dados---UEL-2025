#include "listaLigadaD.h"
#include <stdio.h>
#include <stdlib.h>

void inicializarLista(LISTA* l) {
  l->inicio = NULL;
}

void exibirLista(LISTA* l) {
  PONT end = l->inicio;
  printf("Lista: \" ");
  while (end != NULL) {
    printf("%d ", end->reg.chave);
    end = end->prox;
  }
  printf("\"\n");
}

PONT buscaSeqExc(LISTA* l, TIPOCHAVE ch, PONT* anterior) {
  *anterior = NULL;
  PONT atual = l->inicio;
  while (atual != NULL && atual->reg.chave < ch) {
    *anterior = atual;
    atual = atual->prox;
  }
  if (atual != NULL && atual->reg.chave == ch) return atual;
  return NULL;
}

bool excluirElemLista(LISTA* l, TIPOCHAVE ch) {
  PONT anterior, i;
  i = buscaSeqExc(l, ch, &anterior);
  if (i == NULL) return false;
  if (anterior == NULL) {
    l->inicio = i->prox;
    if (l->inicio != NULL) l->inicio->ant = NULL;
  } else {
    anterior->prox = i->prox;
    if (i->prox != NULL) i->prox->ant = i->ant;
  }
  free(i);
  return true;
}

void reinicializarLista(LISTA* l) {
  PONT end = l->inicio;
  while (end != NULL) {
    PONT apagar = end;
    end = end->prox;
    free(apagar);
  }
  l->inicio = NULL;
}

bool inserirElemListaOrd(LISTA* l, REGISTRO reg) {
  TIPOCHAVE ch = reg.chave;
  PONT anterior, i;
  i = buscaSeqExc(l, ch, &anterior);
  if (i != NULL) return false;
  i = (PONT)malloc(sizeof(ELEMENTO));
  i->reg = reg;

  if (anterior == NULL) {
    i->prox = l->inicio;
    if(l->inicio != NULL){ //Verifica se a lista não é vazia, aí atualiza o anterior do antigo inicio para o novo elemento inicio
      l->inicio->ant = i;
    }
    l->inicio = i;
    i->ant = NULL;
  } else {
    i->ant = anterior;
    i->prox = anterior->prox;
    anterior->prox = i;
    if (i->prox != NULL){ //Verifica se o próx do elemento inserido não é NULL (ou seja, não está no final da lista), e atualiza o anterior do próximo para o elemento novo
      i->prox->ant = i;
    }
  }
  return true;
}

