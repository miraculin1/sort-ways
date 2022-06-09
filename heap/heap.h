#ifndef HEAP_H
#define HEAP_H
#include <stdlib.h>
#include <stdbool.h>

struct heap {
  int *h;
  int tail;
  int max;
};
typedef struct heap *heapPtr;

heapPtr initHeap(int size);
void cleaner(heapPtr heap);

heapPtr buildHeapN(int *in, int size);
heapPtr buildHeapNlogN(int *in, int size);
void insert(int in, heapPtr heap);
bool popMin(heapPtr heap, int *res);

int *heapSort(int *data, int size);
#endif
