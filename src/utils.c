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

void printVector(int *a, int from, int to) {
    for (; from < to; from++)
        printf("%d ", a[from]);
}

void swap(int *a, int *b) {
    int aux = *a;
    *a=*b;
    *b=aux;
}

int* randomVector(int dim) {
    int *a=malloc(sizeof(int)*dim);

    srand(time(NULL));

    for(int i=0; i<dim; i++)
        a[i]=rand()%607;

    return a;
}

int isOrder(int *a, int from, int to) {

    for(;from<to-1; from++)
        if(a[from]>a[from+1])
            return 0;
    return 1;
}
