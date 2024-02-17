#include <stdio.h>
#include "bit_ops.h"

// Return the nth bit of x.
// Assume 0 <= n <= 31
unsigned get_bit(unsigned x,
                 unsigned n) {
    // YOUR CODE HERE
    // Returning -1 is a placeholder (it makes
    // no sense, because get_bit only returns 
    // 0 or 1)
    unsigned rightshift_n = x >> n;
    unsigned leftshift_31 = rightshift_n << 31;
    unsigned rightshift_31 = leftshift_31 >> 31;
    unsigned result = 0 | rightshift_31;
    return result;
}
// Set the nth bit of the value of x to v.
// Assume 0 <= n <= 31, and v is 0 or 1
void set_bit(unsigned * x,
             unsigned n,
             unsigned v) {
    // YOUR CODE HERE
    unsigned notx = ~ *x;
    unsigned notx_nthbit1 = notx | (1 << n);
    unsigned x_nthbit_0 = ~ notx_nthbit1;
    unsigned nthbit_value = v << n;
    unsigned result = x_nthbit_0 | nthbit_value;
    *x = result;
}

// Flip the nth bit of the value of x.
// Assume 0 <= n <= 31
void flip_bit(unsigned * x,
              unsigned n) {
    // YOUR CODE HERE
    unsigned nthBitValue = get_bit(*x, n);
    unsigned flipValue = ((~nthBitValue) << 31) >> 31;
    set_bit(x, n, flipValue);
}

