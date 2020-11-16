#include <stdlib.h>
#include <stdio.h>
#include "foreach.h"
#include "integer_list.h"
#include "integer_tree.h"
#include "sort.h"

/**
 * CPSC 213 Assignment 8, Question 1 Test Harness
 */

void print(void* ipv) {
    int* ip = ipv;
    printf("%d\n", *ip);
}

int sm, mn, mx;

void my_callback(void* element)
{
    print(element);
}

void my_callback_1(void* element)
{
    int i = *(int*)element;
    sm += i;
    if(i < mn) mn = i;
    if(i > mx) mx = i;
}

void test_integer_tree(int* vals, int n) {
    printf("Tree:\n");
    struct it_tree* it = it_new();
    for (int i = 0; i < n; i++)
        it_add(it, vals [i]);

    printf("Order List of Values:\n");
    foreach(it, it_iterator, it_has_next ,it_get_next, it_delete_iterator, my_callback);

    sm = 0, mn = 99999999, mx = -1;
    foreach(it, it_iterator, it_has_next ,it_get_next, it_delete_iterator, my_callback_1);
    printf ("Stats: sum %d min %d max %d\n", sm, mn, mx);

    it_delete(it);
}

void test_integer_list(int* vals, int n) {
    printf("Integer List\n");
    struct il_list* il = il_new(n);
    for (int i = 0; i < n; i++)
        il_add(il, vals [i]);

    printf("Unordered List of Values:\n");
    foreach(il, il_iterator, il_has_next ,il_get_next, il_delete_iterator, my_callback);

    //test_sort();

    printf("Ordered List of Values:\n");
    il_sort(il);
    foreach(il, il_iterator, il_has_next ,il_get_next, il_delete_iterator, my_callback);


    sm = 0, mn = 99999999, mx = -1;
    foreach(il, il_iterator, il_has_next ,il_get_next, il_delete_iterator, my_callback_1);
    printf ("Stats: sum %d min %d max %d\n", sm, mn, mx);

    il_delete(il);
}


int main(int argc, char** argv) {
    int n = argc - 1;
    int vals[n];
    for (int i=1; i<n + 1; i++)
        vals[i-1] = atoi(argv[i]);
    test_integer_tree(vals, n);
    test_integer_list(vals, n);
}