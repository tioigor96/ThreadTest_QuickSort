/*
 * Copyright (C) 2016 Igor 03/01/17.
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

#include "../libs/nplacestack.h"

npstack_t *initnpstack(unsigned char len) {
    npstack_t *stack = malloc(sizeof(npstack_t));
    stack->stack = malloc(sizeof(voiddata_t) * len);
    stack->len = len;
    stack->size = 0;

    return stack;
}

unsigned char npstack_dimension(npstack_t *stack) {
    return stack->size;
}

unsigned char npstack_maxsize(npstack_t *stack) {
    return stack->len;
}

int npstack_push(npstack_t *stack, void *ptr, size_t size) {
    if (stack->size >= stack->len) {
        return 0;
    } else {
        stack->stack[stack->size].pnt = ptr;
        stack->stack[stack->size].size = size;
        stack->size++;
    }

    return 1;
}

void *npstack_pop(npstack_t *stack) {
    void *ptr = NULL;

    if (stack->size > 0) {
        ptr = stack->stack[stack->size - 1].pnt;
        stack->size--;
    }

    return ptr;
}