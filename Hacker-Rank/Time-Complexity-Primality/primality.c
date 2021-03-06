/*  Problem Statement: https://www.hackerrank.com/challenges/ctci-big-o/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=miscellaneous
    Author: striker
*/

#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>
#include<stdbool.h>
#include<assert.h>

static const bool check_primality(uint32_t);

int main(void) {
    uint8_t test;
    scanf("%"SCNu8, &test);
    assert(test > 0 && test < 31);
    while(test--) {
        uint32_t n;
        scanf("%"SCNu32, &n);
        assert(n > 0 && n < 2000000001);
        printf("%s", check_primality(n) ? "Prime\n" : "Not prime\n");
    }
    return EXIT_SUCCESS;
}

static const bool check_primality(uint32_t n) {
    bool is_prime = true;
    if(n < 2) {
        is_prime = false;
    } else if(n == 2 || n == 3) {
        is_prime = true;
    } else if(!(n % 2) || !(n % 3)) {
        is_prime = false;
    } else {
        for(uint64_t i = 5; (i * i) <= n; ++i) {
            if(!(n % i)) {
                is_prime = false;
                break;
            }
        }
    }
    return is_prime;
}