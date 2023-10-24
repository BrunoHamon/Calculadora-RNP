#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H

typedef struct {
    double value;
    int error;
} result_t;

typedef struct {
    float *valores;
    int capacidade;
    int topo;
} Pilha;

void cria_pilha(Pilha *pilha, int capacidade);
void imprime_pilha(Pilha *pilha);
void empilhar (Pilha *pilha, float p);
float desempilhar (Pilha *pilha);
int tamanho (Pilha *pilha);
int vazia (Pilha *pilha);
void notacao_polonesa_inversa (int argc, char *argv[]);


typedef enum { SUM, SUB } operation_t;

result_t sub(double a, double b);
result_t sum(double a, double b);
result_t compute(double a, double b, operation_t op);

#endif
