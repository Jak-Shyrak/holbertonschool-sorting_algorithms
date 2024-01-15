#include "sort.h"
/**
 * swap - Swaps two elements of an array
 * @a: Integer a
 * @b: Integer b
 */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
/**
 * bubble_sort - Doubly linked list node
 * @array: Array of integers to print
 * @size: Size of the array
 */
void bubble_sort(int *array, size_t size) 
{
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
                print_array(array, size);   
            }
            
        }
    }
}