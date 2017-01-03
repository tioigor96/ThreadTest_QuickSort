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

#include "../libs/QuickSort.h"

int partition(uint64_t *vector, int from, int to) {
    int pivot = from;

    for (int i = from; i < to - 1; i++) {
        if (vector[i] <= vector[to - 1]) {
            swap(vector + i, vector + pivot);
            pivot++;
        }
    }

    swap(vector + pivot, vector + to - 1);

    // i don't return pivot+1 because the pivot sign the real halfway position
    return pivot;
}

void recursiveQuickSort(uint64_t *vector, int from, int to) {
    if (from < to) {
        int pivot = partition(vector, from, to);    //pivot is in correct position
        recursiveQuickSort(vector, from, pivot);             //pivot is the last real position of last element
        recursiveQuickSort(vector, pivot + 1, to);           //pivot + 1 is the first element to order
    }
}

void iterativeQuicksort(uint64_t *vector, int from, int to) {
    dynstack_t *stack = NULL;
    qs_limits *limit = malloc(sizeof(qs_limits)), *aux;
    limit->from = from;
    limit->to = to;

    stack = dynstack_push(stack, (void *) limit, sizeof(qs_limits));

    while (dynstack_dimension(stack) > 0) {
        limit = (qs_limits *) dynstack_pop(&stack);
        if (limit->from < limit->to) {

            int pivot = partition(vector, limit->from, limit->to);

            aux = malloc(sizeof(qs_limits));
            aux->from = limit->from;
            aux->to = pivot;
            stack = dynstack_push(stack, (void *) aux, sizeof(qs_limits));

            aux = malloc(sizeof(qs_limits));
            aux->from = pivot + 1;
            aux->to = limit->to;
            stack = dynstack_push(stack, (void *) aux, sizeof(qs_limits));
        }
        free(limit);
    }
}

void iterativeQuicksort_nplace(uint64_t *vector, int from, int to) {
    npstack_t *stack = initnpstack(superiorLog(sizeof(int), to - from + 1) << 2);
    qs_limits *limit = malloc(sizeof(qs_limits)), *aux;
    limit->from = from;
    limit->to = to;

    npstack_push(stack, (void *) limit, sizeof(qs_limits));

    while (npstack_dimension(stack) > 0) {
        limit = (qs_limits *) npstack_pop(stack);
        if (limit->from < limit->to) {

            int pivot = partition(vector, limit->from, limit->to);

            aux = malloc(sizeof(qs_limits));
            aux->from = limit->from;
            aux->to = pivot;
            npstack_push(stack, (void *) aux, sizeof(qs_limits));

            aux = malloc(sizeof(qs_limits));
            aux->from = pivot + 1;
            aux->to = limit->to;
            npstack_push(stack, (void *) aux, sizeof(qs_limits));
        }
        free(limit);
    }
}
