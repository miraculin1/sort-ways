#include "heap.h"
#include <stdio.h>

int main() {
  int data[9] = {1, 5, 2, 3, 4, 9, 6, 7, 8};
  int *res = heapSort(data, 9);
  for (int i = 0; i < 9; i++) {
    printf("%d ", res[i]);
  }
  free(res);
}
