#include "foreach.h"

/**
 * Use iterator design pattern to iterate over collection.
 *   - iterator        (collection)  is called once at the begining of the iteration
 *   - delete_iterator (iterator)    is called once at the end of the iteration
 *   - has_next        (iterator)    is called on each iteration to determine whether it should continue
 *   - get_next        (iterator)    is called on each iteration to next next element and advance cursor
 *   - callback        (element)     is called on each iteration 
 */
void foreach(
    void* collection, 
    void* (*iterator)        (void* collection), 
    int   (*has_next)        (void* iterator), 
    void* (*get_next)        (void* iterator), 
    void  (*delete_iterator) (void* iterator),
    void  (*callback)        (void* element)
) {
    void* it = iterator(collection);
    while (has_next(it))
    {
        callback(get_next(it));
    }
    
    delete_iterator(it);
}