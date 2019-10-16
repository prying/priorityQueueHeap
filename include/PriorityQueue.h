#ifndef PriorityQueue
#define PriorityQueue

#include <stdlib.h>

#define DEFULT_HEAP_SIZE    64
#define NOT_NODE            0x10

typedef struct{
    int priority;
    int data;
}heapNode_t;

// The heap as a variable
typedef struct{
    // The array of heapNode_t's
    heapNode_t * heapArray;
    size_t size;
    // last entery in the heap
    size_t index;
}heap_t;


/**
 * Returns the index of parent of the node
 */
int parent(int index);

/**
 * Returns the index of left child of the node
 */
int leftChild(int index);

/**
 * Returns the index of right child of the node
 */
int rightChild(int index);

/**
 * Returns the root value of the min heap, the smallest value
 */
heapNode_t getMin(heap_t * heap);

/**
 * Removes min element form min heap, and returns is
 * (pops the root)
 */
heapNode_t extractMin(heap_t * heap);

/**
 * Inserts new element to the min heap.
 * Returns the position of the new node.
 */
int insert(heap_t * heap, int key, int data);

/**
 * Prints the Queue
 */
void printQueue(heap_t * heap);

/**
 * Deletes the node #NOT IMPLEMENTED#
 */
void deleteNode(int index);

/**
 * Frees the queue
 */
void freeQueue(heap_t * heap);

#endif

