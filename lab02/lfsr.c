#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "lfsr.h"

uint16_t get_bit(uint16_t x,
                 uint16_t n) {
    // YOUR CODE HERE
    // Returning -1 is a placeholder (it makes
    // no sense, because get_bit only returns 
    // 0 or 1)
    uint16_t rightshift_n = x >> n;
    uint16_t leftshift_15 = rightshift_n << 15;
    uint16_t rightshift_15 = leftshift_15 >> 15;
    uint16_t result = 0 | rightshift_15;
    return result;
}

void set_bit(uint16_t * x,
             uint16_t n,
             uint16_t v) {
    // YOUR CODE HERE
    uint16_t notx = ~ *x;
    uint16_t notx_nthbit1 = notx | (1 << n);
    uint16_t x_nthbit_0 = ~ notx_nthbit1;
    uint16_t nthbit_value = v << n;
    uint16_t result = x_nthbit_0 | nthbit_value;
    *x = result;
}

void lfsr_calculate(uint16_t *reg) {
    /* YOUR CODE HERE */
    uint16_t xor = (((get_bit(*reg, 0) ^ get_bit(*reg, 2)) ^ get_bit(*reg, 3)) ^ get_bit(*reg, 5));
    *reg = *reg >> 1;
    set_bit(reg, 15, xor);
}
