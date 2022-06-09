#include "heap.h"
inline static int left(int in) { return in * 2 + 1; }
inline static int right(int in) { return in * 2 + 2; }
inline static int parent(int in) { return (in - 1) < 0 ? -1 : (in - 1) / 2; }

static void buildFunc(heapPtr heap, int pos);

// 返回值：如果 root 左右分支都不存在将会返回一个超限的值，
// 如果存在至少一个分支，那么返回储存值较小的那个
static int branchMin(heapPtr heap, int root);

static void Down(heapPtr heap, int pos); // 以 pos 为起点下滤
static void Up(heapPtr heap);            // 上滤最后一个（新的）元素


// 初始化一个 size 大小的堆
heapPtr initHeap(int size) {
  heapPtr out = malloc(sizeof(struct heap));
  out->h = malloc(sizeof(int) * size);
  out->max = size - 1;
  out->tail = 0;
  return out;
}

void cleaner(heapPtr heap) {
  free(heap->h);
  free(heap);
}

// 将 in 元素插入维持堆序
void insert(int in, heapPtr heap) {
  if (heap->tail > heap->max) {
    // full
    return;
  }

  heap->h[(heap->tail)++] = in;
  Up(heap);
}

bool popMin(heapPtr heap, int *res) {
  // !! some prob here
  if (!(heap->tail > 0)) {
    return false;
  }

  // swap
  *res = heap->h[0];
  heap->h[0] = heap->h[(heap->tail) - 1];
  heap->h[(heap->tail) - 1] = *res;
  (heap->tail)--;

  // Down
  Down(heap, 0);

  return true;
}

heapPtr buildHeapN(int *in, int size) {
  heapPtr heap = malloc(sizeof(struct heap));
  heap->h = malloc(sizeof(int) * size);
  for (int i = 0; i < size; i++) {
    heap->h[i] = in[i];
  }
  heap->max = size - 1;
  heap->tail = size;

  buildFunc(heap, 0);

  return heap;
}

heapPtr buildHeapNlogN(int *in, int size) {
  heapPtr heap = initHeap(size);
  for (int i = 0; i < size; i++) {
    insert(in[i], heap);
  }
  return heap;
}
int *heapSort(int *data, int size) {
  heapPtr heap = buildHeapN(data, size);
  int tmp;
  int *res = malloc(sizeof(int) * size);
  for (int i = 0; i < size; i++) {
    popMin(heap, &tmp);
    res[i] = tmp;
  }
  cleaner(heap);
  return res;
}

static int branchMin(heapPtr heap, int root) {
  int l = left(root), r = right(root);
  if (l > heap->tail - 1) {
    return l;
  } else if (r > heap->tail - 1) {
    return l;
  } else {
    return heap->h[l] < heap->h[r] ? l : r;
  }
}

static void Down(heapPtr heap, int pos) {
  int now = pos;
  int val = heap->h[now];
  int next = branchMin(heap, now);

  while (next < heap->tail && val > heap->h[next]) {
    heap->h[now] = heap->h[next];

    now = next;
    next = branchMin(heap, now);
  }
  heap->h[now] = val;
}

static void Up(heapPtr heap) {
  int now = heap->tail - 1;
  int val = heap->h[now];
  int p = parent(now);

  while (p >= 0 && val < heap->h[p]) {
    heap->h[now] = heap->h[p];
    // upd now
    now = p;
    p = parent(now);
  }

  heap->h[now] = val;
}

static void buildFunc(heapPtr heap, int pos) {
  if (right(right(pos)) > heap->max) {
    Down(heap, pos);
    return;
  }
  buildFunc(heap, left(pos));
  buildFunc(heap, right(pos));
  Down(heap, pos);
}
