#include <stdio.h>
#include <libprg/libprg.h>

int main(int argc, char *argv[]) {
    float resultado = notacao_polonesa_inversa(argc, argv);
    //Chama a fução de calculadora, usando o numero de argumentos e seus valores, via linha de comando.
    printf("%f\n", resultado);
    return 0;
}