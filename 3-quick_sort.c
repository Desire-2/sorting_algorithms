#include "sort.h"

/**
 * swap_items - Swaps two items in an array.
 * @array: Array to modify.
 * @l: Index of the left item.
 * @r: Index of the right item.
 */
void swap_items(int *array, size_t l, size_t r)
{
	int _tmp;

	if (array != NULL)
	{
		_tmp = array[l];
		array[l] = array[r];
		array[r] = _tmp;
	}
}

/**
 * quick_sort_range_lomuto - Sorts a sub array using the
 * quick sort algorithm and Lomuto's partition scheme.
 * @array: Array containing the sub-array.
 * @low: Starting position of the sub-array.
 * @high: Ending position of the sub-array.
 * @size: Length of the array.
 */
void quick_sort_range_lomuto(int *array, size_t low, size_t high, size_t size)
{
	size_t y, r;
	int _pivot;

	if ((low >= high) || (array == NULL))
		return;
	_pivot = array[high];
	y = low;
	for (r = low; r < high; r++)
	{
		if (array[r] <= _pivot)
		{
			if (y != r)
			{
				swap_items(array, y, r);
				print_array(array, size);
			}
			y++;
		}
	}
	if (y != high)
	{
		swap_items(array, y, high);
		print_array(array, size);
	}
	if (y - low > 1)
		quick_sort_range_lomuto(array, low, y - 1, size);
	if (high - y > 1)
		quick_sort_range_lomuto(array, y + 1, high, size);
}

/**
 * quick_sort - Sorts an array using the quick sort algorithm
 *		and Lomuto's partition scheme.
 * @array: Array to sort.
 * @size: Length of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL)
	{
		quick_sort_range_lomuto(array, 0, size - 1, size);
	}
}
