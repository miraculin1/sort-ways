#include "heap.h"
#include <stdio.h>

int main() {
  int data[4] = {5, 2, 3, 1};
  int *res = heapSort(data, 4);
  for (int i = 0; i < 4; i++) {
    printf("%d ", res[i]);
  }
  free(res);
}
