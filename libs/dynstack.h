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

#ifndef THREADTEST_QUICKSORT_DYNSTACK_H
#define THREADTEST_QUICKSORT_DYNSTACK_H

#include <stddef.h>
#include <stdlib.h>

struct dynamicStack {
    size_t pointerSize;
    void *pointer;
    unsigned int pos;
    struct dynamicStack *next;

};
typedef struct dynamicStack dynstack_t;

/**
 * Add an element on stack
 *
 * @param stack
 * @param element
 * @param size
 * @return
 */
dynstack_t *dynstack_push(dynstack_t *stack, void *element, size_t size);

/**
 * return the dimension of stack
 *
 * @param stack
 * @return
 */
unsigned int dynstack_dimension(dynstack_t *stack);

/**
 * return the first element of stack, and decrease it.
 * @param stack
 * @return
 */
void *dynstack_pop(dynstack_t **stack);

#endif //THREADTEST_QUICKSORT_DYNSTACK_H
