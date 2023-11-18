0x1B. C - Sorting algorithms & Big O
Description
This project is a collaborative effort between Alexandre Gautier and Desire Bikorimana to implement various sorting algorithms in C and understand the concepts of Big O notation. The project aims to enhance understanding of sorting algorithms, data structures, and algorithmic complexities.

Background Context
This project is designed to be completed in teams of two students, with a focus on pair programming for the mandatory part. The project started on Nov 15, 2023, at 6:00 AM, and must be completed by Nov 22, 2023, at 6:00 AM. The checker tool was released on Nov 17, 2023, at 12:00 AM, and an auto review will be launched at the deadline.

Learning Objectives
Upon completion of this project, you are expected to be able to:

General
Implement at least four different sorting algorithms.
Understand what the Big O notation is and how to evaluate the time complexity of an algorithm.
Select the best sorting algorithm for a given input.
Understand what a stable sorting algorithm is.
Copyright - Plagiarism
Students are required to come up with solutions for the tasks independently. Any form of plagiarism is strictly forbidden and will result in removal from the program.

Requirements
General
Allowed editors: vi, vim, emacs
Compilation on Ubuntu 20.04 LTS using gcc with the options -Wall -Werror -Wextra -pedantic -std=gnu89
All files should end with a new line.
A README.md file at the root of the project folder is mandatory.
Code should follow the Betty style, checked using betty-style.pl and betty-doc.pl.
No use of global variables.
No more than 5 functions per file.
Unless specified otherwise, the standard library is not allowed (e.g., no printf, puts, etc.).
Prototypes of all functions should be included in the header file called sort.h.
Don't forget to push your header file.
All header files should be include guarded.
A list/array does not need to be sorted if its size is less than 2.
Data Structure and Functions
For this project, you are provided with the following print_array and print_list functions:

c
Copy code
#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}

#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
    int i;

    i = 0;
    while (list)
    {
        if (i > 0)
            printf(", ");
        printf("%d", list->n);
        ++i;
        list = list->next;
    }
    printf("\n");
}
Big O Notation
The project provides a list of big O notations in various forms:

O(1)
O(n)
O(n!)
n square -> O(n^2)
log(n) -> O(log(n))
n * log(n) -> O(nlog(n))
n + k -> O(n+k)
...
Use the short notation (don't use constants). Example: O(nk) or O(wn) should be written O(n). If an answer is required within a file, all your answers files must have a newline at the end.

Tests
A quick tip to help you test your sorting algorithms with big sets of random integers is provided: Random.org.

Quiz Questions
The project includes a quiz to test your understanding.

Tasks
0. Bubble sort (mandatory)
Write a function that sorts an array of integers in ascending order using the Bubble sort algorithm.

Prototype: void bubble_sort(int *array, size_t size);

Print the array after each time you swap two elements.

Write in the file 0-O the big O notations of the time complexity of the Bubble sort algorithm, with 1 notation per line:

in the best case
in the average case
in the worst case
Example:

c
Copy code
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    bubble_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
1. Insertion sort (mandatory)
Write a function that sorts a doubly linked list of integers in ascending order using the Insertion sort algorithm.

Prototype: void insertion_sort_list(listint_t **list);

You are not allowed to modify the integer n of a node. You have to swap the nodes themselves.

Print the list after each time you swap two elements.

Write in the file 1-O the big O notations of the time complexity of the Insertion sort algorithm, with 1 notation per line:

in the best case
in the average case
in the worst case
Example:

c
Copy code
int main(void)
{
    listint_t *list;
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    list = create_listint(array, n);
    if (!list)
        return (1);
    print_list(list);
    printf("\n");
    insertion_sort_list(&list);
    printf("\n");
    print_list(list);

