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

void printVector(int *a, int from, int to);

void swap(int *a, int *b);

int *randomVector(int dim);

int isOrder(int *a, int from, int to);

#endif //THREADTEST_QUICKSORT_UTILS_H
