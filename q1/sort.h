#pragma once

// TODO 7: Add declaration of generic sort procedure by uncommenting next line and replacing ... with appropriate parameter(s)
void sort (
    void* list, 
    int length,
    int  (*compare)        (void* datav, int a, int b),
    void  (*swap)        (void* datav, int a, int b)
);

void test_sort();
