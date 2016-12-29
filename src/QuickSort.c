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

int partition(int *vector, int from, int to) {
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

int *quickSort(int *vector, int from, int to) {
    if (from < to) {
        int pivot = partition(vector, from, to);    //pivot is in correct position
        quickSort(vector, from, pivot);             //pivot is the last real position of last element
        quickSort(vector, pivot + 1, to);           //pivot + 1 is the first element to order
    }
}
