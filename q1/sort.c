#include <stdio.h>
#include <string.h>
#include "sort.h"

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

void str_swap(void *datav, int i, int j)
{
    char ** list = (char**)datav; 
    char *tmp = list[i];
    list[i] = list[j];
    list[j] = tmp;
}

int str_compare(void *datav, int i, int j)
{
    char ** list = (char**)datav; 
    return strcmp(list[i], list[j]);
}

void int_swap(void *datav, int i, int j)
{
    int * list = (int*)datav;
    int tmp = list[i];
    list[i] = list[j];
    list[j] = tmp;
}

int IntegerNode_compare(void *datav, int i, int j)
{
    int * list = (int*)datav;
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
        sort(list, 6, IntegerNode_compare, int_swap);
        for (int i = 0; i < 6; i++)
            printf("%d\n", list[i]);
    }
}