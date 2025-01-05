#ifndef PILHA_ESTATICA_H
#define PILHA_ESTATICA_H

#include <stdbool.h>

#define MAX 50
typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct {
    int topo;
    REGISTRO A[MAX];
} PILHA;

void inicializarPilha(PILHA* p);
void exibirPilha(PILHA* p);
void exibirPilhaInvertida(PILHA* p);
void reinicializarPilha(PILHA* p);
bool inserirElementoPilha(PILHA* p, REGISTRO reg);

#endif
    