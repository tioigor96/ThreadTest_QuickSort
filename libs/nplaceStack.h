//
// Created by igor on 03/01/17.
//

#ifndef THREADTEST_QUICKSORT_NPLACESTACK_H
#define THREADTEST_QUICKSORT_NPLACESTACK_H

#include <stddef.h>
#include <malloc.h>

#define __STACK_INCREASE    8

struct voidData{
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
