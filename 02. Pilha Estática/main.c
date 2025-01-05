#include "pilhaEstatica.h"
#include "pilhaEstatica.c"
#include <stdio.h>


int main() {
    PILHA pilha;
    REGISTRO reg1 = {4};
    REGISTRO reg2 = {2};
    REGISTRO reg3 = {9};
    REGISTRO reg4 = {7};

    //Inicializando pilha
    inicializarPilha(&pilha);
    
    //Inserindo 4 elementos novos do tipo reg
    inserirElementoPilha(&pilha, reg1);
    inserirElementoPilha(&pilha, reg2);
    inserirElementoPilha(&pilha, reg3);
    inserirElementoPilha(&pilha, reg4);

    //Exibindo pilha normal (do topo pra base)
    exibirPilha(&pilha);

    //Exibindo pilha invertida (da base pro topo)
    exibirPilhaInvertida(&pilha);

    reinicializarPilha(&pilha);
    return 0;
}
