#include "pilhaEstatica.h"
#include <stdio.h>
#include <stdlib.h>

void inicializarPilha(PILHA* p) {
    p->topo = -1;
}

void exibirPilha(PILHA* p) {
    printf("Pilha: \" ");
    for (int i = p->topo; i >= 0; i--) {
        printf("%i ", p->A[i].chave);
    }
    printf("\"\n");
}

void exibirPilhaInvertida(PILHA* p) {
    printf("Pilha (da base para o topo): \" ");
    for (int i = 0; i <= p->topo; i++) {
        printf("%i ", p->A[i].chave);
    }
    printf("\"\n");
}

void reinicializarPilha(PILHA* p) {
    p->topo = -1;
}

bool inserirElementoPilha(PILHA* p, REGISTRO reg) {
    if (p->topo + 1 >= MAX) return false;
    p->A[++p->topo] = reg;
    return true;
}