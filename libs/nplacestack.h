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

#ifndef THREADTEST_QUICKSORT_NPLACESTACK_H
#define THREADTEST_QUICKSORT_NPLACESTACK_H

#include <stddef.h>
#include <malloc.h>

struct voidData {
    void *pnt;
    size_t size;
};
typedef struct voidData voiddata_t;

struct npstack {
    voiddata_t *stack;
    unsigned char len;
    unsigned char size;
};
typedef struct npstack npstack_t;

/**
 * init a n-place stack (allocated dynamically)
 * @param len
 * @return
 */
npstack_t *initnpstack(unsigned char len);

/**
 * Get the current number of allocated item in stack.
 * @param stack
 * @return
 */
unsigned char npstack_dimension(npstack_t *stack);

/**
 * Get the maximum number of item in stack.
 * @param stack
 * @return (void *)ptr
 */
unsigned char npstack_maxsize(npstack_t *stack);

/**
 * Push element in stack. If return 0 the stack is full, 1 in other cases.
 * @param stack
 * @param ptr
 * @param size
 * @return
 */
int npstack_push(npstack_t *stack, void *ptr, size_t size);

/**
 * Pop element in stack.
 * @param stack
 * @return (void *)ptr
 */
void *npstack_pop(npstack_t *stack);

#endif //THREADTEST_QUICKSORT_NPLACESTACK_H
