//
// Created by aluno on 03/10/23.
//
#include <libprg/libprg.h>
#include <stdlib.h>
#include <stdio.h>

void cria_pilha(Pilha *pilha, int capacidade) { //Cria uma alocação de memória do tipo "Pilha"
    //Espaço de memória tem tamanho "float" multiplicado pelo número de elementos máximo da pilha, em bits
    pilha->valores = malloc((sizeof (float)) * capacidade);
    if (pilha->valores == NULL) { //Caso não seja possível criar o espaço exibe mensagem de erro
        printf("Falha na alocação de memória\n");
        exit(1);
    }

    // Atribui os valores iniciais da Pilha
    pilha-> capacidade = capacidade;
    pilha-> topo = 0;
}

void imprime_pilha(Pilha *pilha) { //Percorre os valores da Pilha, do inicío ao (topo-1), imprimindo cada um deles
    for (int i = 0; i < (pilha-> topo); ++i) {
        printf("%f ", pilha-> valores[i]);
    }
    printf("\n");
}

void empilhar (Pilha *pilha, float p) { //Coloca o valor "p" no topo da Pilha e aumento o "Topo" em 1
    pilha->valores[pilha->topo] = p;
    pilha->topo++;
}

float desempilhar (Pilha *pilha) { //Reduz o "Topo" em 1 e retorna o valor no topo da Pilha
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

int vazia (Pilha *pilha) { //Retorna 1 caso a pilha esteja vazia
    if (pilha->topo == 0) {
        return 1;
    }
    return 0;
}

void notacao_polonesa_inversa (int argc, char *argv[]) { //Recebe os argumentos via linha de comando
    Pilha pilha_polonesa; //Declara variável do tipo pilha
    cria_pilha(&pilha_polonesa, argc); //Cria uma pilha com capacidade igual ao número de comandos do terminal

    for (int i = 1; i < argc; ++i) { //Repete de 1 até um número igual a quantidade de comandos do terminal
        char *p = argv[i]; //Declara um ponteiro que aponta para um comando do terminal de acordo com "i"
        if (*p == '*') { //Testa se o comando apontado é o caractere *
            float n; //Declara uma variável do tipo float
            n = desempilhar(&pilha_polonesa); //O topo diminui em 1 e atribui o valor no topo da pilha à variável "n"
            n *= desempilhar(&pilha_polonesa); //Remove o valor no topo da pilha e multiplica "n" pelo próximo, atribuindo o resultado à "n"
            empilhar(&pilha_polonesa, n); //O valor no topo da pilha é substituído por "n" e o topo aumenta em 1
            //Após esse processo é esperado que o topo-1 da pilha seja o resultado da multiplicação
            //O processo para as demais operações é semelhante
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
        } else { //Caso o comando apontado não seja nenhuma das operações anteriores...
            *p = atof(p); //Transforma o comando apontado em um float
            empilhar(&pilha_polonesa, *p); //Atribui o float ao topo da pilha e aumenta o topo em 1
        }

    }
    imprime_pilha(&pilha_polonesa); //Imprime a pilha
}
