//
// Created by aluno on 03/10/23.
//
#include <libprg/libprg.h>
#include <stdlib.h>
#include <stdio.h>

void cria_pilha(Pilha *pilha, int capacidade) { //Cria uma alocação de memória do tipo "Pilha"
    //Espaço de memória tem tamanho "float" multiplicado pelo número de elementos máximo da pilha, em bits:
    pilha->valores = malloc((sizeof (float)) * capacidade);
    if (pilha->valores == NULL) { //Caso não seja possível criar o espaço exibe mensagem de erro
        printf("Falha na alocação de memória\n");
        exit(1);
    }

    // Atribui os valores iniciais da Pilha
    pilha-> capacidade = capacidade;
    pilha-> topo = 0;
}

void imprime_pilha(Pilha *pilha) { //Percorre todos os valores da Pilha, do inicío ao topo, imprimindo cada um deles
    for (int i = 0; i < (pilha-> topo); ++i) {
        printf("%f ", pilha-> valores[i]);
    }
    printf("\n");
}

void empilhar (Pilha *pilha, float p) { //Coloca o valor "p" no topo da Pilha e aumento o "Topo" em 1
    pilha->valores[pilha->topo] = p;
    pilha->topo++;
}

float desempilhar (Pilha *pilha) { //Retorna o valor no topo da pilha e reduz o "Topo" em 1
    if (vazia(pilha)) {
    } else {
        pilha->topo--;
        float p = pilha->valores[pilha->topo];
        return p;
    }
}

int tamanho (Pilha *pilha) { //Retorna o número de elemento na pilha
    return pilha->topo;
}

int vazia (Pilha *pilha) {
    if (pilha->topo == 0) {
        return 1;
    }
    return 0;
}

void notacao_polonesa_inversa (int argc, char *argv[]) {
    Pilha pilha_polonesa;
    cria_pilha(&pilha_polonesa, argc);

    for (int i = 1; i < argc; ++i) {
        char *p = argv[i];
        if (*p == '*') {
            float n;
            n = desempilhar(&pilha_polonesa);
            n *= desempilhar(&pilha_polonesa);
            empilhar(&pilha_polonesa, n);
        } else if (*p == '+') {
            float n;
            n = desempilhar(&pilha_polonesa);
            n  += desempilhar(&pilha_polonesa);
            empilhar(&pilha_polonesa, n);
        } else if (*p == '/') {
            float n;
            n = desempilhar(&pilha_polonesa);
            n = desempilhar(&pilha_polonesa) / n;
            empilhar(&pilha_polonesa, n);
        } else if (*p == '-') {
            float n;
            n = desempilhar(&pilha_polonesa);
            n = desempilhar(&pilha_polonesa) - n;
            empilhar(&pilha_polonesa, n);
        } else {
            *p = atof(p);
            empilhar(&pilha_polonesa, *p);
        }

    }
    imprime_pilha(&pilha_polonesa);
}