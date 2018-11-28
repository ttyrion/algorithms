#include "sort.h"

namespace algorithm {
    namespace sort{
        /**
         * @size the size of the unsorted array
         * @return the index of pivot in the result array
        */
        int partition(int *array, int size) {
            if(size <= 1) {
                return size-1;
            }

            int pivot = array[size-1];
            int i = 0;
            /**
             * After the loop, i points to the element greater than pivot.
             * And:
             * array[k] <= pivot for k in [0, i)
             * array[k] > pivot for k in [i, size-1)
            */
            for (int iter = 0; iter < size-1; ++iter) {
                if(array[iter] <= pivot) {
                    if (i == iter) {
                        ++i;
                        continue;
                    }
                    int swap = array[i];
                    array[i] = array[iter];
                    array[iter] = swap;
                    ++i;
                }
            }
            array[size-1] = array[i];
            array[i] = pivot;
            return i;
        }

        void quick_sort(int *array, int size) {
            if(size <= 1) {
                return;
            }
            int pivot_index = partition(array, size);
            quick_sort(array, pivot_index);
            quick_sort(array + pivot_index + 1 , size-pivot_index-1);
        }
    }
}