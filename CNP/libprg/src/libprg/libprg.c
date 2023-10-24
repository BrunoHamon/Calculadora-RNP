#include "libprg/libprg.h"

result_t compute(double a, double b, operation_t op){

    result_t res = {.value = -1, .error = 1};

    switch (op) {
        case SUM:
            return sum(a, b);
        case SUB:
            return sub(a, b);
        default:
            return res;
    }
}