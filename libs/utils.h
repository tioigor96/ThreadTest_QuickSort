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


#ifndef THREADTEST_QUICKSORT_UTILS_H
#define THREADTEST_QUICKSORT_UTILS_H

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>

extern const uint64_t __VECTOR_LEN;
extern const uint64_t __PRIME;

void printVector(__uint64_t *a, int from, int to);

void swap(uint64_t *a, uint64_t *b);

uint64_t *randomVector(uint64_t dim);

int isOrder(uint64_t *a, int from, int to);

void printFile4Plot(uint64_t *vector);

#endif //THREADTEST_QUICKSORT_UTILS_H
