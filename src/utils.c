/*
 * Copyright (C) 2016 Igor 29/12/16.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "../libs/utils.h"

const __uint64_t __VECTOR_LEN = 524288*128; //524288
const __uint64_t __PRIME = 982451653; //982451653

void printVector(__uint64_t *a, int from, int to) {
    for (; from < to; from++)
        printf("%"PRId64" ", a[from]);
    printf("\n");
}

void swap(__uint64_t *a, __uint64_t *b) {
    __uint64_t aux = *a;
    *a = *b;
    *b = aux;
}

__uint64_t *randomVector(__uint64_t dim) {
    __uint64_t *a = malloc(sizeof(__uint64_t) * dim);

    srand(time(NULL));

    for (__uint64_t i = 0; i < dim; i++)
        a[i] = rand() % __PRIME;

    return a;
}

int isOrder(__uint64_t *a, int from, int to) {

    for (; from < to - 1; from++)
        if (a[from] > a[from + 1])
            return 0;
    return 1;
}

void printFile4Plot(__uint64_t *vector) {
    FILE *fd = fopen("plotThis.txt", "w");

    for (__uint64_t i = 0; i < __VECTOR_LEN; i++) {
        fprintf(fd, "%"PRId64"\n", vector[i]);
    }

    fclose(fd);
}
