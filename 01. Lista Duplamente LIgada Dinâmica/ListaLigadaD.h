#ifndef LISTALIGADAD_H
#define LISTALIGADAD_H

#include <stdbool.h>

typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
    // outros campos...
} REGISTRO;

typedef struct tempRegistro {
    REGISTRO reg;
    struct tempRegistro *ant, *prox;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
    PONT inicio;
} LISTA;

void inicializarLista(LISTA* l);
void exibirLista(LISTA* l);
PONT buscaSeqExc(LISTA* l, TIPOCHAVE ch, PONT* ant);
bool excluirElemLista(LISTA* l, TIPOCHAVE ch);
void reinicializarLista(LISTA* l);
bool inserirElemListaOrd(LISTA* l, REGISTRO reg);

#endif // LISTALIGADAD_H
