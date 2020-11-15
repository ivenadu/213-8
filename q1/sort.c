#include <stdio.h>
#include <string.h>
#include "sort.h"

// TODO 7: Change this procedure sort generic arrays (i.e., arrays of any type)
//         by replacing char** with void* and adding function pointer parameters.
//         Update test_sort to use the new sort to sort
//             (a) this arrays of strings; AND
//             (b) an array of integers (this will help you with TODO 9)
//         See also TODO 8 in sort.h
void sort(
    void *list,
    int length,
    int (*compare)(void *datav, int a, int b),
    void (*swap)(void *datav, int a, int b))
{
    for (int i = 0; i < length; i++)
        for (int j = i + 1; j < length; j++)
            if (compare(list, i, j) > 0)
                swap(list, i, j);
}

int str_swap(char *list[], int i, int j)
{
    char *tmp = list[i];
    list[i] = list[j];
    list[j] = tmp;
}

int str_compare(char *list[], int i, int j)
{
    return strcmp(list[i], list[j]);
}

int int_swap(int *list, int i, int j)
{
    int tmp = list[i];
    list[i] = list[j];
    list[j] = tmp;
}

int int_compare(int *list, int i, int j)
{
    return list[i] - list[j];
}
void test_sort()
{
    {
        char *list[] = {"Cat", "Elephant", "Dog", "Lion", "Zebra", "Ape"};
        sort(list, 6, str_compare, str_swap);
        for (int i = 0; i < 6; i++)
            printf("%s\n", list[i]);
    }

    {
        int list[] = {100, 2, 1, 20, -3, 88 };
        sort(list, 6, int_compare, int_swap);
        for (int i = 0; i < 6; i++)
            printf("%d\n", list[i]);
    }
}