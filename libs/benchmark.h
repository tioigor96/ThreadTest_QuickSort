/*
 * Copyright (C) 2016 Igor 30/12/16.
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

#ifndef THREADTEST_QUICKSORT_BENCHMARK_H
#define THREADTEST_QUICKSORT_BENCHMARK_H

#include <time.h>
#include <inttypes.h>

/**
 * First implementation for banchmarking
 * P.S.: for print the __uint64 use:
 * printf("%"PRId64"\n",granularity());
 * @return
 */
uint64_t granularity();

void getTime(struct timespec *var);

#endif //THREADTEST_QUICKSORT_BENCHMARK_H
