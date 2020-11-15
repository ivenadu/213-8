#include <stdlib.h>
#include <stdio.h>
#include "integer_list.h"
#include "sort.h"


/*** Types ***/

struct il_list {
    int size;
    int i; 
    int * buf; // int[size]
};

struct il_iterator {
    struct il_list* list;
    int pos;
};



/*** Private procedures ***/


/**
 * Compare data[a] and data[b], return -1 if data[a] is smaller, 1 if it is larger, and 0 if they are equal
 */

static int compare(void* datav, int a, int b) {
    // TODO 8
    struct il_list* list = (struct il_list*)datav;
    return list->buf[a] - list->buf[b];
}


/**
 * Swap data[a] and data[b]
 */

static void swap(void* datav, int a, int b) {
    // TODO 8
    struct il_list* list = (struct il_list*)datav;
    int tmp = list->buf[a];
    list->buf[a] = list->buf[b];
    list->buf[b] = tmp;
}



/*** Public procedures for Integer List ***/


/**
 * Create and initialize a new list
 */

struct il_list* il_new(int size) {
    // TODO 4
    void * buf = malloc(sizeof(int)*size);
    struct il_list* p = (struct il_list*)malloc(sizeof(struct il_list));
    p->buf = buf;
    p->size = size;
    p->i = 0;
    return p;
}


/**
 * Delete list
 */

void il_delete(struct il_list* list) {
    // TODO 4
    free(list->buf);
    free(list);
}


/**
 * Add value to end of list
 */

void il_add(struct il_list* list, int value) {
    // TODO 4
    if(list->i >= list->size){
        printf("list full!\n");
        exit(-1);
    }
    list->buf[list->i++] = value;
}


/**
 * Sort list in ascending order by value
 */

void il_sort(struct il_list* list) {
    sort(list, list->i, compare, swap);
}



/*** Public procedures for Integer List Iterator ***/


/**
 * Create and initialize iterator for list
 */

void* il_iterator(void* listv) {
    // TODO 5
    struct il_iterator* it = malloc(sizeof(struct il_iterator));
    it->list = listv;
    it->pos = 0;
    return it;
}


/**
 * Return TRUE iff iterator has more values to produce
 */

int il_has_next(void* iteratorv) {
    struct il_list* list = ((struct il_iterator*)iteratorv)->list;
    return ((struct il_iterator*)iteratorv)->pos < list->i;
}


/**
 * Get pointer to next value in iteration and advance interator's cursor
 */

void* il_get_next(void* iteratorv) {
    // TODO 5
    struct il_list* list = ((struct il_iterator*)iteratorv)->list;
    return &list->buf[((struct il_iterator*)iteratorv)->pos++];
}


/**
 * Delete iterator
 */
void il_delete_iterator(void* iterator) {
    free(iterator);
}