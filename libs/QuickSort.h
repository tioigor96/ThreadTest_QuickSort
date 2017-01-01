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

#ifndef THREADTEST_QUICKSORT_QUICKSORT_H
#define THREADTEST_QUICKSORT_QUICKSORT_H

#include "utils.h"
#include "dynstack.h"

struct _qs_iter_limits {
    int from;
    int to;
};
typedef struct _qs_iter_limits qs_limits;

/**
 * Partition function: create an array partitioned "from" to "to" in:
 * vector{from -> [return value - 1]} < [return value] < vector{[return value + 1] -> to};
 * Limits: from index included, to index excluded (v = [from ; to))
 * @param vector
 * @param from
 * @param to
 * @return
 */
int partition(uint64_t *vector, int from, int to);

/**
 * Recursive quicksort;
 * Limits: from index included, to index excluded (v = [from ; to))
 * @param vector
 * @param from
 * @param to
 */
void quickSort(uint64_t *vector, int from, int to);

void *quicksortI(uint64_t *vector, int from, int to);


#endif //THREADTEST_QUICKSORT_QUICKSORT_H
