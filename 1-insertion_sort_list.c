#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a DLL of integers in
 *		Ascending Order Using the Insertion sort
 * algorithm
 *
 * @list: Doubly linked list
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *_ptr, *_tmp;

	if (!list)
		return;

	_ptr = *list;

	while (_ptr)
	{
		while (_ptr->next && (_ptr->n > _ptr->next->n))
		{
			_tmp = _ptr->next;
			_ptr->next = _tmp->next;
			_tmp->prev = _ptr->prev;

			if (_ptr->prev)
				_ptr->prev->next = _tmp;

			if (_tmp->next)
				_tmp->next->prev = _ptr;

			_ptr->prev = _tmp;
			_tmp->next = _ptr;

			if (_tmp->prev)
				_ptr = _tmp->prev;
			else
				*list = _tmp;

			print_list(*list);
		}
		_ptr = _ptr->next;
	}
}
