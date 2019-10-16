#include "PriorityQueue.h"
#include <assert.h>
#include <stdio.h>

void heapify(heap_t * heap, int index);
void swap(heap_t * heap, int index_1, int index_2);
int minNode(heap_t * heap, int index_1, int index_2);

int parent(int index){return (index - 1) / 2;};

int leftChild(int index){return (index*2) + 1;};

int rightChild(int index){return (index*2) + 2;};

heapNode_t getMin(heap_t * heap){
    // Check if the heap structure and the array exists 
    assert(heap);
    assert(heap->heapArray);
    
    return heap->heapArray[0];
}

heapNode_t extractMin(heap_t * heap){
    heapNode_t nodeBuff;

    // Node to be returned
    nodeBuff = getMin(heap);

    // Remove root and and place last node at root
    assert(heap->index <= heap->size);
    if (heap->index > 0){
        heap->index--;
        heap->heapArray[0] = heap->heapArray[heap->index];
    }

    // Reorder the heap `heapify`
    heapify(heap, 0);

    return nodeBuff;
}

int insert(heap_t * heap, int key, int data){
    int index;
    int upheapFlag = 1;

    // Double size of heap if not enough room
    if (heap->index == heap->size){
        heap->size *= 2;
        heap->heapArray = realloc(heap->heapArray, heap->size * sizeof(heapNode_t));
    }

    heap->heapArray[heap->index].data = data;
    heap->heapArray[heap->index].priority = key;
    
    // Upheap
    index = heap->index;
    while(upheapFlag){
        int p = parent(index);

        // If at root position or doesnt need to be upheaped
        if (index == 0 
            || heap->heapArray[p].priority <= heap->heapArray[index].priority){
            upheapFlag = 0;
            break;
        } else {
            swap(heap, p, index);
            index = p;
        }
    }

    heap->index++;
    return index;
}

void printQueue(heap_t * heap){
    int nextline = 0;
    for (int i = 0; i < heap->index; i++){
        printf("(%d %d)", heap->heapArray[i].priority, heap->heapArray[i].data);
        // Check if power of 2
        if (i == nextline){
            nextline = (i+1)*2;
            printf("\n");
        }
    }
    printf("\n");
    return;
}

void freeQueue(heap_t * heap){
    free(heap->heapArray);
    heap->index = 0;
    heap->size = 0;
    return;
}

/**
 * call to maintain heap properties from and bellow index
 */
void heapify(heap_t * heap, int index){
    assert(index < heap->size);
    int left, right, min;

    left = leftChild(index);
    right = rightChild(index);
    min = index;

    // Get the prioritys of its children
    if (left < heap->index 
        && heap->heapArray[left].priority < heap->heapArray[min].priority){
            min = left;
    }

    if (right < heap->index
        && heap->heapArray[right].priority < heap->heapArray[min].priority){
            min = right;
    }

    // Case for both larger than index
    if (min != index){
        swap(heap, min, index);
        heapify(heap, min);        
    }    

    return;
}

/**
 * Swaps the entrys at the two indexes
 */
void swap(heap_t * heap, int index_1, int index_2){
    // Check for possiable failers 
    assert(heap);
    assert(heap->heapArray);
    assert(heap->size > index_1 && heap->size > index_2);

    heapNode_t nodeBuffer;

    // Swap the two enterys with buffer
    nodeBuffer = heap->heapArray[index_1];
    heap->heapArray[index_1] = heap->heapArray[index_2];
    heap->heapArray[index_2] = nodeBuffer;
    return;
}

/**
 * Returns the index of the min node of index_1 and index_2
 */
int minNode(heap_t * heap, int index_1, int index_2){
    // Check for possiable failers 
    assert(heap);
    assert(heap->heapArray);
    assert(heap->size > index_1 && heap->size > index_2);

    // Determin who has a lower priority ## Change here for min->max heap ##
    if (heap->heapArray[index_1].priority <= heap->heapArray[index_2].priority){
        return index_1;
    } else {
        return index_2;
    }
    exit(EXIT_FAILURE);
}