#include <libprg/libprg.h>

result_t sum(double a, double b){
    result_t res;
    res.value = a + b;
    res.error = 0;
    return res;
}