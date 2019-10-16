/**
 * A example priority queue using a heap.
 * By Flynn Harrison
 */

#include <stdio.h>
#include <stdlib.h>

#include "PriorityQueue.h"

int main(int argc, char **argv){
    printf("hello world\n");

    heap_t firstHeap;
    firstHeap.heapArray = malloc(64*sizeof(heapNode_t));
    firstHeap.size = 64;
    firstHeap.index = 0;
    
    insert(&firstHeap, 3, 3);
    insert(&firstHeap, 5, 5);
    insert(&firstHeap, 15, 15);
    insert(&firstHeap, 2, 2);
    insert(&firstHeap, 9, 9);
    insert(&firstHeap, 7, 7);
    insert(&firstHeap, 8, 8);

    // Print the heap 
    printQueue(&firstHeap);
    
    // pop it twice
    extractMin(&firstHeap);
    printQueue(&firstHeap);

    printf("second pop: %d\n", extractMin(&firstHeap).priority);
    printf("third pop: %d\n", extractMin(&firstHeap).priority);
    printf("fourth pop: %d\n", extractMin(&firstHeap).priority);
    printf("fith pop: %d\n", extractMin(&firstHeap).priority);
    printf("sixth pop: %d\n", extractMin(&firstHeap).priority);
    printf("seventh pop: %d\n", extractMin(&firstHeap).priority);
    printf("eighth pop: %d\n", extractMin(&firstHeap).priority);

    freeQueue(&firstHeap);
}