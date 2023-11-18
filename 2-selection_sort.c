#include "sort.h"
#include <stdio.h>


/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: The array
 * @size: The size of the array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t r, _stp, _minIdx;
	int _tmp;

	for (_stp = 0; _stp < size - 1; _stp++)
	{
		_minIdx = _stp;
		for (r = _stp + 1; r < size; r++)
		{
			if (array[r] < array[_minIdx])
				_minIdx = r;
		}

		if (-minIdx != _stp)
		{
			_tmp = array[_stp];
			array[_stp] = array[_minIdx];
			array[_minIdx] = _tmp;
			print_array(array, size);
		}
	}
}
