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

int main(int argc, char **argv) {

    int *vector = randomVector(20);

    quickSort(vector, 0, 20);

    printf("order: %s\n", isOrder(vector, 0, 20) ? "true" : "false");

    printVector(vector, 0, 20);

    return 0;
}