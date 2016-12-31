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

#include "libs/utils.h"
#include "libs/QuickSort.h"
#include "libs/benchmark.h"
#include <pthread.h>

struct thread_quick_data {
    __uint64_t *vector;
    int start, end;
};

void *compute_sort(struct thread_quick_data *data) {
    quickSort(data->vector, data->start, data->end);
    return 0;
}

int main(int argc, char **argv) {
    __uint64_t *vector = randomVector(1000000);
    __uint64_t delta = granularity();

    struct timespec start, end;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);

    //quickSort(vector, 0, __VECTOR_LEN);       //singlethread

    //multithread
    pthread_t th1, th2;
    struct thread_quick_data th1data, th2data;
    int th1Estat=-1, th2Estat=-1;

    th1data.start = 0;
    th1data.end = partition(vector, 0, __VECTOR_LEN);
    th1data.vector = vector;

    th2data.start = th1data.end + 1;
    th2data.end = __VECTOR_LEN;
    th2data.vector = vector;

    pthread_create(&th1, NULL, (void *) compute_sort, &th1data);
    pthread_create(&th2, NULL, (void *) compute_sort, &th2data);

    pthread_join(th1, (void *) &th1Estat);
    pthread_join(th2, (void *) &th2Estat);

    printf("pivot: %d\n",th1data.end);
    printf("th1Estat: %d\n", th1Estat);
    printf("th2Estat: %d\n", th2Estat);

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);

    printf("order: %s\n", isOrder(vector, 0, __VECTOR_LEN) ? "true" : "false");
    printf("time: %"PRId64" + delta %"PRId64"ns\n", end.tv_nsec - start.tv_nsec, delta);

    printFile4Plot(vector);

    //printVector(vector, th1data.end, th1data.end+40);

    return 0;
}