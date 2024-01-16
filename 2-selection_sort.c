#include "sort.h"

/**
 * selection_sort - trie un tableau d'entiers par ordre croissant
 * @array: tableau à trier
 * @size: taille de l'élément
 */

/*funct sort an array of integers ascending order using selection sort algo*/
void selection_sort(int *array, size_t size)
{
	/*loop through the array from left to right*/
	size_t i, j, min_index;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		/* Find the index of smallest élément of the array */
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
			}
		}
		/* swap the small élément with 1st élément of unsorted part */
		if (min_index != i)
		{
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;
			/* print the array after each swap */
			print_array(array, size);
		}
	}
}
