#include "listaLigadaD.h"
#include "listaLigadaD.c"

int main() {
    LISTA lista;
    inicializarLista(&lista);

    REGISTRO reg1 = {10};
    REGISTRO reg2 = {20};
    REGISTRO reg3 = {15};

    printf("Inserindo elementos...\n");
    inserirElemListaOrd(&lista, reg1);
    inserirElemListaOrd(&lista, reg2);
    inserirElemListaOrd(&lista, reg3);

    PONT elem = lista.inicio;
    while (elem != NULL) {
        printf("\nPara o elemento %d: ", elem->reg.chave);
        if (elem->ant != NULL) {
            printf("Antecessor: %d, ", elem->ant->reg.chave);
        } else {
            printf("Antecessor: NULL, ");
        }
        if (elem->prox != NULL) {
            printf("Sucessor: %d\n", elem->prox->reg.chave);
        } else {
            printf("Sucessor: NULL\n");
        }
        elem = elem->prox;
    }

    printf("Removendo elemento com chave 15...\n");
    excluirElemLista(&lista, 15);

    elem = lista.inicio;
    while (elem != NULL) {
        printf("\nPara o elemento %d: ", elem->reg.chave);
        if (elem->ant != NULL) {
            printf("Antecessor: %d, ", elem->ant->reg.chave);
        } else {
            printf("Antecessor: NULL, ");
        }
        if (elem->prox != NULL) {
            printf("Sucessor: %d\n", elem->prox->reg.chave);
        } else {
            printf("Sucessor: NULL\n");
        }
        elem = elem->prox;
    }

    reinicializarLista(&lista);
    
    return 0;
}
