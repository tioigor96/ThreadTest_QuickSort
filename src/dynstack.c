/*
 * Copyright (C) 2016 Igor 31/12/16.
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

#include "../libs/dynstack.h"

dynstack_t *push(dynstack_t *stack, void *element, size_t size) {
    if (stack == NULL) {
        stack = (dynstack_t *) malloc(sizeof(dynstack_t));
        stack->pos = 0;
        stack->next = NULL;
    } else {
        dynstack_t *aux = (dynstack_t *) malloc(sizeof(dynstack_t));
        aux->next = stack;
        aux->pos = stack->pos + 1;
        stack = aux;
    }
    stack->pointer = element;
    stack->pointerSize = size;

    return stack;
}

unsigned int stack_dimension(dynstack_t *stack) {

    return stack != NULL ? stack->pos + 1 : 0;
}

void *pop(dynstack_t **stack) {
    if (*stack == NULL) {
        return NULL;
    }

    void *ret = (*stack)->pointer;
    dynstack_t *aux = (*stack);
    *stack = (*stack)->next;
    free(aux);

    return ret;
}